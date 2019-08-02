class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') str += s[i];
        }
        int l = 0, r = str.length() - 1;
        while (l < r) {
            if (!isalpha(str[l]) && !isdigit(str[l])) {
                l++;
                continue;
            }
            
            if (!isalpha(str[r]) && !isdigit(str[r])) {
                r--;
                continue;
            }
            char lChar = tolower(str[l]);
            char rChar = tolower(str[r]);
            cout<<lChar<<" "<<rChar;
            if (lChar != rChar) return false;
            l++;
            r--;
        }
        return true;
    }
};
