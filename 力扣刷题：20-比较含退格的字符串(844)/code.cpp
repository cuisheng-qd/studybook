class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        str2stack(&s1, &s);
        str2stack(&s2, &t);

        if (s1.size() != s2.size()) {
            return false;
        }
        while (s1.size() > 0 && s1.top() == s2.top()) {
            s1.pop();
            s2.pop();
        }
        return s1.size() == 0;
    }
    void str2stack(stack<char> *s, string *t) {
        for (auto i : *t) {
            if (i == '#') {
                if (s->size() > 0) {
                    s->pop();
                }
            } else {
                s->push(i);
            }
        }
    }
};
