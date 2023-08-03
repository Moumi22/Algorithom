#include <iostream>
#include <cstring>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n+1][W+1];

    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int val[] = {3,4,5,1};
    int wt[] = {6,2,5,4};
    int W = 9;
    int n = sizeof(val)/sizeof(val[0]);
    cout << "Maximum value that can be obtained is: " << knapsack(W, wt, val, n);
    return 0;
}

