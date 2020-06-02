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

template <typename A, typename B>
inline void chmin(A &a, B b)
{
    if (a > b)
        a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b)
{
    if (a < b)
        a = b;
}
template <typename T>
void print(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << en;
}
template <typename T>
void print(deque<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << en;
}
template <typename T>
void print(vector<vector<T>> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
            cout << a[i][j] << ' ';
        cout << en;
    }
}

bool palindrom(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int sum = 0;
    while (x > sum)
    {
        sum *= 10;
        sum += x % 10;
        x /= 10;
    }
    return (x == sum) || (x == sum / 10);
}

int main()
{
    int target = 101;
    bool ans = palindrom(target);
    cout << ans << en;
}