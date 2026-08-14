class Solution {
    private:


    int findp(int node,vector<int> &parent){

        if(node==parent[node]){
            return node;
        }
        return parent[node]=findp(parent[node],parent);

    }

    void  unionF(int i,int j,vector<int> &parent,vector<int> &rank){

        int u=findp(i,parent);
        int v=findp(j,parent);

        if(u==v){
            return;
        }
        if(rank[u]==rank[v]){
            parent[v]=u;
            rank[u]++;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;

        }
        else{
            parent[u]=v;
        }



    }



public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent(stones.size());
        vector<int> rank(stones.size(),0);


        for(int i=0;i<stones.size();i++){
            parent[i]=i;
        }


        for(int i=0;i<stones.size();i++){
           

            for(int j=i+1;j<stones.size();j++){
                    if(stones[i][0]==stones[j][0] || stones[i][1] == stones[j][1]){
                        unionF(i,j,parent,rank);
                    }
            }
        }
        int component=0;

        for(int i=0;i<stones.size();i++){
            if(parent[i]==i){
                component++;
            }
        }

        return stones.size()-component;
        
        


        
    }
};