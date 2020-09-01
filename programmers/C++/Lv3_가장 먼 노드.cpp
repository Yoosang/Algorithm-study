#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int num, cnt;
};

vector<vector<int>> makeGraph(int number, vector<vector<int>> edges) {
	vector<vector<int>> ret;
	for (int i = 1; i <= number; i++) {
		vector<int> temp;
		for (int j = 0; j < edges.size(); j++) {
			if (i == edges[j][0]) {
				temp.push_back(edges[j][1] - 1);
			}
			else if (i == edges[j][1]) {
				temp.push_back(edges[j][0] - 1);
			}
		}
		ret.push_back(temp);
	}
	return ret;
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int maxCnt = 0;
	vector<bool> visited(n, false);
	queue<Node> q;
	vector<vector<int>> graph = makeGraph(n, edge);

	q.push({ 0,0 });
	visited[0] = true;

	while (!q.empty()) {
		int node = q.front().num;
		int count = q.front().cnt;
		q.pop();
		if (count == maxCnt) {
			answer++;
		}
		else {
			maxCnt = max(count, maxCnt);
			answer = 1;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			if (!visited[graph[node][i]]) {
				visited[graph[node][i]] = true;
				q.push({ graph[node][i] , count + 1 });
			}
		}
	}
	return answer;
}
