// P : https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
using vi = vector<int>;
using cvi = const vi&;
class Solution {
public:
    int solve(cvi a) {
	int n = a.size();
	int l[n],r[n];
	for(int i = 0; i < n; ++i) {
		l[i] = (i==0)?a[i] : max(a[i], l[i-1]);
		r[n-i-1] = (i==0)?a[n-i-1] : min(a[n-i-1], r[n-i]);
	}
	int chunks = 0;
	for(int i = 0; i < n-1; ++i) {
		if(l[i] <= r[i+1]) {
			chunks++;
		}
	}
	return chunks+1;
}
    int maxChunksToSorted(vector<int>& arr) {
       return solve(arr); 
    }
};
