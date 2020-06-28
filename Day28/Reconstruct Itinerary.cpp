class Solution {
public:
    void find(map<string,vector<string>> &adj,string curr,vector<string> &res)
    {    
        
        for(int i=0;i<adj[curr].size();i++)
        {
            string x=adj[curr][i];
            adj[curr].erase(adj[curr].begin()+i);i--;
            find(adj,x,res);
        }
        res.push_back(curr);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        int l=tickets.size();
        map<string,vector<string>> adj; 
        for(int i=0;i<l;i++)
         adj[tickets[i][0]].push_back(tickets[i][1]); 
        for(auto x=adj.begin();x!=adj.end();x++)
          sort(x->second.begin(),x->second.end());
        
        find(adj,"JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }
};
