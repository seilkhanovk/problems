class Solution {
    public:
    
    static bool cmp(string f, string s) {
        return f < s;
    }
    
    bool startsWith(string file, string parent) {
        if (file.length() < parent.length()) return false;
        string str = file.substr(0, parent.length());
        return str == parent;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), cmp);
        vector<string> result;
        string parent = " /";
        for (string filePath: folder) {
            if (!startsWith(filePath, parent)) {
                parent = filePath;
                parent += "/";
                result.push_back(filePath);
            }
            
        }
        return result;
    }
};
