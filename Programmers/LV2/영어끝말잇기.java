import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {0, 0};
        Set<String> store = new HashSet<>();
        store.add(words[0]);
        for(int i=1; i < words.length; i++) {
            int before = store.size();
            store.add(words[i]);
            if(store.size() == before || !isValid(words[i - 1], words[i])) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                break;
            }
        }
        return answer;
    }
    
    private boolean isValid(String before, String current) {
        if(before.charAt(before.length() - 1) == current.charAt(0)) 
            return true;
        return false;
    }
}   