import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        List<String> cache = new ArrayList<>();
        
        for(String city : cities) {
            city = city.toLowerCase();
            if(cache.contains(city) && cacheSize > 0) {
                cache.remove(city);
                cache.add(city);
                answer += 1;
            } else {
                if(!cache.isEmpty() && cache.size() >= cacheSize) {
                    cache.remove(0);
                }
                cache.add(city);
                answer += 5;
            }
        }
        return answer;
    }
}