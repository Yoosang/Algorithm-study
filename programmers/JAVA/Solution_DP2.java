/**
 프로그래머스 Dynamic Programming
 정수 삼각형 (Level 3)
 출처: https://programmers.co.kr/learn/courses/30/lessons/43105
 */

package programmers;

public class Solution_DP2 {
    public int solution(int[][] triangle) {
        int answer = 0;
        int h = triangle.length;
        int[][] sum = new int[h][h];
        sum[0][0] = triangle[0][0];

        for(int row = 1; row < h; row++){
            for(int col = 0; col < row + 1; col++){
                if(col == 0){
                    sum[row][col] = triangle[row][col] + sum[row-1][col];
                }
                else{
                    sum[row][col] = triangle[row][col] + Math.max(sum[row - 1][col], sum[row - 1][col - 1]);
                }
            }
        }

        for(int i = 0; i < h; i++){
            answer = Math.max(sum[h-1][i], answer);
        }

        return answer;
    }
}
