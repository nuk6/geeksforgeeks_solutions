// P : https://leetcode.com/problems/integer-replacement/
class Solution {
public:
    long get2s(long n) {
	long t = 0;
	while((n%2 == 0)) {
		n /= 2;
		t++;
	}
	return t;
}
    long solve(long n) {
        long steps = 0;
	    while(n > 1) {
            if(n%2) {
			if(get2s(n-1) >= get2s(n+1) || n == 3) {
				n -= 1;
			} else {
				n += 1;
			}
		} else {
			n /= 2;
		}
		cout << "N = " << n << endl;
		steps++;
	}
        return steps;
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};
