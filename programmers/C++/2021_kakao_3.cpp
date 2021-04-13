#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> infoList;

vector<string> split(string token, string str){
    vector<string> ret;
    int idx = 0;
    while(!str.empty() && idx > -1){
        idx = str.find(token);
        if(idx != 0){
            ret.push_back(str.substr(0, idx));
        }
        str.erase(0, idx + token.size());
    }
    return ret;
}

void replaceAll(string from, string to, string &str){
    int idx = 0;
    while(1){
        idx = str.find(from);
        if(idx < 0){
            break;
        }
        str.replace(idx, from.size(), to);
    }
}

bool compare (vector<string> a, vector<string> b){
     return stoi(a.back()) < stoi(b.back());
}

void setInfoList(vector<string> list){
    for(string str : list){
        infoList.push_back(split(" ", str));
    }
    sort(infoList.begin(), infoList.end(), compare);
}

int queryResult(string qu){
    int ret = 0;
    replaceAll(" and ", " ", qu);
    vector<string> splitedQuery = split(" ", qu);

    int frontIdx = 0;
    int endIdx = infoList.size() - 1;
    int midIdx = 0;
    bool find;

    while(frontIdx < endIdx){
        midIdx = (frontIdx + endIdx) / 2;
        if(stoi(infoList[midIdx].back()) < stoi(splitedQuery.back())){
            frontIdx = midIdx + 1;  
        }
        else{
            endIdx = midIdx;
        }
    }

    for(int i = endIdx; i < infoList.size(); i++){
        find = true;
        for(int j = 0; j < splitedQuery.size() - 1; j++){
            if(splitedQuery[j] == "-"){
                continue;
            }
            if(splitedQuery[j] != infoList[i][j]){
                find = false;
                break;
            }
        }
        if(find){
            ret++;
        }
    }
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    setInfoList(info);

    for(string qu : query){
        answer.push_back(queryResult(qu));
    }

    return answer;
}

// int main(){
//     vector<string> a = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
//     vector<string> b = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
//     solution(a, b);
//     return 0;
// } 