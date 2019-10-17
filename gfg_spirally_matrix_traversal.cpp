
// Q: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0

#include<bits/stdc++.h>
using namespace std;
int t,n,m,arr[11][11];
int main()
{
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i = 0;i < m; ++i) for(int j = 0; j < n; ++j) cin >> arr[i][j];
        int a = 0,b = n-1,c = m-1, d = 0;
        while(1)
        {
        for(int i = d; i <= b; ++i) cout << arr[a][i] << " "; a++;
        if(a > c) break;
        for(int i = a; i <= c; ++i) cout << arr[i][b] << " "; b--;
        if(d > b) break;
        for(int i = b; i >= d; --i) cout << arr[c][i] << " "; c--;
        if(a > c) break;
        for(int i = c; i >= a; --i) cout << arr[i][d] << " "; d++;
        if(d > b) break;
        }
        cout << endl;
        }
	return 0;
}
