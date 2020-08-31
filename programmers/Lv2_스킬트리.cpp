#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int curIdx = 0;
    bool flag = true;

    for (string set : skill_trees) {
        curIdx = 0;
        flag = true;
        for (int i = 0; i < skill.length(); i++) {
            if (set.find(skill[i]) == string::npos || curIdx > set.find(skill[i])) {
                flag = false;
                break;
            }
            curIdx = set.find(skill[i]);
        }
        if (flag) {
            answer++;
        }
    }
    return answer;
}