class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        int curr = arr[0];
        for(int i=1; i<arr.length; i++) {
            curr = getLeastCommonMultiple(curr, arr[i]);
        }
        answer = curr;
        return answer;
    }
    
    private int getLeastCommonMultiple(int a, int b) {
        for(int i=a; i<=a*b; i++) {
            if(i % a==0 && i%b==0) return i;
        }
        return -1;
    }
}
