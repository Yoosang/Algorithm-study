#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	return a.size() < b.size();
}

/* 
처음 생각
1. 문자열 길이를 짧은 순으로 정렬함
2. 2중 for문을 사용하여 완전 탐색
*/
bool solution(vector<string> phone_book) {
	bool answer = true;
	string number;

	sort(phone_book.begin(), phone_book.end(), compare);

	for (vector<string>::size_type i = 0; i < phone_book.size() - 1; i++) {
		number = phone_book[i];
		for (unsigned j = i + 1; j < phone_book.size(); j++) {
			if (number == phone_book[j].substr(0, number.size())) {
				answer = false;
				break;
			}
		}
		if (!answer) {
			break;
		}
	}
	return answer;
}

/*
두번째 생각
1. 문자열을 문자 순서대로 정렬함
2. 첫번재 문자열과 다음 문자열만 비교해보면 됨 (for문 하나 사용)
*/
bool solution2(vector<string> phoneBook) {
	bool answer = true;

	sort(phoneBook.begin(), phoneBook.end());

	for (int i = 0; i < phoneBook.size() - 1; i++)
	{
		if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
		{
			answer = false;
			break;
		}
	}

	return answer;
}
