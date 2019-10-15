
// Q: https://leetcode.com/problems/total-hamming-distance/submissions/

class Solution {
public:
    int totalHammingDistance(vector<int>& a){
        int bit[32];
        int n = a.size();
        for(int i = 0; i < 32; ++i) bit[i] = 0;
        for(int i = 0; i < n; ++i){
            int x = a[i];
            for(int i = 0; i < 32; ++i){
                bit[i] += (x&1);
                x >>= 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            ans += (bit[i])*(n-bit[i]);
        }
        return ans;
    }
};
