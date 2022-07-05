class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int result = 0;
        for (int i : uset) {
            int current = 1;
            if (uset.find(i - 1) == uset.end()) {
                int k = i + 1;
                while (uset.find(k) != uset.end()) {
                    ++current;
                    ++k;
                }
                result = max(result, current);
            }
        }
        return result;
    }
};
