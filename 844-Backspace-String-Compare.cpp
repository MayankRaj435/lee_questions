class Solution {
public:
    string build(string s) {
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                res.push_back(s[i]);
            }
            else if (!res.empty()) {
                res.pop_back();
            }
        }

        return res;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};