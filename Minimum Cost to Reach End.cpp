#include <bits/stdc++.h>
using namespace std;
int minimumCost(vector<int> &arr, int n, int k)
{
    // Write your code here.
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= max(0, i - k); j--)
        {
            dp[i] = min(dp[i], abs(arr[i] - arr[j]) + dp[j]);
        }
    }
    return dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minimumCost(arr, n, k) << endl;
    return 0;
}