#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;
char grid[3][3];
void resetGrid() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = '.';
}

bool isThereAWinner() {
	char c;
	//Row Checker
	for (int i = 0; i < 3; i++) {
		bool win = true;
		c = grid[i][0];
		if (c == '.')
			continue;
		for (int j = 1; j < 3; j++) {
			win &= (grid[i][j] == c);
		}
		if (win)
			return true;
	}
	//Column Checker
	for (int j = 0; j < 3; j++) {
		bool win = true;
		c = grid[0][j];
		if (c == '.')
			continue;
		for (int i = 1; i < 3; i++) {
			win &= (grid[i][j] == c);
		}
		if (win)
			return true;
	}
	if (grid[1][1] != '.' && ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])))
		return true;
	return false;
}

void drawGrid(bool xTurn,bool win,bool full) {
	cout << '\n';
	if (win) {
		cout << ((xTurn) ? "Player X" : "Player O") << " Won.\n";
	}
	else {
		cout << ((full) ? "Draw.\n" : "On-Going.\n");
	}
	for (int i = 0; i < 3; i++) {
		cout << "\t\t";
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == '.')
				cout << ' ';
			else
				cout << grid[i][j];
			if (j < 2)
				cout << " | ";
		}
		if (i < 2)
			cout << "\n\t\t----------\n";
	}
	cout << '\n';
}

bool isGridFull() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i][j] == '.')
				return false;
	return true;
}

bool isValidPosition(int position) {
	int i = position / 3, j = position % 3;
	return (position >= 0 && position < 9 && grid[i][j] == '.');
}

void startGame() {
	bool xTurn = true;
	bool win = false;
	int position;
	while (true) {
		cout << "\nEnter game position for player " << ((xTurn) ? "X(zero-based): " : "O(zero-based): ");
		cin >> position;
		while (!isValidPosition(position)) {
			cout << "Enter valid Position:";
			cin >> position;
		}
		int i = position / 3, j = position % 3;
		grid[i][j] = (xTurn) ? 'X' : 'O';
		win = isThereAWinner();
		drawGrid(xTurn, win, isGridFull());
		if (win || isGridFull())
			break;
		xTurn = !xTurn;
	}
}

int main() {
	char choice;
	do {
		system("cls");
		cout << '\n';
		resetGrid();
		startGame();
		cout << "\nDo you want to continue: ";
		cin >> choice;
	} while (choice == 'y');
	return 0;
}