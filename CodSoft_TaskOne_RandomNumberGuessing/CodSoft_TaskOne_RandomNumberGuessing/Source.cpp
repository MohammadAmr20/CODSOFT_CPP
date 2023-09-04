#include<iostream>
#include<random>
using namespace std;

int returnRandomNumber(int max) {
	random_device rd;
	uniform_int_distribution<int> dist(1, max);
	return dist(rd);
}

int main() {
	int x,max;
	cout << "Enter Maximum Value for guessing: ";
	cin >> max;
	cout << '\n';
	int guess = returnRandomNumber(max);
	cout << "Enter a guess: ";
	cin >> x;
	cout << '\n';
	while (x != guess) {
		if (x > guess)
			cout << "Your Guess is greater than our value.\n\n";
		else
			cout << "Your Guess is less than our value.\n\n";
		cout << "Enter another guess:";
		cin >> x;
	}
	cout << "Congrats, You guessed it.\n";
	return 0;
}