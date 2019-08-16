#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 101
#define MAX_ANS 100

// 숫자와 숫자 개수를 포함한 구조체
struct Info {
	int number, cnt;
};

int r, c, k;
int answer = MAX_ANS;
vector<vector<int>> arr(MAX_SIZE, vector<int>(MAX_SIZE, 0));
vector<Info> tempForSort;
int usedNum[MAX_SIZE];

bool compare(Info a, Info b) {
	if (a.cnt == b.cnt) {
		return a.number < b.number;
	}
	return a.cnt < b.cnt;
}

void solution(int rowSize, int colSize, int depth) {
	if (depth > MAX_ANS) {
		answer = -1;
		return;
	}
	if (answer <= depth) {
		return;
	}
	if (arr[r - 1][c - 1] == k) {
		answer = depth;
		return;
	}

	// R 연산
	if (rowSize >= colSize) {
		int nextColSize = 0;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (arr[i][j] == 0) {
					continue;
				}
				usedNum[arr[i][j]]++;
				arr[i][j] = 0;
			}
			for (int j = 0; j < MAX_SIZE; j++) {
				if (usedNum[j] > 0) {
					tempForSort.push_back({ j,usedNum[j] });
					usedNum[j] = 0;
				}
			}
			nextColSize = max(nextColSize, (int)tempForSort.size() * 2);
			sort(tempForSort.begin(), tempForSort.end(), compare);

			int arrIdx = 0;
			int tempLength = ((int)tempForSort.size() > 50) ? 50 : (int)tempForSort.size();
			for (int j = 0; j < tempLength; j++) {
				arr[i][arrIdx] = tempForSort[j].number;
				arr[i][arrIdx + 1] = tempForSort[j].cnt;
				arrIdx += 2;
			}
			tempForSort.clear();
		}
		if (nextColSize > 100) {
			nextColSize = 100;
		}
		solution(rowSize, nextColSize, depth + 1);
	}

	// C 연산
	else {
		int nextRowSize = 0;
		for (int i = 0; i < colSize; i++) {
			for (int j = 0; j < rowSize; j++) {
				if (arr[j][i] == 0) {
					continue;
				}
				usedNum[arr[j][i]]++;
				arr[j][i] = 0;
			}
			for (int j = 0; j < MAX_SIZE; j++) {
				if (usedNum[j] > 0) {
					tempForSort.push_back({ j,usedNum[j] });
					usedNum[j] = 0;
				}
			}
			nextRowSize = max(nextRowSize, (int)tempForSort.size() * 2);
			sort(tempForSort.begin(), tempForSort.end(), compare);

			int arrIdx = 0;
			int tempLength = ((int)tempForSort.size() > 50) ? 50 : (int)tempForSort.size();
			for (int j = 0; j < tempLength; j++) {
				arr[arrIdx][i] = tempForSort[j].number;
				arr[arrIdx + 1][i] = tempForSort[j].cnt;
				arrIdx += 2;
			}
			tempForSort.clear();
		}
		if (nextRowSize > MAX_ANS) {
			nextRowSize = MAX_ANS;
		}
		solution(nextRowSize, colSize, depth + 1);
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	solution(3, 3, 0);
	cout << answer << endl;
	return 0;
}