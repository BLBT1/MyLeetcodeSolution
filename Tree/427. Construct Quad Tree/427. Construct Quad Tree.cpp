/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        return helper(grid, 0, 0, n-1, n-1);
    }
    
    Node* helper(vector<vector<int>>& grid, int x_start, int y_start, int x_end, int y_end)
    {
        if(x_start > x_end || y_start > y_end)
            return nullptr;
        
        bool allSame = true;
        int val = grid[x_start][y_start];
        for(int i = x_start; i <= x_end; ++i)
        {
            for(int j = y_start; j <= y_end; ++j)
            {
                if(val != grid[i][j])
                {
                    allSame = false;
                    break;
                }
            }
            if(allSame == false)
                break;
        }
        
        Node* root = new Node();
        root->val = true;
        if(allSame)
        {
            root->isLeaf = true;
            root->val = (grid[x_start][y_start] == 1);
            return root;
        }
        
        int x_half = (x_end-x_start)/2+x_start;
        int y_half = (y_end-y_start)/2+y_start;
        root->isLeaf = false;
        root->topLeft = helper(grid, x_start, y_start, x_half, y_half);
        root->topRight = helper(grid, x_start, y_half+1, x_half, y_end);
        root->bottomLeft = helper(grid, x_half+1, y_start, x_end, y_half);
        root->bottomRight = helper(grid, x_half+1, y_half+1, x_end, y_end);
        return root;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};