// Problem : https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double n, long p) {
	if(p < 0) return myPow(1/n, -1*p);
	if(p == 0) return 1;
	if(p%2) {
		//cout << "N = " << n << endl;
		return n * myPow(n,p-1);
	} else {
		double x = myPow(n, p/2);
		return x*x;
	}
}
};
