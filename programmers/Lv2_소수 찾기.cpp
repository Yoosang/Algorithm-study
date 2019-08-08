#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
bool isUsed[8]; // 7자리 숫자 사용 확인
vector<int> check; // 중복 숫자 확인


bool findPrimeNumber(string num) {
	bool ret = true;
	int intNum = stoi(num);
	if (intNum < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(intNum); i++) {
		if (intNum % i == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

//같은 숫자 중복 확인
bool sameCheck(string num) {
	int intNum = stoi(num);
	for (vector<int>::size_type i = 0; i < check.size(); i++) {
		if (intNum == check[i]) {
			return false;
		}
	}
	check.push_back(intNum);
	return true;
}

void makeNumber(string number, int endIndex, string numList) {
	if (!number.empty()) {
		if (sameCheck(number)) {
			answer += findPrimeNumber(number);
		}
	}
	for (int i = 0; i < endIndex; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			makeNumber(number + numList[i], endIndex, numList);
			isUsed[i] = false;
		}
	}
}

int solution(string numbers) {
	makeNumber("", numbers.size(), numbers);
	return answer;
}