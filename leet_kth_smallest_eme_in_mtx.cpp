// P : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    // Returns the idx just greater & returns the idx less or equal
int searchRow(const vector<vector<int>>& mtx, int row, int target) {
	int cols = mtx[0].size();
	int l = 0, h = cols-1, mid;
	while(l < h) {
		mid = (l+h) >> 1;
		if(mtx[row][mid] > target) {
			h = mid;
		} else {
			l = mid+1;
		}
	}
	if(mtx[row][h] < target) return cols;
	return h-(mtx[row][h] != target);
}

int searchCol(const vector<vector<int>>& mtx, int col, int target) {
	int rows = mtx.size();
	int l = 0,h = rows-1, mid;
	while(l < h) {
		mid = (l+h) >> 1;
		if(mtx[mid][col] > target) {
			h = mid;
		} else {
			l = mid+1;
		}
	}
	if(mtx[h][col] < target) return rows;
	return h - (mtx[h][col] != target);
}

int elems_less_than_or_equal_to_target(const vector<vector<int>>& mtx, int target) {
	int rows = mtx.size(), cols = mtx[0].size();
	int c1 = min(cols-1, searchRow(mtx, 0, target));
	int r1 = min(rows-1, searchCol(mtx, c1, target));
	int r2 = min(rows-1, searchCol(mtx, 0, target));
	int c2 = min(cols-1, searchRow(mtx, r2, target));
	//cout << "Printing..." << r1 << c1 << r2 << c2 << endl;
	int cnt = (r1+1)*(c1+1);
	for(int i = r1 + 1; i <= r2; ++i) {
		cnt += searchRow(mtx, i, target)  + 1;
	}
	return cnt;
}
    int kth_smallest_element(const vector<vector<int>>& mtx, int k) {
	int m = mtx.size(), n = mtx[0].size(), l = mtx[0][0], h = mtx[m-1][n-1], mid, ans;
	while(l <= h) {
		mid = (l+h) >> 1;
		if(elems_less_than_or_equal_to_target(mtx, mid) >= k) {
			ans = mid;
			h = mid-1;
		} else {
			l = mid+1;
		}
	}
	return ans;
}
    int kthSmallest(vector<vector<int>>& mtx, int k) {
        return kth_smallest_element(mtx, k);
    }
};
