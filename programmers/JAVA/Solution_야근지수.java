package programmers;

import java.util.Collections;
import java.util.PriorityQueue;

public class Solution_야근지수 {
	public long solution(int n, int[] works) {
        long answer = 0;
        int temp = 0;
        PriorityQueue<Integer> times = new PriorityQueue<Integer>(Collections.reverseOrder());
        
        for(int num : works) {
        	times.add(num);
        }
        
        while(n > 0) {
        	temp = times.peek() - 1;
        	times.remove();
        	times.add(temp);
        	n -= 1;
        }
        
        while(!times.isEmpty()) {
        	if(times.peek() <= 0) {
        		break;
        	}
        	answer += (times.peek() * times.peek());
        	times.remove();
        }
        
        return answer;
    }
}
