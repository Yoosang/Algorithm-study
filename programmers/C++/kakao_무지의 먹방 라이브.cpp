#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Food {
	int time, idx;
};

bool compareByTime(Food a, Food b) {
	return a.time < b.time;
}

bool compareByIdx(Food a, Food b) {
	return a.idx < b.idx;
}

int solution(vector<int> food_times, long long k) {
	int answer = -1;
	int foodNum = food_times.size();
	vector<Food> foodInfo;
	
	for (auto i = 0; i < food_times.size(); i++) {
		foodInfo.push_back({ food_times[i], i + 1 });
	}
	sort(foodInfo.begin(), foodInfo.end(), compareByTime);

	int rotateTime = 0;
	for (auto i = 0; i < foodInfo.size(); i++) {
		long long possibleRound = long long(foodInfo[i].time - rotateTime) * foodNum;
		if (k >= possibleRound) {
			k -= possibleRound;
			rotateTime = foodInfo[i].time;
		}
		else {
			int remainTime = k % foodNum;
			sort(foodInfo.begin() + i, foodInfo.end(), compareByIdx);
			answer = foodInfo[i + remainTime].idx;
			break;
		}
		foodNum--;
	}
	return answer;
}
