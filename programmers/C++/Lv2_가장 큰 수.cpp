#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	return a + b > b + a ? true : false;
}

vector<string> convertIntToString(vector<int> num) {
	vector<string> ret;
	for (vector<int>::size_type i = 0; i < num.size(); i++) {
		ret.push_back(to_string(num[i]));
	}
	return ret;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> stringNumber = convertIntToString(numbers);

	sort(stringNumber.begin(), stringNumber.end(), compare);

	if (stringNumber[0] == "0") {
		return "0";
	}

	for (vector<string>::size_type i = 0; i < stringNumber.size(); i++) {
		answer += stringNumber[i];
	}

	return answer;
}
