#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>
using namespace std;

#define MAX_SIZE 51

struct Pos {
	int row, col;
};

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int N, L, R;
int answer = 0;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

bool isUnited(int row, int col) {
	int numOfNation = 0;
	int population = 0;
	int r, c, nr, nc, gap;
	bool unite[MAX_SIZE][MAX_SIZE] = { false, };
	queue<Pos> q;
	
	visited[row][col] = true;
	q.push({ row, col });
	while (!q.empty()) {
		r = q.front().row;
		c = q.front().col;
		q.pop();
		numOfNation++;
		population += map[r][c];
		unite[r][c] = true;
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
				continue;
			}
			if (visited[nr][nc]) {
				continue;
			}
			gap = abs(map[r][c] - map[nr][nc]);
			if (gap >= L && gap <= R) {
				visited[nr][nc] = true;
				q.push({ nr, nc });
			}
		}
	}
	if (numOfNation == 1) {
		return false;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (unite[i][j]) {
				map[i][j] = population / numOfNation;
			}
		}
	}

	return true;
}

void solution() {
	int count;
	while (1) {
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					if (isUnited(i, j)) {
						count++;
					}
				}
			}
		}
		if (count == 0) {
			break;
		}
		answer ++;
		memset(visited, false, sizeof(visited));
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solution();
	cout << answer << endl;
	return 0;
}