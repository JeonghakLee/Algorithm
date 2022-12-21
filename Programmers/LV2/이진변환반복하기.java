class Solution {
    public int[] solution(String s) {
        int[] answer = {0, 0};
        int x = 0;
        int zeroCount = 0;
        
        while(true) {
            zeroCount = s.length();
            s = s.replaceAll("0", "");
            x = s.length();
            zeroCount -= x;
            answer[1] += zeroCount; 
            s = getBinary(x);
            answer[0]++;
            if(s.equals("1")) break;
        }
        return answer;
    }
    
    private String getBinary(int x) {
        String result = "";
        while(x > 0) {
            result = Integer.toString(x%2) + result;
            x /= 2;
        }
        return result;
    }
}