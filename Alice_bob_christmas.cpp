#include <bits/stdc++.h>
using namespace std;
int n;
int solution(vector<int> &a, vector<int> &b)
{
    vector<int> odda, oddb, evena, evenb;
    int odd = 0, even = 0, sum = 0, n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
        {
            odda.push_back(a[i]);
            odd++;
        }
        else
        {
            evena.push_back(a[i]);
            even++;
        }
        if (b[i] & 1)
        {
            oddb.push_back(b[i]);
            odd--;
        }
        else
        {
            evenb.push_back(b[i]);
            even--;
        }
        sum += a[i] - b[i];
    }
    if (sum != 0 || even != 0 || odd != 0)
        return -1;
    sort(odda.begin(), odda.end());
    sort(oddb.begin(), oddb.end());
    sort(evena.begin(), evena.end());
    sort(evenb.begin(), evenb.end());
    int op = 0;
    for (int i = 0; i < odda.size(); i++)
    {
        if (odda[i] > oddb[i])
            op += (odda[i] - oddb[i]) / 2;
    }
    for (int i = 0; i < evena.size(); i++)
    {
        if (evena[i] > evenb[i])
            op += (evena[i] - evenb[i]) / 2;
    }
    return op;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cout << solution(a, b) << endl;
    }
    return 0;
}
