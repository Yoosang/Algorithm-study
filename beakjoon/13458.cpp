#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector<int> A;

long long solution() {
	long long ret = 0;
	int temp = 0;	//부 감독관의 수
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ret++;
		if (A[i] <= 0) {
			continue;
		}
		temp = A[i] / C;
		if (A[i] % C == 0) {
			ret += temp;
		}
		else {
			ret += temp + 1;
		}
	}
	return ret;
}

int main() {
	int input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		A.push_back(input);
	}
	cin >> B >> C;
	cout << solution() << endl;
	return 0;
}