class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        if (n == 1)
            return 1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        queue<pair<int, int>> q;

        dist[0][0] = 1;
        q.push({0, 0});

        int dr[] = {-1,-1,-1,0,0,1,1,1};        //there striver has explored 4 directions ,but here we need to explore diagonals as well
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 &&
                    dist[row][col] + 1 < dist[newRow][newCol]) {

                    dist[newRow][newCol] = dist[row][col] + 1;

                    if (newRow == n - 1 && newCol == n - 1)
                        return dist[newRow][newCol];

                    q.push({newRow, newCol});
                }
            }
        }

        return -1;
    }
};