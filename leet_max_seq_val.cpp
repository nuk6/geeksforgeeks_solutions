#include <bits/stdc++.h>
using namespace std;

int dp[10][5][128];

/*
dp[i][k][x] = dp[i-1][k][x] + fore(v(0,128), dp[i-1][k-1][(v|a[i])] , st v|a[i] == x)
*/

void compute(const vector<int>& a, int K) {
  int n = a.size();
  for(int i = 0; i < n; ++i) {
    for(int k = 1; k <= min(i+1, K); ++k) {
      for(int x = 0; x < 129; ++x) {
          if (k == 1) {
            dp[i][1][x] = (a[i] == x) + ((i > 0) ? dp[i-1][1][x] : 0);
          } else {
            dp[i][k][x] = dp[i-1][k][x];
            dp[i][k][(x|a[i])] += dp[i-1][k-1][x];
          }
      }
    }
  }
}



int main() {
  vector<int> a{6,6,6,5,4};
  compute(a, 2);
  cout << dp[2][2][6] << endl;
  return 0;
}
