class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 1;
        
        if(b < a) {
            int temp = b;
            b = a;
            a = temp;
        }
        
        while(true) {
            if(a%2==1 && b - a == 1) break;
            a = (a + 1)/2;
            b = (b + 1)/2;
            answer++;
        }

        return answer;
    }
}