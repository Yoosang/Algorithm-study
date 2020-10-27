package baekjoon;

import java.util.Scanner;

public class Solution_ºø¹° {

	public static void main(String[] args) {
		int ret = 0;
		Scanner scan = new Scanner(System.in);
		int h, w;
		int[] heights = new int[501];
		h = scan.nextInt();
		w = scan.nextInt();
		for(int i = 0; i < w; i++) {
			heights[i] = scan.nextInt();
		}
		
		int idx = 1;
		int maxVal = heights[0];
		
		for(int i = 1; i < w - 1; i++) {
			int leftIdx = -1;
			int rightIdx = w;
			int minValue = 0;
			
			for(int j = i - 1; j >= 0; j--) {
				if(heights[j] > heights[i]) {
					leftIdx = j;
					break;
				}
			}
			if(leftIdx == -1) {
				continue;	
			}
			
			for(int j = i + 1; j < w; j++) {
				if(heights[j] > heights[i]) {
					rightIdx = j;
					break;
				}
			}
			if(rightIdx == w) {
				continue;
			}
			
			minValue = (heights[leftIdx] <= heights[rightIdx]) ? heights[leftIdx] : heights[rightIdx];
			
			for(int j = leftIdx + 1; j <= rightIdx - 1; j++) {
				ret += (minValue - heights[j]);
				heights[j] = minValue;
			}
			
		}
		System.out.println(ret);
	}
}
