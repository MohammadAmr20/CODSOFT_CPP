#include<iostream>
#include<string>
using namespace std;

int main() {
	int x, y;
	char op;
	cout << "Enter First Number :";
	cin >> x;
	cout << "\nEnter Second Number :";
	cin >> y;
	cout << '\n';
	cout << "Enter operation ( + , - , * , /): ";
	cin >> op;
	cout << '\n';
	switch (op) {
		case '+':
			cout << x << ' ' << op << ' ' << y << " = " << x + y << '\n';
			break;
		case '-':
			cout << x << ' ' << op << ' ' << y << " = " << x - y << '\n';
			break;
		case '*':
			cout << x << ' ' << op << ' ' << y << " = " << x * y << '\n';
			break;
		case '/':
			cout << x << ' ' << op << ' ' << y << " = " << ((y) ? to_string(1.0*x/y) : "Infinity") << '\n';
			break;
		default:
			cout << "Not a valid operation.\n";
			break;
	}
	return 0;
}