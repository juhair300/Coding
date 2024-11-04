#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
const int N = 1e6 + 10;
int n;
ll m;
ll trees[N];

bool iswoodSufficient(int h)
{
    ll wood = 0;
    for (int i = 0; i < n; ++i)
    {
        if (trees[i] >= h)
        {
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    ll lo = 0, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (iswoodSufficient(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (iswoodSufficient(hi))
    {
        cout << hi << nl;
    }
    else
    {
        cout << lo << nl;
    }
    // TC : O(nlog(trees[max]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}