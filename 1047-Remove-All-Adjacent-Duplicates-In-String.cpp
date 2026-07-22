class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && st.top() == s[i]) {   //check if stack is empty ;if not check the top element of stack whether it is not equal to the element present in the string ; if found pop it
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";   //we need to store the ans of the stack somewhere so an "ans" string defined

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());        //because we need to reverse for exampe abbaca so while popping out ,order will be -> a c   and we need to preserve the order so reverse it 

        return ans;
    }
};