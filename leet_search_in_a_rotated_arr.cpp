// Problem : https://leetcode.com/problems/search-in-rotated-sorted-array/
using cvi = const vector<int>&;
class Solution {
public:
    int bSearch(cvi a, int t, int l, int r) {
	int mid = -1;
	while(l <= r) {
		mid = (l+r)/2;
		if(a[mid] < t) {
			l = mid+1;
		} else if(a[mid] > t) {
			r = mid-1;
		} else if(a[mid] == t) {
			return mid;
		}
	}
	return -1;
}
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
int getMaxIdx(cvi a, int target) {
	int idx = getMaxIndex(a);
	int n = a.size();
	if(target > a[idx] || target < a[(idx+1)%n]) return -1;
	if(target >= a[0] && target <= a[idx]) return bSearch(a,target,0,idx);
	return bSearch(a,target, ((idx+1)%n), n-1);
}
    int search(vector<int>& nums, int target) {
        return getMaxIdx(nums, target);
    }
};
