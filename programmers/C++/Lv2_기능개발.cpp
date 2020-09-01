#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    unsigned end_count = progresses.size();
    int temp = 0;
    while (end_count) {
        for (unsigned i = 0; i < progresses.size(); i++) {
            if (progresses[i] == -1) {
                continue;
            }
            progresses[i] += speeds[i];
        }
        for (unsigned i = 0; i < progresses.size(); i++) {
            if (progresses[i] < 0) {
                continue;
            }
            else if (progresses[i] >= 100) {
                temp++;
                progresses[i] = -1;
            }
            else {
                break;
            }
        }
        if (temp != 0) {
            end_count -= temp;
            answer.push_back(temp);
            temp = 0;
        }
    }

    return answer;
}

int main() {
    solution({ 93,30,55 }, { 1,30,5 });
}