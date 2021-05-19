#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int LOTTO_SIZE = 6;
int ranking[LOTTO_SIZE + 1] = {6, 6, 5, 4, 3, 2, 1}; 

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int same_cnt = 0;
    int zero_cnt = 0;

    for(int i = 0; i < LOTTO_SIZE; i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        for(int j = 0; j < LOTTO_SIZE; j++){
            if(lottos[i] == win_nums[j]){
                same_cnt++;
            }
        }
    }

    answer.push_back(ranking[zero_cnt + same_cnt]);
    answer.push_back(ranking[same_cnt]);

    return answer;
}