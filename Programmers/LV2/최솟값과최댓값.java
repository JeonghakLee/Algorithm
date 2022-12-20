class Solution {
    public String solution(String s) {
        String answer = "";
        int min = 0x7f7f7f7f, max = -0x7f7f7f7f;
        String[] numbers = s.split(" ");
        
        for(String number : numbers) {
            int num = Integer.parseInt(number);
            if(num > max) max = num;
            if(num < min) min = num;
        }
        
        answer = Integer.toString(min) + " " + Integer.toString(max);
        
        return answer;
    }
}