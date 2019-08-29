#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Info {
	int stageNum;
	double failPercent;
};

bool compare(Info a, Info b) {
	if (a.failPercent == b.failPercent) {
		return a.stageNum < b.stageNum;
	}
	return a.failPercent > b.failPercent;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<Info> stageInfo;
	vector<int> count(N + 2, 0);
	int sum = stages.size();
	
	for (auto i = 0; i < stages.size(); i++) {
		count[stages[i]]++;
	}

	for (auto i = 1; i < count.size() - 1; i++) {
		if (count[i] == 0) {
			stageInfo.push_back({ i, 0.0 });
		}
		else {
			stageInfo.push_back({ i, (double)count[i] / (double)sum });
		}
		sum -= count[i];
	}

	sort(stageInfo.begin(), stageInfo.end(), compare);

	for (auto i = 0; i < stageInfo.size(); i++) {
		answer.push_back(stageInfo[i].stageNum);
	}

	return answer;
}
