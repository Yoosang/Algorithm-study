#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> sortedScoville;

	for (vector<int>::size_type i = 0; i < scoville.size(); i++) {
		sortedScoville.push(scoville[i]);
	}

	int food1, food2, newFood;

	while (sortedScoville.top() < K && sortedScoville.size() >= 2) {
		food1 = sortedScoville.top();
		sortedScoville.pop();
		food2 = sortedScoville.top();
		sortedScoville.pop();
		newFood = food1 + (food2 * 2);
		sortedScoville.push(newFood);
		answer++;
	}

	if (sortedScoville.top() < K) {
		answer = -1;
	}

	return answer;
}