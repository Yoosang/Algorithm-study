#include <iostream>
#define MAX (1000000000)
#define MIN (-1000000000)
using namespace std;

int n, maxValue = MIN, minValue = MAX;
int oper[4];
int numbers[101];

void solution(int plus, int minus, int mul, int div, int index, int number) {
	if (index == n) {
		maxValue = (maxValue < number) ? number : maxValue;
		minValue = (minValue > number) ? number : minValue;
		return;
	}

	if (plus < oper[0]) {
		solution(plus + 1, minus, mul, div, index + 1, number + numbers[index]);
	}
	if (minus < oper[1]) {
		solution(plus, minus + 1, mul, div, index + 1, number - numbers[index]);
	}
	if (mul < oper[2]) {
		solution(plus, minus, mul + 1, div, index + 1, number * numbers[index]);
	}
	if (div < oper[3]) {
		solution(plus, minus, mul, div + 1, index + 1, number / numbers[index]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];

	}
	solution(0, 0, 0, 0, 1, numbers[0]);
	cout << maxValue << endl;
	cout << minValue << endl;
	return 0;
}