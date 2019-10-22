#include <iostream>
#include <vector>
using namespace std;

// row, col, speed, dir, size 
struct Shark {
	int r, c, s, d, z;
};

// up, down, right, left
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, 1, -1 };

int R, C, M;
int answer = 0;
vector<Shark> sharks;

void catchShark(int pos) {
	int minRow = R + 1;
	int catchIdx = -1;
	for (int i = 0; i < sharks.size(); i++) {
		if (sharks[i].c == pos) {
			if (minRow > sharks[i].r) {
				catchIdx = i;
				minRow = sharks[i].r;
			}
		}
	}
	if (catchIdx != -1) {
		answer += sharks[catchIdx].z;
		sharks[catchIdx] = { 0,0,0,0,0 };
	}
}

int changeDir(int dir) {
	if (dir == 1) {
		return 2;
	}
	if (dir == 4) {
		return 3;
	}
	if (dir == 2) {
		return 1;
	}
	return 4;
}

int reduceSpeed(int dir, int speed) {
	if ((dir == 1) || (dir == 2)) {
		speed %= (2 * (R - 1));
	}
	else {
		speed %= (2 * (C - 1));
	}
	return speed;
}

void moveShark() {
	int row, col, dir, speed;
	for (int i = 0; i < sharks.size(); i++) {
		if (sharks[i].r == 0) {
			continue;
		}
		row = sharks[i].r;
		col = sharks[i].c;
		dir = sharks[i].d;
		speed = reduceSpeed(dir, sharks[i].s);

		for (int j = 0; j < speed; j++) {
			row += dr[dir];
			col += dc[dir];
			if (row < 1 || col < 1 || row > R || col > C) {
				dir = changeDir(dir);
				for (int k = 0; k < 2; k++) {
					row += dr[dir];
					col += dc[dir];
				}
			}
		}
		sharks[i] = { row,col,sharks[i].s, dir, sharks[i].z };
	}
}

void setShark() {
	vector<vector<int>> temp(R + 1, vector<int>(C + 1, -1)); // for remove duplication, save index
	int row, col;
	for (int i = 0; i < sharks.size(); i++) {
		row = sharks[i].r;
		col = sharks[i].c;

		if (temp[row][col] == -1) {
			temp[row][col] = i;
		}
		else {
			if (sharks[temp[row][col]].z > sharks[i].z) {
				sharks[i] = { 0,0,0,0,0 };
			}
			else {
				sharks[temp[row][col]] = { 0,0,0,0,0 };
				temp[row][col] = i;
			}
		}
	}
}

void solution() {
	for (int move = 1; move <= C; move++) {
		if (sharks.empty()) {
			break;
		}
		catchShark(move);
		moveShark();
		setShark();
	}
}

int main() {
	int row, col, speed, dir, s_size;
	cin >> R >> C >> M;
	sharks.assign(M, { 0,0,0,0,0 });
	for (int i = 0; i < M; i++) {
		cin >> row >> col >> speed >> dir >> s_size;
		sharks[i] = { row, col, speed, dir, s_size };
	}
	solution();
	cout << answer << endl;
	return 0;
}