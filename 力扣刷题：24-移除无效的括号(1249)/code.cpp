class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ret = "";
        int pre = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '(':
                cnt ++;
                break;
            case ')':
                cnt --;
                break;
            }
            if (cnt == -1) {
                ret += s.substr(pre, i - pre);
                cnt = 0;
                pre = i + 1;
            }
        }
        ret += s.substr(pre, s.size() - pre);
        if (cnt == 0) {
            return ret;
        }

        s = ret;
        ret = "";
        pre = s.length() - 1;
        cnt = 0;
        for (int i = pre; i >= 0; i--) {
            switch (s[i]) {
            case '(':
                cnt --;
                break;
            case ')':
                cnt ++;
                break;
            }
            if (cnt == -1) {
                ret = s.substr(i + 1, pre - i) + ret;
                cnt = 0;
                pre = i - 1;
            }
        }
        ret = s.substr(0, pre + 1) + ret;
        return ret;
    }
};
