#include <string>
#include <vector>
using namespace std;

int answer;
int numbers[8];

void run(int destNum, int cnt, int sum) {
	if ((answer != -1) && (cnt >= answer)) {
		return;
	}
	if (sum == destNum) {
		answer = cnt;
		return;
	}
	if (cnt > 8) {
		return;
	}

	for (int i = 0; i < 8; i++) {
		run(destNum, cnt + i + 1, sum + numbers[i]);
		run(destNum, cnt + i + 1, sum - numbers[i]);
		run(destNum, cnt + i + 1, sum * numbers[i]);
		run(destNum, cnt + i + 1, sum / numbers[i]);
	}
}

int solution(int N, int number) {
	answer = -1;
	int num = 0;
	for (int i = 0; i < 8; i++) {
		num = (num * 10) + N;
		numbers[i] = num;
	}
	run(number, 0, 0);
	return answer;
} 