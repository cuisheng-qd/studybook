class Log {
public:
    int func = 0;
    string type;
    int timestamp = 0;
};

class Solution {
private:
    Log parse(string s) {
        Log log;
        int sts = 1;
        int curr = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (sts) {
                case 1:
                    if (s[i] == ':') {
                        sts = 2;
                        curr = i + 1;
                    } else {
                        log.func = log.func * 10 + (s[i] - '0');
                    }
                    break;
                case 2:
                    if (s[i] == ':') {
                        log.type = s.substr(curr, i - curr);
                        sts = 3;
                        curr = i + 1;
                    }
                    break;
                case 3:
                    log.timestamp = log.timestamp * 10 + (s[i] - '0');
                    break;
            }
        }
        return log;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n);
        stack<int> funcS;
        int currTimestamp = -1;
        for (auto s : logs) {
            Log log = parse(s);
            if (log.type == "start") {
                if (!funcS.empty()) {
                    ret[funcS.top()] += log.timestamp - currTimestamp;
                }
                funcS.push(log.func);
                currTimestamp = log.timestamp;
            } else if (log.type == "end") {
                ret[log.func] += log.timestamp - currTimestamp + 1;
                funcS.pop();
                currTimestamp = log.timestamp + 1;
            }
        }
        return ret;
    }
};
