class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj [n];
        for(int i=0;i<edges.size();i++){
                int no=edges[i][0];
                int adj_no=edges[i][1];
                adj[no].push_back({adj_no,succProb[i]}); 
                adj[adj_no].push_back({no,succProb[i]}); // adj_node - prob
        }

        priority_queue<pair<double,int>>qu;
        
        qu.push({1.0,start_node});

        vector<double>dis(n,INT_MIN);
        dis[start_node]=1;

        while(!qu.empty()){
            int node=qu.top().second;
            double dist=qu.top().first;
            qu.pop();
          

            for(auto it : adj[node]){
                int adj_node=it.first;
                double cost=it.second;
                if(dist*cost>dis[adj_node]){
                    dis[adj_node]=dist*cost;
                    qu.push({dis[adj_node],adj_node});
                }
            }
        }

        if(dis[end_node]==INT_MIN) return 0.0000;
        else return dis[end_node];

    }
};