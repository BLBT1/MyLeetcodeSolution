```c++
class Node {
public: 
    // string path;
    int value;
    unordered_map<string, Node*> next;

    Node(int value){
        this->value = value;
    }    
};

class FileSystem {
    Node* root;
public:
    FileSystem() {
        root = new Node(-1);
    }
    
    bool createPath(string path, int value) {
        vector<string> subPaths;
        int i = 0;
        while (i < path.size()) {
            int j = i+1; 
            while(j < path.size() && path[j] != '/') 
                ++j;
            
            subPaths.push_back(path.substr(i, j-i));
            i = j;
        }

        Node* curr = root;
        for (int i = 0; i < subPaths.size(); ++i){
            string s = subPaths[i];
            if (curr->next.find(s) == curr->next.end()){
                if (i != subPaths.size()-1){
                    // missing parent path
                    return false;
                } else {
                    curr->next[s] = new Node(value);
                    return true;
                }
            } else{
                if (i == subPaths.size()-1){
                    return false;
                } else {
                    curr = curr->next[s];
                }
            }
        }
        return true;
    }
    
    int get(string path) {
        vector<string> subPaths;
        int i = 0;
        while (i < path.size()) {
            int j = i+1; 
            while(j < path.size() && path[j] != '/') 
                ++j;
            
            subPaths.push_back(path.substr(i, j-i));
            i = j;
        }

        Node* curr = root;
        for (int i = 0; i < subPaths.size(); ++i){
            string s = subPaths[i];
            if (curr->next.find(s) == curr->next.end()){
                return -1;
            } else{
                curr = curr->next[s];
            }
        }
        return curr->value;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

// internally file system is like a tree

// /leetcode/foo
// /leetcode/bar

// /leetcode -> /foo
//           -> /bar


```