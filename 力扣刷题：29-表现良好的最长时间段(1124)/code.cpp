class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ret = 0;
        unordered_map<int, int> ind;
        unordered_map<int, int> f;
        ind[0] = -1;
        f[0] = 0;
        int cnt = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8) {
                cnt ++;
            } else {
                cnt --;
            }
            if (ind.find(cnt) == ind.end()) {
                ind[cnt] = i;
                if (ind.find(cnt - 1) == ind.end()) {
                    f[cnt] = 0;
                } else {
                    f[cnt] = f[cnt - 1] + (i - ind[cnt - 1]);
                }
            }
            if (ind.find(cnt - 1) == ind.end()) {
                continue;
            }
            ret = max(ret, f[cnt - 1] + (i - ind[cnt - 1]));
        }
        return ret;
    }
};