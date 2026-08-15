class Solution {

   

int findp(vector<int> &parent,int node){

    if(parent[node]==node){
        return node;
    }

    return parent[node]=findp(parent,parent[node]);

}



void unionf(int prev,int curr,vector<int> &parent,vector<int> &rank){


    int  parent_prev=findp(parent,prev);
    int  parent_curr=findp(parent,curr);

    if(parent_prev==parent_curr){
        return;
    } 
    if(rank[parent_prev]==rank[parent_curr]){
        parent[parent_prev]=parent_curr;
        rank[parent_curr]++;
    }
    else if(rank[parent_prev]>rank[parent_curr]){
        parent[parent_curr]=parent_prev;
    }
    else{
        parent[parent_prev]=parent_curr;
    }



}


public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        vector<int> parent(accounts.size());
        vector<int> rank(accounts.size(),0);

        for(int i=0;i<accounts.size();i++){
            parent[i]=i;
        }

        for(int i=0;i<accounts.size();i++){
            vector<string> s=accounts[i];
            for(int j=1;j<s.size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    
                    int prev=mp[accounts[i][j]];
                    unionf(prev,i,parent,rank);

                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }


        vector<vector<string>> ans;
        unordered_map<int,vector<string>> group;

        for(auto i:mp){
            string email=i.first;
            int index=i.second;
            int p=findp(parent,index);

            group[p].push_back(email);
        }

        for(auto i:group){
            int index=i.first;
            vector<string> e=i.second;

            sort(e.begin(),e.end());
            vector<string> temp;
            temp.push_back(accounts[index][0]);

            for(int j=0;j<e.size();j++){
                temp.push_back(e[j]);

            }


            ans.push_back(temp);
            
        }


        return ans;
    }
};