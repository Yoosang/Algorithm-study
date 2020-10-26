#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 101

// 0: right, 1: down, 2: left, 3: up
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int map[MAX_SIZE][MAX_SIZE];
int n;
vector<vector<int>> dragon;

vector<int> setSequence(int dir, int generation) {
	vector<int> ret;
	ret.push_back(dir);
	for (int i = 0; i < generation; i++) {
		for (int j = ret.size() - 1; j >= 0; j--) {
			ret.push_back((ret[j] + 1) % 4);
		}
	}
	return ret;
}

void dragonCurve(int pos) {
	int x = dragon[pos][0];
	int y = dragon[pos][1];
	int d = dragon[pos][2];
	int g = dragon[pos][3];
	vector<int> sequence = setSequence(d, g);
	map[y][x] = 1;
	for (int i = 0; i < sequence.size(); i++) {
		x += dx[sequence[i]];
		y += dy[sequence[i]];
		if (x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE) {
			continue;
		}
		map[y][x] = 1;
	}
}

bool isSquare(int row, int col) {
	if (map[row][col] != 1) {
		return false;
	}
	if (map[row + 1][col] != 1) {
		return false;
	}
	if (map[row][col + 1] != 1) {
		return false;
	}
	if (map[row + 1][col + 1] != 1) {
		return false;
	}
	return true;
}

int countSquare() {
	int ret = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (isSquare(i,j)) {
				ret++;
			}
		}
	}
	return ret;
}

void solution() {
	for (int i = 0; i < n; i++) {
		dragonCurve(i);
	}
	cout << countSquare() << endl;
}

int main() {
	cin >> n;
	dragon.assign(n, vector<int>(4, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> dragon[i][j];
		}
	}
	solution();
	return 0;
}