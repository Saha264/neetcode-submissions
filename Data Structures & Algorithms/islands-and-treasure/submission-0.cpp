#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> chests;

        // 1. Add all chests (0) to the queue initially
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    chests.push({i, j});
                }
            }
        }

        // Direction vectors for moving: Up, Down, Left, Right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 1; // The distance we will assign to the next layer of rooms

        // 2. Multi-source BFS
        while (!chests.empty()) {
            int current_layer_size = chests.size(); // Snapshots the size of the current wave

            // Process all nodes at the current distance level
            for (int i = 0; i < current_layer_size; i++) {
                auto [x, y] = chests.front(); // Correct way to fetch from a queue
                chests.pop();

                // Check all 4 adjacent directions
                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    // Bounds check & ensure it is an unvisited room (2147483647 / INF)
                    // (Water/Walls are -1, Chests are 0, already visited rooms have a smaller number)
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 2147483647) {
                        grid[nx][ny] = time; // Set the current layer's time/distance
                        chests.push({nx, ny}); // Push to queue to explore its neighbors next
                    }
                }
            }
            
            // 3. Increment time only AFTER processing the entire current wave
            time++;
        }
    }
};