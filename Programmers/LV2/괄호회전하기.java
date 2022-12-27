import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        for(int i=0; i<s.length(); i++) {
            String lotated = s.substring(i) + s.substring(0, i);
            if(isValid(lotated)) answer++;
        }
        return answer;
    }
    
    private boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        
        for(int i=0; i<s.length(); i++) {
            char curr = s.charAt(i);
            if(stack.isEmpty()) {
                stack.push(curr);
                continue;
            }
            
            char top = stack.peek();
            if(
                (top == '(' && curr == ')') ||
                (top == '[' && curr == ']') || 
                (top == '{' && curr == '}')
            ) stack.pop(); 
            else stack.push(curr);
        }
        
        return stack.isEmpty();
    }
}