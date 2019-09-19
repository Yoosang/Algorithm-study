#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	vector<long long> length;
	length.push_back(0);
	length.push_back(1);
	for (int i = 1; i <= N; i++) {
		length.push_back(length[i] + length[i - 1]);
	}
	answer = ((length[N] * 2)) + ((length[N] + length[N - 1]) * 2);
	return answer;
}