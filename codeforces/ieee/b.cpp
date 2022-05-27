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

template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}

/*
DEBUG: -D LOCAL
debug() << imie(k) imie(x) imie(row) imie(col);
*/

const int INF = 1e9 + 5, N = 100;
vi G[N + 5];
vll dist(N + 5, INF);
int n, m;

int ask(int myIndex) {
  cout << myIndex << en;
  cout.flush();

  int opponentIndex;
  cin >> opponentIndex;
  return opponentIndex;
}

int getNextMove(int src, int dst) {
  int minNode = src;
  int minWeight = weight[src][dst];
  for (int i = 0; i < (int)edges[src].size(); i++) {
    if (minWeight >= weight[edges[src][i]][dst]) {
      minWeight = weight[edges[src][i]][dst];
      minNode = edges[src][i];
    }
  }
  return minNode;
}

int bfs(int opponentIdx, int myIdx) {
  queue<int> q;
  vll dist(n + 5, INF);
  dist[opponentIdx] = 0;
  q.push(opponentIdx);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : G[u]) {
      int newDist = dist[u] + 1;
      if (newDist < dist[v]) {
        dist[v] = newDist;
        q.push(v);
      }
    }
  }

  int nextIdx = myIdx;
  int nextDist = INF;

  for (auto i : G[myIdx]) {
    if (i != myIdx) {
      if (dist[i] < nextDist) {
        nextDist = dist[i];
        nextIdx = i;
      }
    }
  }

  return nextIdx;
}

int getStart() {
  int nodeWithMaxEdge = 1;
  int edgeCount = (int)G[1].size();
  for (int i = 2; i <= n; i++) {
    if (edgeCount < (int)G[i].size()) {
      edgeCount = (int)G[i].size();
      nodeWithMaxEdge = i;
    }
  }
  return nodeWithMaxEdge;
}

int main() {
  fast;
  cin >> n >> m;

  FOR(m) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  int myIdx = getStart(), opponentIdx = -1;

  while (opponentIdx != myIdx) {
    opponentIdx = ask(myIdx);
    if (opponentIdx == myIdx) break;
    myIdx = bfs(opponentIdx, myIdx);
  }
  cout << myIdx;
}