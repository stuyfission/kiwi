/*(kind-of) random composite number generator
	by Ryan Siu */

int x = rand() % 100; //generates random number from 0-100
int y = rand() % 100;
int answer;

bool check = true;

if (check == 1) {
	answer = x*y;
}

//below part is unnecessary but oh well

else {
	answer = x/y;
}