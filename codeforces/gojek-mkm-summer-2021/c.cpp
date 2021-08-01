#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back

#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);
#define F_OR(i, a, b, s) \
  for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)     \
  F_ORC(__VA_ARGS__) \
  (__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)     \
  E_ACHC(__VA_ARGS__) \
  (__VA_ARGS__)

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) cerr << boolalpha << i;
  ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c &) { ris; }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y <<
// ")"; return dd; }

/*
You are presented with a map of a kingdom. Empty land on this map is depicted as
‘.’ (without the quotes), and mountains are depicted by ‘#’. This kingdom has
factions whose armies are represented by lowercase letters in the map. Two
armies of the same letter belong to the same faction.

Armies can go up, down, left, and right, but cannot travel through mountains. A
region is an area enclosed by mountains. From this it can be deduced that armies
cannot travel between different regions. A region is said to be controlled by a
faction if it’s the only faction with an army in that region. If there are at
least two armies from different factions in a region, then that region is said
to be contested. Your task is to determine how many regions each faction
controls and how many contested regions there are.

Input:

The first line is the number of test cases T. Each test case will have two
numbers N and M, each on their own line given in that order. Following that is N
lines of M characters that represent the map.

Output:

For each test case, output one line of the form “Case C:” (without the quotes),
where C is the case number (starting from 1). On the following lines, output the
factions that appear in the grid in alphabetical order if the faction controls
at least one region and how many regions that letter controls. Factions that
don’t control any regions should not be in the output. After this, print one
last line of the form “contested K” where K is the number of regions that
contain at least two distinct letters.

See the sample output below for details.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ M ≤ 100

Sample Input:

2
2
2
.#
#a
12
15
###########....
#.......c.###..
####......#.#..
.#.########.#..
##...#..b#..#..
#.a.#...#...###
####.#.#d###..#
......#...e#xx#
.#....#########
.#.x..#..#.....
.######.c#.....
......####.....
Sample Output:

Case 1:
a 1
contested 0
Case 2:
a 1
b 1
c 2
x 2
contested 1
*/

const int N = 100;
const char MOUNTAIN = '#', LAND = '.';
const int dir[5] = {0, 1, 0, -1, 0};

bool vis[N][N];
string S[N];
set<char> letters;
int n, m;

void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || S[i][j] == MOUNTAIN)
    return;
  vis[i][j] = 1;
  char c = S[i][j];
  if (c != LAND) letters.insert(c);
  for (int k = 0; k < 4; k++) {
    int r = i + dir[k], c = j + dir[k + 1];
    dfs(r, c);
  }
}

void solve() {
  memset(vis, 0, sizeof(vis));
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  ll contested = 0;

  map<char, int> mp;
  FOR(n) {
    FOR(j, m) {
      if (vis[i][j]) continue;
      letters.clear();
      dfs(i, j);

      int sz = letters.size();
      if (sz == 0) {
        continue;
      } else if (sz == 1) {
        char c = *letters.begin();
        mp[c]++;
      } else {
        contested++;
      }
    }
  }
  for (auto &[x, y] : mp) {
    cout << x << " " << y << en;
  }
  cout << "contested " << contested << en;
}

int main() {
  fast;
  freopen("in3-3.in", "r", stdin);
  freopen("out3-3.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": " << en;
    solve();
  }
}