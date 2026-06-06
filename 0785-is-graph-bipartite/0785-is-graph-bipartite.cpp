class Solution {
public:

    vector<vector<int>> v ; 
    vector<int> vis, color ; 
    int is_Bipartite(int node , int c)
    {
        vis[node] = 1 ; 
        color[node] = c;
        int ans = 1 ; 
        for(auto it : v[node])
        {
            if(vis[it])
            {
                if(color[node] == color[it])
                {
                    ans = 0 ; 
                }
            }
            else{
                ans = ans && is_Bipartite(it, c^1);
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        v = graph ; 
        int n = graph.size() ; 
        vis.assign(n,0);
        color.assign(n,0);
        int ans = 1;
        for(int i = 0; i < n ; i++)
        {
            if(!vis[i])
            {
                ans = ans && is_Bipartite(i , 0);
            }
        }
        return ans;
    }
};