#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> userList;
	stringstream splitedRecord;
	string log[3];

	for (int i = 0; i < record.size(); i++) {
		splitedRecord.str(record[i]);
		for (int j = 0; j < 3; j++) {
			splitedRecord >> log[j];
		}

		if (log[0] == "Enter") {
			if (userList.count(log[1]) == 1) {
				userList[log[1]] = log[2];
			}
			else {
				userList.insert({ log[1], log[2] });
			}
		}
		else if (log[0] == "Leave") {
			userList.insert({ log[1], log[2] });
		}
		else {
			userList[log[1]] = log[2];
		}
		splitedRecord.clear();
	}

	for (int i = 0; i < record.size(); i++) {
		splitedRecord.str(record[i]);
		for (int j = 0; j < 3; j++) {
			splitedRecord >> log[j];
		}

		if (log[0] == "Enter") {
			answer.push_back(userList[log[1]] + "님이 들어왔습니다.");
		}
		else if (log[0] == "Leave") {
			answer.push_back(userList[log[1]] + "님이 나갔습니다.");
		}
		splitedRecord.clear();
	}
	return answer;
}
