#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// up, down, right, left
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int R, C, T;
vector<pair<int, int>> machine;
vector<vector<int>> map;

vector<vector<int>> spread() {
	vector<vector<int>> ret(R + 1, vector<int>(C + 1, 0));
	int cnt, nr, nc;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				cnt = 0;
				for (int k = 0; k < 4; k++) {
					nr = i + dr[k];
					nc = j + dc[k];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C) {
						continue;
					}
					if (map[nr][nc] == -1) {
						continue;
					}
					ret[nr][nc] += (map[i][j] / 5);
					cnt++;
				}
				ret[i][j] += (map[i][j] - ((map[i][j] / 5) * cnt));
			}
		}
	}
	return ret;
}

// move == 0 : up, move == 1 down
void run(int move) {
	int row = machine[move].first;
	int col = machine[move].second;
	int dir = 2;
	int nr = row + dr[dir];
	int nc = col + dc[dir];
	int temp = map[nr][nc];
	int nextValue = 0;

	while (1) {
		if (nr == row && nc == col) {
			break;
		}
		temp = map[nr][nc];
		map[nr][nc] = nextValue;
		nextValue = temp;

		if (nr == row && nc == C - 1) {
			dir = move;
		}
		else if (((nr == 0) || (nr == R - 1)) && nc == C - 1) {
			dir = 3;
		}
		else if ((nr == 0 || nr == R - 1) && nc == 0) {
			dir = !move;
		}
		
		nr += dr[dir];
		nc += dc[dir];
	}
	map[row][col] = -1;
}

int dustSum() {
	int ret = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				ret += map[i][j];
			}
		}
	}
	return ret;
}

void print() {
	cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}

void solution() {
	while (T--) {
		map = spread();
		for (int move = 0; move < 2; move++) {
			run(move);
		}
	}
	cout << dustSum() << endl;
}

int main() {
	cin >> R >> C >> T;
	map.assign(R + 1, vector<int>(C + 1, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				machine.push_back({ i,j });
			}
		}
	}
	solution();
	return 0;
}