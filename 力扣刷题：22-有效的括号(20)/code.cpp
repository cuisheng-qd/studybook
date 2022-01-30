class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        for (auto i : s) {
            switch (i) {
                case '(':
                case '[':
                case '{':
                    k.push(i);
                    break;
                default:
                    if (k.empty()) {
                        return false;
                    }
                    if (i == ')' && k.top() == '(') {
                        k.pop();
                        break;
                    }
                    if (i == ']' && k.top() == '[') {
                        k.pop();
                        break;
                    }
                    if (i == '}' && k.top() == '{') {
                        k.pop();
                        break;
                    }
                    return false;
            }
        }
        return k.empty();
    }
};
