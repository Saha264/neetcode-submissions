#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if (heights.empty() || heights[0].empty()) return res;

        int m = heights.size();     // Rows
        int n = heights[0].size();  // Columns

        // 2D grids to track reachable cells from each ocean
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 1. Call DFS for Top and Bottom edges
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, heights[0][j]);             // Top edge (Pacific)
            dfs(heights, atlantic, m - 1, j, heights[m - 1][j]);     // Bottom edge (Atlantic)
        }

        // 2. Call DFS for Left and Right edges
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, heights[i][0]);             // Left edge (Pacific)
            dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);     // Right edge (Atlantic)
        }

        // 3. Find cells that can reach both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, int prev_height) {
        int m = heights.size();
        int n = heights[0].size();

        // Base cases: 
        // - Out of bounds
        // - Already visited (prevents infinite loops)
        // - Height is decreasing (water can't flow backward up a hill, so moving inward requires heights[x][y] >= prev_height)
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || heights[x][y] < prev_height) {
            return;
        }

        // Mark current cell as reachable
        visited[x][y] = true;

        // Traverse all 4 directions
        dfs(heights, visited, x + 1, y, heights[x][y]);
        dfs(heights, visited, x - 1, y, heights[x][y]);
        dfs(heights, visited, x, y + 1, heights[x][y]);
        dfs(heights, visited, x, y - 1, heights[x][y]);
    }
};