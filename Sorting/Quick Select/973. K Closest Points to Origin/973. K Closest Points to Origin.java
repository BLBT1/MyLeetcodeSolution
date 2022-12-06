class Solution {
    class Point{
        long dist;
        int x;
        int y;
    }
    private List<Point> ptList = new ArrayList<>();
    
    public int[][] kClosest(int[][] points, int k) 
    {   
        for(var p: points)
        {
            var pt = new Point();
            pt.x = p[0];
            pt.y = p[1];
            pt.dist = pt.x*pt.x+pt.y*pt.y;
            ptList.add(pt);
        }
        
        long kthClosest = quickSelect(0, ptList.size()-1, k);
        
        List<Point> res = new ArrayList<>();
        for(var pt: ptList)
        {
            if(pt.dist <= kthClosest)
                res.add(pt);
        }
        
        int[][] ans = new int[res.size()][];
        for(int i  = 0; i < res.size(); ++i)
        {    
            ans[i] = new int[]{res.get(i).x, res.get(i).y};
        }
        return ans;
    }
    
    private long quickSelect(int begin, int end, int k)
    {
        long pivot = ptList.get(begin).dist;
        int i = begin, j = end, t = begin;
        while(t <= j)
        {
            if(ptList.get(t).dist < pivot)
            {
                swap(i, t);
                ++t;
                ++i;
            }
            else if(ptList.get(t).dist > pivot)
            {
                swap(t, j);
                --j;
            }
            else
            {
                ++t;
            }
        }
        
        if(i-begin >= k)
            return quickSelect(begin, i-1, k);
        else if(j-begin+1 >= k)
            return pivot;
        else
            return quickSelect(j+1, end, k-(j-begin+1));
    }
    
    private void swap(int i, int j)
    {
        var temp = ptList.get(i);
        ptList.set(i, ptList.get(j));
        ptList.set(j, temp);
    }
}

// SSSS PPPPP LLLL 
// b    i   j    e




