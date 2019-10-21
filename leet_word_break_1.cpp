
// Q: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, const vector<string>& words){
    unordered_set<string> pres(words.begin(),words.end());
    int n = s.size();bool b;
    bool dp[n][n];
    memset(dp,0,sizeof(dp));    
    for (size_t i = 0; i < n; i++)
    {
        dp[i][i] = pres.find(s.substr(i,1)) != pres.end();
    }
    for (int l = 2; l <= n; l++)
    {
        for(int i = 0; i+l-1 < n; ++i){
            bool b = pres.find(s.substr(i,l)) != pres.end();
            for(int j = i; j < (i+l-1); ++j){
                bool b1 = dp[i][j] && dp[j+1][i+l-1];
                b = (b||b1);
            }
            dp[i][i+l-1] = b;
        }
    }
    return dp[0][n-1];
    }
};
