class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> save;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            string current = strs[i];
            sort(current.begin(), current.end());
            save[current].push_back(strs[i]);
        }

        res.reserve(save.size());
        for (auto& p : save)
            res.push_back(move(p.second));

        return res;
    }
};