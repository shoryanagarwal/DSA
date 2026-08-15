class Solution {
private:


    int findp(int node ,vector<int> &parent){

        if(node==parent[node]){
            return node;
        }
        return parent[node]=findp(parent[node],parent);
    }

    void unionf(int prev,int curr,vector<int> &parent,vector<int> &rank){

        int parent_prev=findp(prev,parent);
        int parent_curr=findp(curr,parent);

        if(parent_prev==parent_curr){
            return;
        }
        if(rank[parent_prev]==rank[parent_curr]){
            parent[parent_prev]=parent_curr;
            rank[parent_curr]++;
        }
        else if(rank[parent_prev]<rank[parent_curr]){
             parent[parent_prev]=parent_curr;
        }
        else{
             parent[parent_curr]=parent_prev;
        }




    }

    
public:
    int largestIsland(vector<vector<int>>& grid) {


        
       
        int n=grid.size();
        int count=0;
        for(int i=0;i<n*n;i++){
            if(grid[i/n][i%n]==1){
                count++;
            }
        }

        if(count==n*n){
            return n*n;
        }

        vector<int> parent(n*n);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        vector<int> rank(n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    // checking all four directions for getting one or not
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];

                        if(nx<0 || ny<0 || nx>=n || ny>=n || grid[nx][ny]==0){
                            continue;
                        }
                        int prev=(i*n)+j;
                        int curr=(nx*n)+ny;

                        unionf(prev,curr,parent,rank);
                        
                    }

                }
            }
        }


        unordered_map<int,int> component;

        for(int i=0;i<n*n;i++){
            if(grid[i/n][i%n]==1){

                int index=findp(i,parent);

                component[index]++;

            }
        }

        int maxi=0;
       
        for(int i=0;i<n*n;i++){
        
            if(grid[i/n][i%n]==0){
                set<int> st;
                
                // charo direction mai traverse karp
                for(int j=0;j<4;j++){
                    int nx=(i/n)+dx[j];
                    int ny=(i%n)+dy[j];

                    if(nx<0 || ny<0 || nx>=n || ny>=n || grid[nx][ny]==0){
                        continue;
                    }
                    int neighbour=(nx*n)+ny;
                    int root=findp(neighbour,parent);
                    if(st.find(root)==st.end()){
                        st.insert(root);
                    }
                    

                }

                int ans=1;
                for(auto value:st){
                    ans+=component[value];
                }
                maxi=max(ans,maxi);

            }
        }



        return maxi;

    }
};