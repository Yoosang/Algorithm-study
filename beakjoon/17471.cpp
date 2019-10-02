#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define MAX 1000

int n;
int answer = MAX;
vector<int> population;
vector<int> team;
vector<vector<int>> map;

int count() {
	vector<bool> visited(n + 1, false);
	queue<int> q;
	int team_zero = 0;
	int team_one = 0;
	int node = 0;

	// bfs about team_zero
	for (int i = 1; i <= n; i++) {
		if (team[i] == 0) {
			q.push(i);
			visited[i] = true;
			break;
		}
	}

	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 1; i < map[node].size(); i++) {
			if (team[map[node][i]] == 0 && !visited[map[node][i]]) {
				q.push(map[node][i]);
				visited[map[node][i]] = true;
			}
		}
	}

	// bfs about team_one
	for (int i = 1; i <= n; i++) {
		if (team[i] == 1) {
			q.push(i);
			visited[i] = true;
			break;
		}
	}

	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 1; i < map[node].size(); i++) {
			if (team[map[node][i]] == 1 && !visited[map[node][i]]) {
				q.push(map[node][i]);
				visited[map[node][i]] = true;
			}
		}
	}

	// visit check and sum population
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			return MAX;
		}

		if (team[i] == 0) {
			team_zero += population[i];
		}
		else {
			team_one += population[i];
		}
	}
	return abs(team_one - team_zero);
}

void makeTeam(int idx) {
	if (idx == n) {
		return;
	}
	if (idx > 1) {
		answer = min(answer, count());
	}
	for (int i = idx; i <= n; i++) {
		team[i] = 1;
		makeTeam(i + 1);
		team[i] = 0;
	}
}

int main() {
	int input_cnt;
	cin >> n;
	population.assign(n + 1, 0);
	team.assign(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> population[i];
	}

	// empty vector for starting index 
	map.push_back(vector<int>(1, 0));
	
	for (int i = 1; i <= n; i++) {
		cin >> input_cnt;
		vector<int> temp(input_cnt + 1, 0);
		for (int j = 1; j <= input_cnt; j++) {
			cin >> temp[j];
		}
		map.push_back(temp);
	}
	
	makeTeam(1);

	if (answer == MAX) {
		cout << -1 << endl;
	}
	else {
		cout << answer << endl;
	}
	return 0;
}