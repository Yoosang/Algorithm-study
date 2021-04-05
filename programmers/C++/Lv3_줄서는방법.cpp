#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> number;
    long long mul = 1;
    int idx = 1;

    k -= 1;
    for(int i = 1; i <= n; i++){
        number.push_back(i);
        mul *= i;
    }

    while(n > 0){
        mul /= n;
        idx = (k / mul);
        answer.push_back(number[idx]);
        number.erase(number.begin() + idx);
        k %= mul;
        if(number.size() == 1){
            answer.push_back(number[0]);
            break;
        }
        n--;
    }

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }

    return answer;
}

int main(){
    vector<int> a = solution(4, 24);
    return 0;
}