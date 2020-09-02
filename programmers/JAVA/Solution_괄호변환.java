package programmers;

import java.util.*;

public class Solution_°ýÈ£º¯È¯ {
	public String solution(String p) {
        String answer = "";
        answer = makeStr(p);
        return answer;
    }
	
	public String makeStr(String w) {
		if(w == "") {
			return "";
		}
		
		String u = "";
		String v = "";
		String retStr = "";
		int idx = 0;
		boolean flag = true;
		
		Stack<Character> s = new Stack<Character>();
		
		s.push(w.charAt(idx));
		while(!s.empty()) {
			idx++;
			if(s.peek() == ')') {
				flag = false;
			}
			if(w.charAt(idx) == s.peek()) {
				s.push(w.charAt(idx));
			}
			else {
				s.pop();
			}
		}
		
		if(idx != w.length() - 1) {
			u = w.substring(0, idx + 1);
			v = w.substring(idx+1);
		}
		else {
			u = w;
		}
		
		if(flag) {
			return u + makeStr(v);
		}
		
		retStr += "(" + makeStr(v) + ")";
		
		u = u.substring(1, u.length() - 1);
		for(int i = 0; i < u.length(); i++) {
			if(u.charAt(i) == '(') {
				retStr += ")";
				continue;
			}
			retStr += "(";
		}
		
		return retStr;
	}
}
