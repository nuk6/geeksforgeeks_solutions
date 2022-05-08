// Problem : https://leetcode.com/problems/jump-game-ii/submissions/
int dp[10001];
class Solution {
public:
    int jump(vector<int>& v) {
        if(v.size() == 1) return 0;
        queue<int> q;
	q.push(0);
	int mx = -1;
	while(!q.empty()) {
		int c = q.front(); q.pop();
		for(int i = 1; i <= v[c]; ++i) {
			if(c+i < v.size()-1 && c+i > mx)
			{
				q.push(c+i);
				dp[c+i] = dp[c]+1;
				mx = max(mx, c+i);
			}
			else if (c+i >= v.size()-1){
				return dp[c]+1;
			}
		}
	}
	return -1;
    }
};
