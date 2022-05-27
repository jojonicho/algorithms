#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define vt vector
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
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
#define dor > dbg &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, dbg &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct dbg {
#ifdef LOCAL
  ~dbg() { cerr << endl; }
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
};

#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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
dbg() << imie(k) imie(x) imie(row) imie(col);
*/

const string NO = "IMPOSSIBLE";

int n;

void solve() {
  cin >> n;
  vt<string> S(n);

  vi ends(26, -1), starts(26, -1);

  vt<vt<int>> mono(26, vt<int>()); // indeces where s.back() == s.front()
  bool earlyFlag = 0;

  FOR(n) {
    string s;
    cin >> s;
    S[i] = s;

    if(earlyFlag)
      continue;

    int u = s.front() - 'A', v = s.back() - 'A';

    vt<bool> vis(26);
    FOR(j, sz(s)) {
      char c = s[j];
      if(j && s[j] != s[j-1] && vis[c-'A'])
        earlyFlag = 1;
      vis[c-'A'] = 1;
    }

    bool isMono = accumulate(all(vis), 0) == 1;
    if(isMono) {
      mono[u].pb(i);
      continue;
    }

    if(ends[v] != -1 || starts[u] != -1) {
      earlyFlag = 1;
      continue;
    }

    ends[v] = i;
    starts[u] = i;
    //dbg() << im(s.front()) im(s.back()) im(u) im(v) im(starts[u]) im(ends[v]);
  }

  if(earlyFlag) {
    cout << NO << en;
    return;
  }

  //dbg() << im(mono);
  //dbg() << im(ends) im(starts);

  queue<int> q;

  string ans = "";
  vt<bool> vis(n);

  auto extract = [&](int c) {
    while(!mono[c].empty()) {
      int idx = mono[c].back();
      mono[c].pop_back();
      ans += S[idx];
      vis[idx] = 1;
    }
  };

  auto bfs = [&]() {
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(vis[u])
        continue;
      vis[u] = 1;

      int c= S[u].front() - 'A';
      extract(c);

      ans += S[u];

      int d = S[u].back() - 'A';
      extract(d);

      int v = starts[d];
      if(v == -1)
        continue;
      q.push(v);
    }
  };

  FOR(26) {
    if(ends[i] == -1 && starts[i] != -1) {
      int idx = starts[i];
      if(vis[idx])
        continue;
      q.push(idx);
      bfs();
    }
  }

  FOR(n) {
    if(!vis[i]) {
      ans += S[i];
      vis[i] = 1;
    }
  }

  bool flag = 0;

  vt<bool> charVis(26);
  for(int i=0; i<sz(ans); i++) {
    int c = ans[i] - 'A';
    if(i && ans[i-1] != ans[i] && charVis[c])
      flag = 1;
    charVis[c] = 1;
  }

  if(flag) {
    cout << NO << en;
    return;
  }

  cout << ans << en;
}

int main() {
  fast;
  int t; cin >> t;
  FOR(t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

