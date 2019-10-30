
// Q: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int cnt[7];
        for(int i = 0; i < 7; ++i) cnt[i] = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] != b[i]){
                cnt[a[i]]++;
                cnt[b[i]]++;
            } else {
                cnt[a[i]]++;
            }
        }
        int f = 0, n0;
        for(int i = 1; i <= 6; ++i){
            if(cnt[i] == n) {f = 1;n0 = i;}
        }
        if(!f) return -1;
        int cta = 0,ctb = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == n0) cta++;
            if(b[i] == n0) ctb++;
        }
        return n-max(cta,ctb);
    }
};
