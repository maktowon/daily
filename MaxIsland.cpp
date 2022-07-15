class Solution {
public:
    bool in(int n, int m, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size(), island = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    island = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        if (in(n, m, p.first, p.second) && grid[p.first][p.second] == 1) {
                            island++;
                            q.push({p.first - 1, p.second});
                            q.push({p.first + 1, p.second});
                            q.push({p.first, p.second - 1});
                            q.push({p.first, p.second + 1});
                            grid[p.first][p.second] = 0;
                        }
                    }
                }
                res = max(res, island);
            }
        }
        return res;
    }
};
