
// Q: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string> > adj;
        vector<vector<string> > ans;
        vector<string> tem;
        for(string i : str){
            string t = i;
            sort(t.begin(),t.end());
            adj[t].push_back(i);
        }
        for(auto it : adj){
            for(auto it2 : adj[it.first]){
                tem.push_back(it2);
            }
            ans.push_back(tem);
            tem.clear();
        }
        return ans;
}
};
