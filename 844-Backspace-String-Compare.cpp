class Solution {
public:
    string build(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                st.push(s[i]);
            }
            else if (!st.empty()) {
                st.pop();
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};