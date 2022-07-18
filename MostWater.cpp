class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0, l = 0, r = height.size() - 1, length = height.size() - 1;
        while (length > 0) {
            ret = max(ret, min(height[l], height[r]) * length);
            if (height[l] > height[r]) {
                r--;
            }
            else {
                l++;
            }
            length--;
        }
        return ret;
    }
};
