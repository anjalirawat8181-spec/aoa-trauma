#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = 4;

    int dp[n][n];

    for(int i=1;i<n;i++)
        dp[i][i]=0;

    for(int len=2;len<n;len++) {
        for(int i=1;i<n-len+1;i++) {
            int j=i+len-1;
            dp[i][j]=INT_MAX;

            for(int k=i;k<j;k++) {
                int cost = dp[i][k] + dp[k+1][j]
                         + arr[i-1]*arr[k]*arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout<<"Minimum Multiplications = "<<dp[1][n-1];
}