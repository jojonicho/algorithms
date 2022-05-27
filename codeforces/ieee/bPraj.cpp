#include <bits/stdc++.h>

using namespace std;

// functions used to comunicate with the interactor (the other program)
// use this to get the position of the other player.
// after using it you must do your own move
// TL;DR GetBlack() GetBlack() is invalid
int GetBlack() {
  int black_king_node;
  cin >> black_king_node;
  return black_king_node;
}

// use this to set your own move
void SetWhite(int node) { cout << node << endl; }

int n, m;

vector<int> edges[105];
int weight[105][105];

void ReadGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; i += 1) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
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

void getWeight(int start) {
  queue<pair<int, int>> q;
  q.push(make_pair(start, 0));
  int visited[105];
  memset(visited, 0, sizeof(visited));
  while (!q.empty()) {
    pair<int, int> now = q.front();
    q.pop();

    if (!visited[now.first]) {
      weight[start][now.first] = min(weight[start][now.first], now.second);
      visited[now.first] = 1;
      for (int i = 0; i < (int)edges[now.first].size(); i++) {
        q.push(make_pair(edges[now.first][i], now.second + 1));
      }
    }
  }
}

int getStart() {
  int nodeWithMaxEdge = 1;
  int edgeCount = (int)edges[1].size();
  for (int i = 2; i <= n; i++) {
    if (edgeCount < (int)edges[i].size()) {
      edgeCount = (int)edges[i].size();
      nodeWithMaxEdge = i;
    }
  }
  return nodeWithMaxEdge;
}

int main() {
  // use this to pass the first example
  ReadGraph();
  for (int i = 1; i <= n; i++) {
    getWeight(i);
  }

  int white = getStart();
  SetWhite(white);
  int black = GetBlack();
  while (white != black) {
    white = getNextMove(white, black);
    SetWhite(white);
    black = GetBlack();
  }
  return 0;
}