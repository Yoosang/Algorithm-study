#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAP_SIZE 10
#define ISLAND_NUM 6

struct Pos {
	int row, col;
};

struct Bridge {
	int startPoint, endPoint, length;
};

int n, m;
int answer = 0;
int map[MAP_SIZE + 1][MAP_SIZE + 1];
int islandSet[ISLAND_NUM + 1];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
vector<Bridge> bridges;

bool isOut(int row, int col) {
	if (row < 0 || col < 0 || row >= n || col >= m) {
		return true;
	}
	return false;
}

void makeIsland(Pos pos, int num) {
	queue<Pos> q;
	q.push(pos);
	map[pos.row][pos.col] = num;

	while (!q.empty()) {
		int r = q.front().row;
		int c = q.front().col;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (isOut(nr, nc)) {
				continue;
			}
			if (map[nr][nc] != -1) {
				continue;
			}
			map[nr][nc] = num;
			q.push({ nr,nc });
		}
	}
}

int numbering() {
	int number = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) {
				number++;
				makeIsland({ i,j }, number);
			}
		}
	}
	return number;
}

void addBridge(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (map[nr][nc] > 0) {
			continue;
		}
		while (map[nr][nc] == 0 && !isOut(nr, nc)) {
			cnt++;
			nr += dr[i];
			nc += dc[i];
		}
		if (!isOut(nr, nc) && cnt > 1) {
			bridges.push_back({ map[row][col], map[nr][nc], cnt });
		}
	}
}

void setBridge() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) {
				addBridge(i, j);
			}
		}
	}
}

bool compare(Bridge a, Bridge b) {
	return a.length < b.length;
}

int getParent(int bridge) {
	if (islandSet[bridge] == bridge) {
		return bridge;
	}
	return getParent(islandSet[bridge]);
}

bool isSameParent(int bridge1, int bridge2) {
	int bridge1_parent = getParent(bridge1);
	int bridge2_parent = getParent(bridge2);
	if (bridge1_parent == bridge2_parent) {
		return true;
	}
	return false;
}

void unionParent(int bridge1, int bridge2) {
	int bridge1_parent = getParent(bridge1);
	int bridge2_parent = getParent(bridge2);
	if (bridge1_parent < bridge2_parent) {
		islandSet[bridge2_parent] = bridge1_parent;
	}
	else {
		islandSet[bridge1_parent] = bridge2_parent;
	}
}

// Kruscal algorithm
void findMin(int islandIdx) {
	int numOfbridges = 0;
	for (int i = 1; i <= islandIdx; i++) {
		islandSet[i] = i;
	}
	sort(bridges.begin(), bridges.end(), compare);
	for (auto bridge : bridges) {
		if (!isSameParent(bridge.startPoint, bridge.endPoint)) {
			answer += bridge.length;
			unionParent(bridge.startPoint, bridge.endPoint);
		}
	}
	for (int i = 2; i <= islandIdx; i++) {
		if (islandSet[i] == i) {
			answer = -1;
			break;
		}
	}
}

void solution() {
	int numOfIsland = numbering();
	setBridge();
	findMin(numOfIsland);
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}
}

int main() {
	input();
	solution();
	cout << answer << endl;
	return 0;
}