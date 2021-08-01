#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
using namespace __detail;

int bitmask;
char *characters;
int characters_count;
char *running;
int running_count;

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
void permutations() {
  int i;
  if (running_count == characters_count) {
    printf("%s\n", running);
  } else {
    for (i = 0; i < characters_count; i++) {
      if (((bitmask >> i) & 1) == 0) {
        running[running_count] = characters[i];
        bitmask |= (1 << i);
        running_count = running_count + 1;
        permutations();
        bitmask &= ~(1 << i);
        running_count = running_count - 1;
      }
    }
  }
}

main() {
  int i;
  int cases;
  // freopen("in8.in", "r", stdin);
  freopen("out8.txt", "w", stdout);

  characters = (char *)malloc(sizeof(char) * 30);
  scanf("%s", characters);
  characters_count = strlen(characters);

  running = (char *)malloc(sizeof(char) * 30);
  memset(running, 0, 30);
  running_count = 0;

  permutations();

  free(characters);
  free(running);
}