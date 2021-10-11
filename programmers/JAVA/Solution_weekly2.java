package programmers;

import java.util.Arrays;

public class Solution_weekly2 {
    public String solution(int[][] scores) {
        String answer = "";
        int numOfStudent = scores.length;
        int[][] newScores = getNewScores(scores);

        for(int c = 0; c < numOfStudent; c++){
            int newNumOfStudent = numOfStudent;
            int sumOfScores = 0;
            for(int r = 0; r < numOfStudent; r++){
                if(newScores[r][c] == -1){
                    newNumOfStudent += newScores[r][c];
                    continue;
                }
                sumOfScores += newScores[r][c];
            }
            answer += getCredit((double) sumOfScores/(double)newNumOfStudent);
        }

        return answer;
    }

    public String getCredit(double score){
        if(score >= 90.0){
            return "A";
        }
        else if(score >= 80.0){
            return "B";
        }
        else if(score >= 70.0){
            return "C";
        }
        else if(score >= 50.0){
            return "D";
        }
        else{
            return "F";
        }
    }

    /*
    본인의 점수가 최저, 최고일 경우를 제외한 scores
    (-1 로 표기)
     */
    public int[][] getNewScores(int[][] map){
        int[][] newMap = new int[map.length][map.length];
        int[] temp = new int[map.length];
        for(int i = 0; i < newMap.length; i++){
            for(int j = 0; j < newMap.length; j++){
                temp[j] = map[j][i];
            }
            Arrays.sort(temp);
            int maxVal = temp[temp.length - 1];
            int minVal = temp[0];

            if(map[i][i] == minVal && minVal != temp[1]){
                map[i][i] = -1;
            }
            if(map[i][i] == maxVal && maxVal != temp[temp.length - 2]){
                map[i][i] = -1;
            }
            for(int j = 0; j < newMap.length; j++){
                newMap[j][i] = map[j][i];
            }
        }
        return newMap;
    }
}
