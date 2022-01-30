class Solution {
private:
    void reversePre(int length, vector<int> &arr, vector<int> &ind) {
        for (int i = 0, j = length; i < j; i++, j--) {
            int t = ind[arr[i] - 1];
            ind[arr[i] - 1] = ind[arr[j] - 1];
            ind[arr[j] - 1] = t;

            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ret;
        vector<int> ind(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ind[arr[i] - 1] = i;
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr_max = ind[i]; // 当前最大
            if (curr_max == i) {
                continue;
            }
            // cout << curr_max << endl;
            if (curr_max > 0) {
                ret.push_back(curr_max + 1);
                reversePre(curr_max, arr, ind);
                // cout << ind[0] << ' ' << ind[1] << ' ' << ind[2] << endl;
                // cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
            }
            ret.push_back(i + 1);
            reversePre(i, arr, ind);
            // cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
        }
        return ret;
    }
};
