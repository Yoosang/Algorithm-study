#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> special_char_list = {'-' , '.', '_'};
static int max_length = 16;

bool isPossibleChar(char str){
    for(char ch : special_char_list){
        if(ch == str){
            return true;
        }
    }
    return false;
}

string step1(string str){
    string ret = str;
    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

string step2(string str){
    string ret = "";
    for(int i = 0; i < str.size(); i++){
        if(isalpha(str[i]) || isdigit(str[i]) || isPossibleChar(str[i])){
            ret += str[i];
        }
    }
    return ret;   
}

string step3(string str){
    string ret = str;
    int idx = 1;
    while(idx < ret.size()){
        if(ret[idx] == '.' && ret[idx-1] == '.'){
            ret.erase(ret.begin() + idx);
            continue;
        }
        idx++;
    }
    return ret;
}

string step4(string str){
    string ret = str;
    if(ret[0] == '.'){
        ret.erase(ret.begin());
    }
    if(ret[ret.size() - 1] == '.'){
        ret.erase(ret.end() - 1);
    }
    return ret;
}

string step5(string str){
    string ret = "a";
    if(str == ""){
        return ret;
    }
    return str;
}

string step6(string str){
    string ret = str;
    if(ret.size() >= max_length){
        ret = ret.substr(0, max_length - 1);
        ret = step4(ret);
    }
    return ret;
}

string step7(string str){
    string ret = str;
    if(ret.size() <= 2){
        while(ret.size() < 3){
            ret += str[str.size() - 1];
        }
    }
    return ret;
}

string solution(string new_id) {
    string answer = "";
    answer = step1(new_id);
    answer = step2(answer);
    answer = step3(answer);
    answer = step4(answer);
    answer = step5(answer);
    answer = step6(answer);
    answer = step7(answer);
    return answer;
}
