class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hsize = horizontalCuts.size(), vsize = verticalCuts.size();
        int hmax = max(horizontalCuts[0], h - horizontalCuts[hsize - 1]);
        int vmax = max(verticalCuts[0], w - verticalCuts[vsize - 1]);
        for (int i = 1; i < hsize; ++i) {
            hmax = max(hmax, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < vsize; ++i) {
            vmax = max(vmax, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (long)hmax * vmax % 1000000007;
    }
};
