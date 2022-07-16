class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 1, up = 0, down = 0, temp = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            ++result;
            if (ratings[i] < ratings[i - 1]) {
                if (up == 0) {
                    ++down;
                    result += down;
                    if (temp > 0 && temp <= down) {
                        ++result;
                    }
                }
                else {
                    temp = up;
                    up = 0;
                }
            }
            else if (ratings[i] > ratings[i - 1]) {
                ++up;
                result += up;
                down = 0;
            }
            else {
                up = 0, down = 0, temp = 0;
            }
        }
        return result;
    }
};
