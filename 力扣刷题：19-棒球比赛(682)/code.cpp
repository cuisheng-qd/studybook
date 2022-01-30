class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (auto op : ops) {
            if (op == "+") {
                int t = s.top();
                s.pop();
                int n = t + s.top();
                s.push(t);
                s.push(n);
            } else if (op == "D") {
                s.push(s.top() * 2);
            } else if (op == "C") {
                s.pop();
            } else {
                int n = 0;
                for (auto i : op) {
                    if (i == '-') {
                        continue;
                    }
                    n = n * 10 + (i - '0');
                }
                if (op[0] == '-') {
                    n = -n;
                }
                s.push(n);
            }
        }
        int ret = 0;
        while (!s.empty()) {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
};
