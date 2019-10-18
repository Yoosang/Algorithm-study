#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 10

int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int N, M, K;
vector<int> trees[MAX_SIZE + 1][MAX_SIZE + 1];
int supply_nutrient[MAX_SIZE + 1][MAX_SIZE + 1];
int cur_nutrient[MAX_SIZE + 1][MAX_SIZE + 1];

void springSummer() {
	vector<int> temp;
	int deathValue;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (trees[i][j].empty()) {
				continue;
			}
			temp = trees[i][j];
			deathValue = 0;
			sort(temp.begin(), temp.end());

			for (int k = 0; k < temp.size(); k++) {
				if (cur_nutrient[i][j] < temp[k]) {
					deathValue += (temp[k] / 2);
					temp[k] = 0;
				}
				else {
					cur_nutrient[i][j] -= temp[k];
					temp[k]++;
				}
			}
			cur_nutrient[i][j] += deathValue;
			trees[i][j].clear();
			for (int k = 0; k < temp.size(); k++) {
				if (temp[k] != 0) {
					trees[i][j].push_back(temp[k]);
				}
			}
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (trees[i][j].empty()) {
				continue;
			}
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int nr = i + dr[l];
						int nc = j + dc[l];
						if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
							continue;
						}
						trees[nr][nc].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cur_nutrient[i][j] += supply_nutrient[i][j];
		}
	}
}

int numOfTree() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!trees[i][j].empty()) {
				ret += trees[i][j].size();
			}
		}
	}
	return ret;
}

void solution() {
	while (K--) {
		springSummer();
		fall();
		winter();
	}
	cout << numOfTree() << endl;
}

int main() {
	int x, y, z;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> supply_nutrient[i][j];
			cur_nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
	}
	solution();
	return 0;
}