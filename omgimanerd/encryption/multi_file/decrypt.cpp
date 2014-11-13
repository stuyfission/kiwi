/*
 * File:   decrypt.cpp
 * Author: Alvin Lin (alvin.lin@stuypulse.com)
 * Multiple file decryption.
 * This script is paired with the multi-file encryption algorithm.
 * A text file named file.txt must exist in order for this to work.
 * file.txt must contain all the names of the files to decrypt.
 * Created on July 23, 2013, 7:05 PM
 */
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Given an encoded string, a vector containing the decryption key,
// and a counter to keep track of the index, this function returns
// the decrypted version of the encoded string.
string decode(string entryline,
              vector<int> vigenere_keyvector,
              int &charCounter) {
  string decodedline;
  int keydigits = vigenere_keyvector.size();
  // Start vigenere form.
  // Greater than 256 is automatically handled.
  for (int i = 0; i < entryline.length(); i++) {
    decodedline.append(1, (char)((int)entryline.at(i) -
        vigenere_keyvector[charCounter % keydigits]));
    charCounter++;
    if (charCounter > keydigits) {charCounter %= keydigits;}
  }
  return decodedline;
}

// Isolates the key from the keystring since key is every other digit.
void keyfind(string keystring,
             vector<int> &vigenere_keyvector,
             int &keydigits) {
  // Loop appends every other character starting at 1 to remove encryption
  // label and get actual key.
  for (int i = 1; i < keystring.length(); i+=2) {
    vigenere_keyvector.push_back((int)keystring[i] - (int)'0');
  }
  // Can decode this cipher with any key length.
  keydigits = vigenere_keyvector.size();
}

int main(int argc, char** argv) {
  // First we must get the names of all the files to decrypt.
  ifstream file;
  file.open("file.txt");
  if (file.fail()) {
    cout << "Could not read file.txt." << endl;
    return 0;
  } else {
    cout << "file.txt found." << endl;
  }
  // Vector to store the names of all the files to decrypt.
  vector<string> filenames;
  // Temporary storage for getline.
  string stor;
  while (getline(file, stor)) {
    filenames.push_back(stor);
  }
  // Closes input file.
  file.close();

  for (int i = 0; i < filenames.size(); i++) {
    ifstream infile;
    ofstream outfile;
    infile.open(filenames[i].c_str());
    if (infile.fail()) {
      cout << filenames[i] << " does not exist." << endl;
      continue;
    }
    else {
      cout << filenames[i] << " found." << endl;
    }

    // Takes all lines in the file and stores it into a vector.
    // Necessary because output file overwrites input file.
    vector <string> filestorage;
    // Temporary storage for getline
    string stor;
    while (getline(infile, stor)) {
      filestorage.push_back(stor);
    }
    // Closes input file
    infile.close();

    // Opens output file to overwrite input file
    outfile.open(filenames[i].c_str());
    // Storage for whole keystring
    string keystring = filestorage[0];
    // Erases key from filestorage
    filestorage.erase(filestorage.begin());
    // Storage of the part of the key for vigenere ciphers
    vector<int> vigenere_keyvector;
    // Storage for the number of digits in the key
    int keydigits;
    // Character counter for vigenere cipher
    int charCounter = 0;
    // Decrypts dummy key and returns actual key in a vector
    keyfind(keystring, vigenere_keyvector, keydigits);

    // Only decrypts files if they are encrypted by matching
    // encryption algorithm. Denoted by P at the beginning of the keystring.
    if (keystring.at(0) == 'P') {
      // Gets, decodes, and outputs every line after the first line
      // Will leave a trailing newline
      for (int i = 0; i < filestorage.size(); i++) {
        outfile << decode(filestorage[i],
                          vigenere_keyvector,
                          charCounter) << endl;
      }
    }
    // If it is unable to read the keystring, or if the file is not encrypted
    // with this algorithm, then it will reoutput the file as is.
    else {
      outfile << "UNABLE TO DECODE, INVALID OR NONEXISTENT KEYSTRING" << endl;
      // Reoutputs the rest of the file as is
      while (getline(infile, stor)) {
        outfile << stor << endl;
      }
    }
    // Closes output file
    outfile.close();
  }

  cout << "Decryption completed. " << filenames.size() << " files encrypted";

  return 0;
}
