
// Q: https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

#include<bits/stdc++.h>
using namespace std;
int t,n,a[10000001];
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        int l = 0, r = n-1, ml = 0, mr = 0,ans = 0;
        while(l <=r){
            if(a[l] < a[r]){
                if(a[l] > ml){
                    ml = a[l];
                } else {
                    ans += ml-a[l];
                    l++;
                }
            } else {
                if(a[r] > mr) mr = a[r];
                else {
                    ans += mr-a[r];
                    r--;
                }
            }
        }
        cout << ans << endl;
    }
	return 0;
}
