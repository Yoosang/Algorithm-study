#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> temp;

void dfs(string departure, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer) {
	answer.push_back(departure);
	if (answer.size() == tickets.size() + 1) {
		temp.push_back(answer);
	}
	for (int i = 0; i < tickets.size(); i++) {
		if ((tickets[i][0] == departure) && !visited[i]) {
			visited[i] = true;
			dfs(tickets[i][1], tickets, visited, answer);
			visited[i] = false;
		}
	}
	answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> visited(tickets.size(), false);
	dfs("ICN", tickets, visited, answer);
	sort(temp.begin(), temp.end());
	answer = temp[0];
	return answer;
}