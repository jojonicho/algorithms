#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define fork(i, n) for (ll i = 0; i < (n); i++)
#define forn for (ll i = 0; i < (n); i++)
#define fori(i, k, n) for (ll i = k; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

template <typename T>
void print(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << en;
}

vector<int> sumToN(vector<int> nums, int target)
{
    map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = mp.find(nums[i]);
        if (it != mp.end())
        {
            ans.push_back(it->second);
            ans.push_back(i);
            return ans;
        }
        mp[target - nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> samp = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sumToN(samp, target);
    print(ans);
}