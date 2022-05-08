// Problem : https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& v) {
        if(v.size() == 1) return true;
        queue<int> q;
	q.push(0);
	int mx = -1;
	while(!q.empty()) {
		int c = q.front(); q.pop();
		for(int i = 1; i <= v[c]; ++i) {
			if(c+i < v.size()-1 && c+i > mx)
			{
				q.push(c+i);
				mx = max(mx, c+i);
			}
			else if (c+i >= v.size()-1){
				return true;
			}
		}
	}
	return false;
    }
};
