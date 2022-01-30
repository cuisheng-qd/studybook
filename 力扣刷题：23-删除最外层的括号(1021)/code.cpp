class Solution {
public:
    string removeOuterParentheses(string s) {
        string ret = "";
        int pre = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                ret += s.substr(pre + 1, i - pre - 1);
                pre = i + 1;
            }
        }
        return ret;
    }
};
