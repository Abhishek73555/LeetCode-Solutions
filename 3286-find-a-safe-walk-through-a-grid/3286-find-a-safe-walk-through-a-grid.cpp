#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dist[r][c] stores the minimum health damage taken to reach cell (r, c)
        // Initialize with a large number (infinity proxy)
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        // Double-ended queue for 0-1 BFS
        // Stores coordinates as pairs: {row, col}
        deque<pair<int, int>> dq;
        
        // Initialize the starting position
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        // Direction vectors for 4-way movement: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            // Early exit optimization if we reach the destination
            if (r == m - 1 && c == n - 1) {
                break;
            }
            
            // Explore all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Boundary check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc]; // 0 if safe, 1 if unsafe
                    int next_cost = dist[r][c] + weight;
                    
                    // If a safer path to the neighbor is found
                    if (next_cost < dist[nr][nc]) {
                        dist[nr][nc] = next_cost;
                        
                        // 0-1 BFS priority ordering
                        if (weight == 0) {
                            dq.push_front({nr, nc}); // 0 cost moves go to the front
                        } else {
                            dq.push_back({nr, nc});  // 1 cost moves go to the back
                        }
                    }
                }
            }
        }
        
        // To survive, final damage must be strictly less than initial health
        return dist[m - 1][n - 1] < health;
    }
};
