#include<bits/stdc++.h>
using namespace std;


int numOfWays(int srcX, int srcY, int n, int dp[][100]) {
  if(srcX == n-1 && srcY == n-1)
    return 1;

  if(dp[srcX][srcY] != -1)
    return dp[srcX][srcY];
  int ways = 0;
  if(srcX + 1 <= srcY)
    ways += numOfWays(srcX+1, srcY, n, dp);
  if(srcY + 1 < n)
    ways += numOfWays(srcX, srcY+1, n, dp);

  return dp[srcX][srcY] = ways;
}
int numOfPathsToDest( int n )
{
  int dp[100][100];
  memset(dp, -1, sizeof(dp));
  return numOfWays(0, 0, n, dp);
}

int main() {
    int n;
    cin>>n;
    cout<<numOfPathsToDest(n);
  return 0;
}
