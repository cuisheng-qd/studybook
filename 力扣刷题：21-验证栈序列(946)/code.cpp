class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int poppedIndex = 0;
        for (auto i : pushed) {
            s.push(i);
            while (!s.empty() && s.top() == popped[poppedIndex]) {
                s.pop();
                poppedIndex++;
            }
        }
        return s.empty();
    }
};
