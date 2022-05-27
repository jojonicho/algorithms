#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

Point iron;
int monster;
vector<Point> monsters;
int k;
vector<pair<Point, Point>> segments;

bool onSegment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;

  return false;
}

int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0) return 0;

  return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
  // cout << "Cek dengan segment (" << p2.x << ", " << p2.y << ") dan (" << q2.x
  // << ", " << q2.y << ") " << endl;
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  // General case
  if (o1 != o2 && o3 != o4) return true;

  // cout << "Lolos orientasi!" << endl;
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;

  if (o2 == 0 && onSegment(p1, q2, q1)) return true;

  if (o3 == 0 && onSegment(p2, p1, q2)) return true;

  if (o4 == 0 && onSegment(p2, q1, q2)) return true;

  return false;
}

void input() {
  cin >> iron.x >> iron.y;
  cin >> monster;
  for (int i = 1; i <= monster; i++) {
    Point newMonster;
    cin >> newMonster.x >> newMonster.y;
    monsters.push_back(newMonster);
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    Point p, q;
    cin >> p.x >> p.y >> q.x >> q.y;
    segments.push_back(make_pair(p, q));
  }
}

void solve() {
  int ans = 0;
  for (int i = 0; i < monsters.size(); i++) {
    Point posisiMonster = monsters[i];

    // cout << "Mengecek ultron ke " << i << endl;
    // cout << "Di (" << posisiMonster.x << ", " << posisiMonster.y << ")" <<
    // endl;
    bool isTidakAdaPenghalang = true;
    for (int j = 0; j < segments.size(); j++) {
      Point segmentStart = segments[j].first;
      Point segmentEnd = segments[j].second;

      if (doIntersect(iron, posisiMonster, segmentStart, segmentEnd)) {
        isTidakAdaPenghalang = false;
        break;
      }
    }
    if (isTidakAdaPenghalang) {
      // cout << "Tidak ada penghalang!" << endl;
      ans++;
    }
    // cout << endl;
  }
  cout << ans << endl;
}

int main() {
  input();
  solve();
}