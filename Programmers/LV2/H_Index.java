import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int n = citations.length;
        Arrays.sort(citations);
        
        // h는 전체 논문 수 보다 작거나 같다.
        for(int i=0; i<n; i++) {
            int h = n - i;  // 현재 인용 횟수 이상인 논문 수
            
            // 현재 논문의 인용 횟수가 현재 인용 횟수 이상인 논문 수 이상이 되면 조건 만족
            if(citations[i] >= h) {
                answer = h;
                break;
            }
        }
        
        return answer;
    }
}