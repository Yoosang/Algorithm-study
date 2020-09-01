#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct DocInfo {
	int prior, idx;
};

int solution(vector<int> priorities, int location) {
	int answer = 1;
	queue<DocInfo> printList;

	for (unsigned i = 0; i < priorities.size(); i++) {
		printList.push({ priorities[i], (int)i });
	}

	sort(priorities.begin(), priorities.end());

	int max_idx = priorities.size() - 1;
	int max_val = priorities[max_idx];

	while (!printList.empty()) {
		if (printList.front().prior == max_val) {
			if (location == printList.front().idx) {
				break;
			}
			else {
				printList.push(printList.front());
				printList.pop();
				answer += 1;
				max_val = priorities[--max_idx];
			}
		}
		else {
			printList.push(printList.front());
			printList.pop();
		}
	}
	
	return answer;
}
