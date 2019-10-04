#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 5001

int n, m, k;
int operation[7][4];
int answer = MAX;
vector<vector<int>> map;
vector<int> sequence;
bool checked[6];
//up, right, bottom, left
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void rotate() {
	int ret = 0;
	vector<vector<int>> rotatedMap(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rotatedMap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int seq = sequence[i];
		int front_row = operation[seq][0] - 1;
		int front_col = operation[seq][1] - 1;

		for (int offset = operation[seq][2]; offset >= 1; offset--) {
			int row = front_row - offset;
			int col = front_col - offset;
			cout << row << col << endl;
			int nextValue = rotatedMap[row][col];
			int temp = 0;
			int dir = 0;  // start from up

			do {
				int nr = row + dr[dir];
				int nc = col + dc[dir];
				temp = nextValue;
				nextValue = rotatedMap[nr][nc];
				rotatedMap[nr][nc] = temp;
				row = nr;
				col = nc;
				if (row == front_row - offset && col == front_col + offset) {
					dir = 1;
				}
				if (row == front_row + offset && col == front_col + offset) {
					dir = 2;
				}
				if (row == front_row + offset && col == front_col - offset) {
					dir = 3;
				}
			} while ((row != front_row - offset) || (col != front_col - offset));
		
		}
	}
	
	for (int i = 0; i < n; i++) {
		ret = 0;
		for (int j = 0; j < m; j++) {
			ret += rotatedMap[i][j];
		}
		answer = min(ret, answer);
	}
}

void makeSequence(int operNum) {
	if (operNum == k) {
		rotate();
		return;
	}
	for (int i = 0; i < k; i++) {
		if (!checked[i]) {
			checked[i] = true;
			sequence[operNum] = i;
			makeSequence(operNum + 1);
			sequence[operNum] = -1;
			checked[i] = false;

		}
	}
}

int main() {
	cin >> n >> m >> k;
	map.assign(n, vector<int>(m, 0));		
	sequence.assign(k, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> operation[i][j];
		}
	}
	makeSequence(0);
	cout << answer << endl;
	return 0;
}