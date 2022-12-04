class Solution {
    
    List<Pair<Integer, Integer>> freq = new ArrayList<>();
    
    public int[] topKFrequent(int[] nums, int k)
    {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i: nums)
        {    
            mp.put(i, mp.getOrDefault(i, 0)+1);
        }
        
        for(int w: mp.keySet())
        {
            freq.add(new Pair<Integer, Integer>(mp.get(w), w));
        }
        int kthLargest = quickSelect(k, 0, freq.size()-1);
                
        int[] ans = new int[k];
        List<Integer> res = new ArrayList<>();
        for(Pair<Integer, Integer> p: freq){
            if(p.getKey() >= kthLargest)
            {
                res.add(p.getValue());
            }
        }
        
        
        for(int pos = 0; pos < res.size(); ++pos)
        {
            ans[pos] = res.get(pos);
        }
        return ans;
    }
    
    private int quickSelect(int k, int beg, int end)
    {    
        int pivot = freq.get(beg).getKey();
        
        // rank by pivot, like leetcode 75
        int w = beg; // checking
        int i = beg;
        int j = end;
        while(w <= j)
        {
            if(freq.get(w).getKey() < pivot)
            {
                swap(i, w);
                ++i;
                ++w;
            }
            else if(freq.get(w).getKey() > pivot)
            {
                swap(j, w);
                --j;
            }
            else
            {
                ++w;
            }
        }
        
        int leftSize = i - beg;
        int rightSize = end - j;
        
        if (rightSize>=k) 
        {
            return quickSelect(k, j+1, end);
        }
        else if (end-i+1>=k) 
        {
            return pivot;
        }
        else
        {
            return quickSelect(k-(end-i+1), beg, i-1);
        }
    }
    
    private void swap(int i, int j)
    {    
        var temp = freq.get(i);
        freq.set(i, freq.get(j));
        freq.set(j, temp);
    }
}
// beg        end
// SSSSSPPPPLLLL
//      i
//         j 
//          w 