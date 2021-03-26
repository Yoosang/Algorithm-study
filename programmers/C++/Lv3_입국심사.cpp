#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long minTime, maxTime, midTime;
    sort(times.begin(), times.end());
    minTime = 1;
    maxTime = times.back() * n;
    answer = maxTime;

    while(minTime <= maxTime){
        long long sum = 0;
        midTime = (minTime + maxTime) / 2;
        for(int i = 0; i < times.size(); i++){
            sum += (midTime / times[i]);
        }

        if(sum < n){
            minTime = midTime + 1;
        }
        else{
            answer = (midTime <= answer) ? midTime : answer;
            maxTime = midTime - 1;
        }
    }

    return answer;
}
