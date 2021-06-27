#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map ;

void initMap(int row, int col){
    int num = 1;

    map.assign(row, vector<int>(col, 0));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            map[i][j] = num;
            num++;
        }
    }
}

 vector<int> rotate(vector<int> position){

    vector<int> ret;
    
    int x1 = position[0] -1;
    int y1 = position[1] -1;
    int x2 = position[2] -1;
    int y2 = position[3] -1;

    int originVal = map[x1][y1];
    ret.push_back(originVal);

    //left
    for(int row = x1; row < x2; row++){
        map[row][y1] = map[row + 1][y1];
        ret.push_back(map[row][y1]);
    }
    //bottom
    for(int col = y1; col < y2; col++){
        map[x2][col] = map[x2][col+1];
        ret.push_back(map[x2][col]);
    }
    //right
    for(int row = x2; row > x1; row--){
        map[row][y2] = map[row - 1][y2];
        ret.push_back(map[row][y2]);
    }
    //top
    for(int col = y2; col > y1 + 1; col--){
        map[x1][col] = map[x1][col - 1];
        ret.push_back(map[x1][col]);
    }
    map[x1][y1 + 1]= originVal;

    return ret;
}

int findMin(vector<int> position){

    vector<int> rotatedList = rotate(position);
    sort(rotatedList.begin(), rotatedList.end());

    return rotatedList[0];
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    initMap(rows, columns);

    for(vector<int> query : queries){
        answer.push_back(findMin(query));
    }

    return answer;
}
