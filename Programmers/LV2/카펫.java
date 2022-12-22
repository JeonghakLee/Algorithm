class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {0, 0};
        int total = brown + yellow;
    
        for(int i=1; i <= total/2; i++) {
            if((total) % i == 0) {
                if((i * 2 + total / i * 2) - 4 == brown){
                    answer[0] = total / i;
                    answer[1] = i;
                    break;
                }
            }
        }
        return answer;
    }
}