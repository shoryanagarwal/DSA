class Solution {
private:
    int findp(int node,vector<int> &parent){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findp(parent[node],parent);

    }



public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size()<n-1){
            return -1;
        }
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int component=0;
        int extra=0;

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            int p_u=findp(u,parent);
            int p_v=findp(v,parent);

            if(p_u==p_v){
                extra++;
                continue;

            }

            if(rank[p_u]==rank[p_v]){
                parent[p_v]=parent[p_u];
                rank[p_u]++;
            }
            else if(rank[p_u]>rank[p_v]){
                 parent[p_v]=parent[p_u];
            }
            else{
                parent[p_u]=parent[p_v];
            }
        }



        //finding componenets;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                component++;
            }
        }

        if(extra>=component-1){
            return component-1;
        }
      
        return -1;
        
        
    }
};