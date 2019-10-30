
// Q: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

#include<bits/stdc++.h>
using namespace std;

int dp[11][51];

int efTopDown(int K, int N){
    if(dp[K][N] != -1) return dp[K][N];
    if(K == 0 || N == 0) return 0;
    if(K == 1 || N == 1) return N;
    int ans = INT_MAX;
    for(int x = 2; x <= N; ++x){
        ans = min(ans, 1+(max(efTopDown(K,N-x),efTopDown(K-1,x-1))));
    }
    return dp[K][N] = ans;
}

int main()
{
    int t,N,K;
    cin >> t;
    while(t--){
        cin >> K >> N;
        memset(dp,-1,sizeof(dp));
        cout << efTopDown(K,N) << endl;
    }
	return 0;
}
