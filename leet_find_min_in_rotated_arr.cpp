// Problem : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
using cvi = const vector<int>&;
class Solution {
public:
    int getMaxIndex(cvi a) {
	int n = a.size();
	int l = 0, r = n-1, mid;
	while(l <= r) {
		mid = (l+r)/2;
		if(a[l] < a[mid]) {
			l = mid;
		} else if(a[l] > a[mid]) {
			r = mid-1;
		} else if(l == mid) {
			return (a[l] > a[r]) ? l : r;
		}
	}
	return mid;
}
    int findMin(vector<int>& nums) {
        int idx = getMaxIndex(nums);
        int n = nums.size();
        return nums[(idx+1)%n];
    }
};
