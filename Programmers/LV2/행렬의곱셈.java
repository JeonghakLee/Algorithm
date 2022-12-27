class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer;
        int m = arr1.length;
        int n = arr2[0].length;
        int K = arr2.length;
        answer = new int[m][n];
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<K; k++) {
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        
        return answer;
    }
}