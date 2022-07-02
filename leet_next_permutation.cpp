// P : https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
    void nextPermutation(vector<int>& a) {
	int n = a.size();
	int i = n-2;
	while((i != -1) && a[i] >= a[i+1]) {
		i--;
	}
	int j = n-1;
	while((i != -1) && (j != -1) && a[j] <= a[i]) {
		j--;
	}
	if((i != -1) && (j != -1))
	{
		swap(a[i], a[j]);
	}
    int k = 0;
	for(int it = i+1; it <= (int)((n+i)/2); ++it) {
		swap(a[it], a[n-k-1]);
        k++;
	}
    }
};
