class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") {
            return true;
        }
        vector<string> vec;
        int curr = 0;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',') {
                vec.push_back(preorder.substr(curr, i - curr));
                curr = i + 1;
            } else {
                continue;
            }
            process(vec);
        }
        if (curr == 0) {
            return false;
        }
        vec.push_back(preorder.substr(curr));
        process(vec);
        return vec.size() == 1;
    }

    void process(vector<string> &vec) {
        while (vec.size() > 2 && vec[vec.size() - 1] == "#" && vec[vec.size() - 2] == "#" && vec[vec.size() - 3] != "#") {
            vec.pop_back();
            vec.pop_back();
            vec.pop_back();
            vec.push_back("#");
        }
    }
};
