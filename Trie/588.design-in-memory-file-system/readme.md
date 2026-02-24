需要注意细节的题目
- need to separate filePath vs. directory path
- need to trim the prefix '/' for split
- to optimize, we can store all content for files in a map for faster read

```c++
class DirNode {
public:
    // for file content can be store in map, not in the tree
    // string content;
    string file;
    bool isFile;
    unordered_map<string, DirNode*> next;
    DirNode(bool isFile, string file){
        this->isFile = isFile,
        this->file = file;
    }
};

class FileSystem {
    DirNode *root;
    unordered_map<string, string> contentFile; // file -> content
public:
    FileSystem() {
        root = new DirNode(false, "/");
    }
    
    vector<string> ls(string path) {
        if(path == "/")
            return getPathFromCurr(root);

        auto subs = split(path);
        DirNode* curr = root;
        int i = 0;
        while(i < subs.size()){
            curr = curr->next[subs[i]];
            ++i;
        }
        if (!curr->isFile)
            return getPathFromCurr(curr);
        else
            return {curr->file}; 
    }
    
    void mkdir(string path) {
        auto subs = split(path);
        DirNode* curr = root;
        int i = 0;
        while(i < subs.size()){
            if (curr->next.find(subs[i]) == curr->next.end()){
                curr->next[subs[i]] = new DirNode(false, subs[i].substr(0));
            }
            curr = curr->next[subs[i]];
            ++i;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        auto subs = split(filePath);
        DirNode* curr = root;
        int i = 0;
        // we still need this, otherwise we don't know if the file name from ls
        while(i < subs.size()){
            if (curr->next.find(subs[i]) == curr->next.end()){
                curr->next[subs[i]] = new DirNode(true, subs[i].substr(0));
            }
            curr = curr->next[subs[i]];
            ++i;
        }
        // curr->content += content;
        contentFile[filePath] += content;
    }
    
    string readContentFromFile(string filePath) {
        // auto subs = split(filePath);
        // DirNode* curr = root;
        // int i = 0;
        // while(i < subs.size()){
        //     curr = curr->next[subs[i]];
        //     ++i;
        // }
        // return curr->content;
        
        // faster access than store content on the node
        return contentFile[filePath];
    }

    // if split returns empty, it is the root dir
    vector<string> split(string path) {
        vector<string> subPaths;
        int i = 0;
        int j = i+1;
        while(i < path.size()){
            while(j < path.size() && path[j] != '/')
                ++j;
            subPaths.push_back(path.substr(i+1, j-i-1)); // strap the '/' prefix
            i = j;
            j = j+1;
        }
        return subPaths;
    }

    vector<string> getPathFromCurr(DirNode *curr){
        vector<string> res;
        for(auto p: curr->next){
            res.push_back(p.first);
        }
        sort(res.begin(), res. end());
        return res;
    }  
};

// /bc
// i
//     j

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
```
