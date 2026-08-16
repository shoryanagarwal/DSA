class Solution {

private:

    int findp(int node,vector<int> &parent){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findp(parent[node],parent);
    }

    void unionf(int curr,int neigh,vector<int> &parent,vector<int> &rank){

        int p_curr=findp(curr,parent);
        int p_neigh=findp(neigh,parent);


        if(p_curr==p_neigh){
            return;
        }
        if(rank[p_curr]==rank[p_neigh]){
            parent[p_neigh]=p_curr;
            rank[p_curr]++;
        }

        else if(rank[p_curr]>rank[p_neigh]){
            parent[p_neigh]=p_curr;
        }
        else{
            parent[p_curr]=p_neigh;
        }



    }


public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int> parent(n*n);
        vector<int> rank(n*n,0);

        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }

        vector<pair<int,int>> cells;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cells.push_back({grid[i][j],(i*n)+j});
            }
        }

        sort(cells.begin(),cells.end());
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        vector<bool> active(cells.size(),false);
        int ptr=0;
        for(int t=0;t<n*n;t++){
            while(ptr<n*n && cells[ptr].first<=t){

                int node=cells[ptr].second;

                active[node]=true;
                int r=node/n;
                int c=node%n;

                for(int i=0;i<4;i++){
                    int nx=r+dx[i];
                    int ny=c+dy[i];

                    int neigh=(nx*n)+ny;


                    if(nx<0 || ny<0 || nx>=n || ny>=n ){
                        continue;
                    }

                    if(active[neigh]){
                        unionf(node,neigh,parent,rank);
                        
                    }
                   


                }


                ptr++;


            }

            

                if(findp(0,parent) == findp(n*n-1,parent)){
                    return t;
                }



        }

    return 0;



    }
};