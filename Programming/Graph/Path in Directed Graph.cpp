// Problem Name: Path in Directed Graph

const int inf = 100009;
vector<int> adj[inf];
bool vis[inf];
void init(){
    for(int i=0; i<inf; i++) adj[i].clear();
    memset(vis, false, sizeof vis);
}
bool fxn(int s, int d) {
    if (s==d) return 1;
    queue<int> q; q.push(s);
    vis[s]=1;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(auto v: adj[u]) {
        if(v==d) return 1;
        if(!vis[v]) {
          vis[v] = 1; q.push(v);
        }
      }
    }
    return 0;
}
int Solution::solve(int V, vector<vector<int>>&m){
  init();
  for(auto &v: m) adj[v[0]].push_back(v[1]);
  return (fxn(1,V));
}

