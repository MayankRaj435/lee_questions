class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int,int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0,0});

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        while(!dq.empty()){

            int r = dq.front().first;
            int c = dq.front().second;
            dq.pop_front();

            for(int k=0;k<4;k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m){

                    int wt = grid[nr][nc];

                    if(dist[r][c] + wt < dist[nr][nc]){

                        dist[nr][nc] = dist[r][c] + wt;

                        if(wt == 0)
                            dq.push_front({nr,nc});
                        else
                            dq.push_back({nr,nc});
                    }
                }
            }
        }

        return dist[n-1][m-1] < health;
    }
};