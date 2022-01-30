class Solution {
public:
    int level(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '@':
                return -1;
        }
        return 0;
    }
    int cal(int num1, char op, int num2) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        }
        return 0;
    }
    int calculate(string s) {
        stack<int> operand;
        stack<char> operate;
        s += '@';
        for (int i = 0, num = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (level(s[i]) == 0) {
                num = num * 10 + (s[i] - '0');
                continue;
            }
            operand.push(num);
            num = 0;
            while (!operate.empty() && level(operate.top()) >= level(s[i])) {
                int num2 = operand.top();
                operand.pop();
                int num1 = operand.top();
                operand.pop();
                operand.push(cal(num1, operate.top(), num2));
                operate.pop();
            }
            operate.push(s[i]);
        }
        return operand.top();
    }
};
