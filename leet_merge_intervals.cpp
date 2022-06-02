// P : https://leetcode.com/problems/merge-intervals/submissions/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& data) {
        unordered_map<int,int> add, left;
	int mx = INT_MIN, mn = INT_MAX;
	for(auto it: data) {
		add[it[0]]++;
		left[it[1]]++;
		mn = min(mn, it[0]);
		mx = max(mx, it[1]);
	}
	vector<vector<int>> merged;
	int counter = 0;
	int considering = 636;
	for(int i = mn; i <= mx; ++i) {
		if(add[i]) {
			if(counter == 0) {
				considering = i;
			}
			counter += add[i];
		} 
		if(left[i]) {
			counter -= left[i];
			if(counter == 0) {
				merged.push_back({considering, i});
			}
		}
	}
      return merged;  
    }
};
