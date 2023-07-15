
// Given an array of integers, find the maximum number of pairs with the same sum.
// Input: arr[] = {3, 4, 2, 6, 7}
// Output: 2
// Explanation: The maximum number of pairs with sum 9 is 2.
// The pairs are:
// (3, 6) and (4, 5)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mp1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mp1[(arr[i] + arr[j])]++;
        }
    }
    int maxi = 0, sum = 0;
    for (auto it : mp1)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
            sum = it.first;
        }
    }
    // cout<<sum<<" ";
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(sum - arr[i]) != mp.end())
        {
            a++;
            mp[sum - arr[i]]--;
            if (mp[sum - arr[i]] == 0)
            {
                mp.erase(sum - arr[i]);
            }
        }
        else
        {
            mp[arr[i]]++;
        }
    }

    cout << a << endl;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int count_pairs(vector<int> &arr, int target)
// {
//     int ans = 0;
//     int low = 0, high = arr.size() - 1;
//     while (low < high)
//     {
//         int curr = arr[low] + arr[high];
//         if (curr == target)
//         {
//             ans++;
//             low++;
//             high--;
//         }
//         else if (curr > target)
//             high--;
//         else
//             low++;
//     }
//     return ans;
// }
// void solve()
// {
//     long long n;
//     cin >> n;
//     vector<int> arr(n);
//     for (auto &it : arr)
//         cin >> it;

//     int ans = 0;
//     sort(arr.begin(), arr.end());

//     unordered_set<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             st.insert(arr[i] + arr[j]);
//         }
//     }
//     for (auto it : st)
//     {
//         int target = it;
//         ans = max(ans, count_pairs(arr, target));
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }