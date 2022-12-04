class Solution {
    public boolean closeStrings(String word1, String word2) 
    {
        if(word1.length() != word2.length())
            return false;
        
        int[] cnt1 = new int[26], cnt2 = new int[26];
        for(var c : word1.toCharArray()){
            cnt1[c-'a']++;
        }
        for(var c : word2.toCharArray()){
            cnt2[c-'a']++;
        }
        
        // if one word has some char that the other word does not, then false
        for(int i = 0; i < 26; ++i){
            if(cnt1[i] != 0 && cnt2[i] == 0)
                return false;
            if(cnt2[i] != 0 && cnt1[i] == 0)
                return false;
        }
        
        Arrays.sort(cnt1);
        Arrays.sort(cnt2);
        for(int i = 0; i < 26; ++i){
            if(cnt1[i] != cnt2[i])
                return false;
        }
        
        return true;
    }
}
// op1, op2 =>1. two string has same exisiting chars
//            2. frq of all all chars exisiting is the same after sorting