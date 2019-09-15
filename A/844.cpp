class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stS;
        stack<char> stT;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != '#') stS.push(S[i]);
            else
                if (!stS.empty()) stS.pop();
        }
        for (int i = 0; i < T.length(); i++) {
            if (T[i] != '#') stT.push(T[i]);
            else
                if (!stT.empty()) stT.pop();
        }
        while (!stS.empty() && !stT.empty()) {
            if (stS.top() != stT.top()) return false;
            stS.pop(); stT.pop();
        }
        if (!stS.empty() || !stT.empty()) return false;
        return true;
    }
};
