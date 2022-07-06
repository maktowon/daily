class Solution {
public:
    int res = 0, empty = 1;
    bool in(int x, int y, vector<vector<int>>& grid) {
        return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != -1);
    }
    void dfs(int x, int y, vector<vector<int>>& grid, int squares) {
        if (in(x, y, grid)) {
            if (grid[x][y] == 2) {
                if (squares == empty) ++res;
                return;
            }
            grid[x][y] = -1;
            dfs(x - 1, y, grid, squares + 1);
            dfs(x + 1, y, grid, squares + 1);
            dfs(x, y - 1, grid, squares + 1);
            dfs(x, y + 1, grid, squares + 1);
            grid[x][y] = 0;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx, starty;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) ++empty;
                else if (grid[i][j] == 1) startx = i, starty = j;
            }
        }
        dfs(startx, starty, grid, 0);
        return res;
    }
};
