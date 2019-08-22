#include <iostream>
#include <vector>
using namespace std;

int n, k;

void solution() {
	vector<int> numbers;
	for (int i = 1; i <= n; i++) {
		numbers.push_back(i);
	}

	cout << "<";

	int idx = 0;
	while (!numbers.empty()) {
		idx += (k - 1);
		idx %= n;
		if (numbers.size() == 1) {
			cout << numbers[idx];
		}
		else {
			cout << numbers[idx] << ", ";
		}
		numbers.erase(numbers.begin() + idx);
		n--;
	}

	cout << ">";
}

int main() {
	cin >> n >> k;
	solution();
	return 0;
}