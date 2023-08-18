// Problem Name: Cycle in Undirected Graph
// Problem Link: https://www.interviewbit.com/problems/cycle-in-undirected-graph/

int Solution::solve(int n, vector<vector<int>> &mat){
    vector<vector<int>> adj(n+1);
    for(auto &m : mat){
        adj[m[0]].push_back(m[1]);
        adj[m[1]].push_back(m[0]);
    }
    vector<bool> vis(n+1, 0); 
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            queue<pair<int, int>> q; q.push({i, -1});
            vis[i] = 1;
            while(q.size()){
                auto x = q.front(); q.pop();
                int u = x.first, p = x.second;
                for(int v : adj[u]){
                    if(v!=p and vis[v]) return 1;
                    if(!vis[v]) q.push({v, u}), vis[v] = 1;
                }
            }
        }
    }
    return 0;
}