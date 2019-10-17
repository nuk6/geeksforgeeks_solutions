
// Q: https://leetcode.com/problems/find-the-duplicate-number/submissions/

class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size()-1;
        int ans = -1;
        for (size_t i = 0; i <= n; i++)
        {
        if(v[abs(v[i])-1] < 0) ans = abs(v[i]);
        if(v[abs(v[i])-1] > 0) v[abs(v[i])-1] *= -1;
        }
        return ans;
    }
};
