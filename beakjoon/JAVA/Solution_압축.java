package baekjoon;

import java.util.Scanner;

public class Solution_æ–√‡ {
	public static void main(String[] args) {
		String input ="";
		Scanner scan = new Scanner(System.in);
		input = scan.next();
		System.out.println(decoder(input));
	}
	
	public static int decoder(String str) {
		int ret = 0;
		int idx = 0;
		
		while(idx < str.length()) {
			if(str.charAt(idx) == '(') {
				int bracketCnt = 1;
				int startIdx = idx + 1;
				int endIdx = startIdx;
				while(bracketCnt > 0) {
					idx++;
					if(str.charAt(idx) == ')') {
						bracketCnt --;
					}
					else if(str.charAt(idx) == '('){
						bracketCnt ++;
					}
				}
				endIdx = idx;
				ret += decoder(str.substring(startIdx, endIdx)) * (str.charAt(startIdx - 2) - '0');
				ret--;
			}
			else {
				ret++;
			}
			idx++;
		}
		return ret;
	}

}
