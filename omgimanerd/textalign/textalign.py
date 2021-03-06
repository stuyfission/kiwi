#!/usr/bin/python

def main():
  inputFile = open('text.txt')
  inputText = inputFile.read();

  inputText = inputText.split('\n')
  textList = []
  for i in inputText:
    textList += i.split(' ')

  while (textList.count("") != 0):
    textList.remove("")
  while (textList.count(" ") != 0):
    textList.remove(" ")

  outputText = ""
  charCounter = 0
  for i in textList:
    if charCounter + len(i) >= 80:
      outputText += "\n" + i + " ";
      charCounter = len(i) + 2
    else:
      outputText += i + " ";
      charCounter += len(i) + 1
  print outputText

if __name__ in '__main__':
  main()
