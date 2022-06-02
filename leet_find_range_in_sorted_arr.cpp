// Problem : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    
using cvi = const vector<int>&;
using pii = pair<int,int>;

pii anss{-1,-1};

pii find(cvi v, int t, bool leftMost = true) {
		cout << "Heyyyy" << endl;
		int n = v.size();
		int l = 0, r = n-1;
		int mid;
		while(l <= r && (l < n && r >= 0)) {
			mid = (l+r)/2;
			if(v[mid] > t) {
				r = mid-1;
			} else if(v[mid] < t) {
				l = mid+1;
			} else {
				cout << "Here\n";
				if((leftMost && (mid == 0 || v[mid] != v[mid-1])) || (!leftMost && (mid == n-1|| v[mid] != v[mid+1]))) {
					if(leftMost) {
						anss.first = mid;
					} else {
						anss.second = mid;
					}
					break;
				} else {
					if(leftMost) r = mid-1;
					else l = mid+1;
				}
			}
		}
	return anss;
}
    vector<int> searchRange(vector<int>& v, int t) {
        pii ans;
	    //vector<int> v{2,2,2,8};
	    find(v,t);
	    ans = find(v,t, false);
        return {ans.first, ans.second};
    }
};
