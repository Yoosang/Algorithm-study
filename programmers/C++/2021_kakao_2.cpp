#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

map<string, int> cnt[11];

/**
 * origin_str: 주문한 단품 메뉴의 조합, num: 추천 조합 메뉴의 개수, result_str: 현재까지 조합한 메뉴, next_idx: 다음 인덱스
 */
void combination(string origin_str, int num, string result_str, int next_idx){
    if(num == result_str.size()){
        if(cnt[num].find(result_str) != cnt[num].end()){
            cnt[num][result_str] ++;
        }else{
            cnt[num].insert(make_pair(result_str, 1));
        }
        return;
    }
    for(int i = next_idx; i < origin_str.size(); i++){
        combination(origin_str, num, result_str + origin_str[i], i + 1);
    }
}

bool compare(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<pair<string, int>> temp;

    for(string order : orders){
        sort(order.begin(), order.end());
        for(int numberOfWords : course){
            combination(order, numberOfWords, "", 0);

        }
    }

    for(int num : course){
        temp.assign(cnt[num].begin(), cnt[num].end());
        sort(temp.begin(), temp.end(), compare);
        
        for(int i = 0; i < temp.size() - 1; i++){
            if(temp[0].second < 2){
                break;
            }  
            answer.push_back(temp[i].first);
            if(temp[i].second != temp[i+1].second){
                break;
            }
        }
        temp.clear();
    }
    sort(answer.begin(), answer.end());

    return answer;
}