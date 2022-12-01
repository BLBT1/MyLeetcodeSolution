class Solution {
    public boolean halvesAreAlike(String s) 
    {
        Set<Character> vows = new HashSet<>();
        
        for(char c: "aeiouAEIOU".toCharArray())
            vows.add(c);
        
        int mid = s.length()/2;
        int res = 0;
        for(int i = 0, j = mid; i < mid; ++i, ++j){
            if(vows.contains(s.charAt(i))) res += 1;
            if(vows.contains(s.charAt(j))) res -= 1;
        }
        
        return res == 0;
    }
}