

class Solution {
    public int solution(int n) {
        int answer = n + 1;
        int oneCount = getOneCount(n);
        
        while(true) {
            if(oneCount == getOneCount(answer)) break;
            answer++;
        }
        
        return answer;
    }
    
    private int getOneCount(int n) {
        int count = 0;
        while(n>0) {
            if(n%2 == 1) count++;
            n /= 2;
        }
        return count;
    }
}