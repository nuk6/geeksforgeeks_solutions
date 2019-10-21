
// Q: https://leetcode.com/problems/two-sum/

#define f first
#define s second
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        vector<pair<int,int>> v;
        int n = a.size();
        for(int i = 0; i < n; ++i){
            v.push_back(make_pair(a[i],i));
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        int l = 0, r = n-1;
        while(l < r){
            if(v[l].f+v[r].f < t) l++;
            else if(v[l].f+v[r].f>t) r--;
            else{
                ans.push_back(v[l].s);
                ans.push_back(v[r].s);
                break;
            }
        }
        return ans;
    }
};
