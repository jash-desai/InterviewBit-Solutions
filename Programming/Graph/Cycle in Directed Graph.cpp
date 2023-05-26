// Problem Name: Cycle in Directed Graph

// int root(int i,vector<int>&arr){
//     if(arr[i]==-1) return i;
//     return root(arr[i],arr);
// }
// void uni(int a,int b,vector<int>&arr){
//     int ra=root(a,arr);
//     int rb=root(b,arr);
//     arr[a]=b;
// }
// int Solution::solve(int A, vector<vector<int>> &m) {
//     vector<int> arr(A+1,-1);
//     for(int i=0;i<m.size();i++){
//         int ra=root(m[i][0],arr);
//         int rb=root(m[i][1],arr);
//         if(ra==rb) return 1;
//         uni(m[i][0],m[i][1],arr);
//     }
//     return 0;
// }
bool dfs(vector<vector<int>>&adj, unordered_set<int>&s, vector<bool>&vis, int u){
    vis[u]=1; s.insert(u);
    for(int v : adj[u]){
        if(s.count(v)) return 1;
        if(dfs(adj,s,vis,v)) return 1;
    }
    s.erase(u); vis[u]=0;
    return 0;
}
int Solution::solve(int V, vector<vector<int>>&m){
    unordered_set<int> s; vector<vector<int>> adj(V+1);
    // converting into a adjacency list -
    for(auto v:m){
        int x = v[0], y=v[1];
        adj[x].push_back(y);
    }
    vector<bool> vis(V+1,false);
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            if(dfs(adj,s,vis,i)) return 1;
        }
    }
    return 0;
}
