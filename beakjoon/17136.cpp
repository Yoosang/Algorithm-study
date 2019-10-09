#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 25
#define SIZE 10

int paper[SIZE + 1][SIZE + 1];
int cnt[5] = { 5, 5, 5, 5, 5 };
int answer = MAX;

bool isBoundary(int row, int col) {
	if (row >= MAX || col >= MAX) {
		return false;
	}
	return true;
}

void visitCheck(int row, int col, int length, int flag) {
	for (int i = 0; i <= length; i++) {
		for (int j = 0; j <= length; j++) {
			paper[row + i][col + j] = flag;
		}
	}
}

void solution(int row, int col, int paperNum) {
	if (paperNum >= answer) {
		return;
	}
	
	if (row == SIZE) {
		answer = min(paperNum, answer);
		return;
	}

	if (col == SIZE) {
		solution(row + 1, 0, paperNum);
		return;
	}

	if (paper[row][col] == 0) {
		solution(row, col + 1, paperNum);
		return;
	}

	for (int len = 4; len >= 0; len--) {
		if (!isBoundary(row + len, col + len)) {
			continue;
		}
		if (cnt[len] == 0) {
			continue;
		}

		bool impossible = false;

		for (int i = 0; i <= len; i++) {
			for (int j = 0; j <= len; j++) {
				if (paper[row + i][col + j] == 0) {
					impossible = true;
					break;
				}
			}
			if (impossible) {
				break;
			}
		}
		if (impossible) {
			continue;
		}

		cnt[len]--;
		visitCheck(row, col, len, 0);
		solution(row, col + 1, paperNum + 1);
		visitCheck(row, col, len, 1);
		cnt[len]++;
	}	
}

int main() {
	int numOfOne = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 1) {
				numOfOne++;
			}
		}
	}
	if (numOfOne == 0) {
		answer = 0;
	}
	else {
		solution(0, 0, 0);
	}
	
	if (answer == MAX) {
		answer = -1;
	}
	cout << answer << endl;
	return 0;
}