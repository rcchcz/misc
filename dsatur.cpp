#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

// add edge
void add_edge(vector<int> graph[], int a, int b) {
  graph[a].push_back(b);
  graph[b].push_back(a);
}
 
// information related to vertices
class vertexInfo {
  public:
    // saturation degree
    int sat;
  
    // degree in uncolored graph
    int deg;
  
    // index
    int vertex;
};
 
struct maxSat {
  bool operator()(const vertexInfo &lhs, const vertexInfo &rhs) const {
    return tie(lhs.sat, lhs.deg, lhs.vertex) > tie(rhs.sat, rhs.deg, rhs.vertex); }
};

// print k independent sets 
void printksets(vector<int> &color, set<int> &ans) {
  vector<vector<int>> ksets;
  vector<int> k;
  
  for(int i = 0; i < ans.size(); i++) { ksets.push_back(k); }
  
  for(int i = 0; i < color.size(); i++) { ksets[color[i]].push_back(i); }
  
  for(int i = 0; i < ksets.size(); i++) {
    cout << "Container " << i << ": [ ";
    for(int j = 0; j < ksets[i].size(); j++) { cout << ksets[i][j] << " "; }
    cout << "]" << endl;
  }
}

// print color of each vertex of graph
void printcolor(vector<int> &color) {
  for (int i = 0; i < color.size(); i++) {
      cout << "The color of the vertex " << i << " is " << color[i] << endl;
  }
}
 
// DSatur algorithm
int DSatur(vector<int> graph[], int V) {
  int u, i;
  // create vector to store status of used colors
  vector<bool> use(V, false);

  // create vector to store colors.
  vector<int> color(V), d(V);
  vector<set<int>> adjCols(V);
  set<vertexInfo, maxSat> Q;
  set<vertexInfo, maxSat>::iterator maxPtr;

  for(u = 0; u < V; u++) {
    color[u] = -1;
    d[u] = graph[u].size();
    adjCols[u] = set<int>();
    Q.emplace(vertexInfo{0, d[u], u});
  }

  while (!Q.empty()) {
    maxPtr = Q.begin();
    u = (*maxPtr).vertex;
    Q.erase(maxPtr);

    for(int v : graph[u]) {
      if(color[v] != -1) { use[color[v]] = true; }
    }
          
    i = 0;
    while(i != use.size()) {
      if (use[i] == false) { break; }
      i++;
    }
  
    for(auto v : graph[u]) {
      if (color[v] != -1) { use[color[v]] = false; }
    }
      
    color[u] = i;
    for(auto v : graph[u]) {
      if(color[v] == -1) {
        Q.erase({int(adjCols[v].size()), d[v], v});
        adjCols[v].insert(i);
        d[v]--;
        Q.emplace(vertexInfo{int(adjCols[v].size()),d[v], v});
      }
    }
  }

  set<int> ans;
  for(int i = 0; i < V; i++) { ans.insert(color[i]); }
      
  printksets(color, ans);
  
  // return chromatic number
  return ans.size();
}
 
// calculate the chromatic number
int chromatic_number() { 
  // 'v' vertices, 'e' edges
  int v, e;
  cin >> v >> e;

  // create graph of ‘v’ vertices from 0 to v - 1
  vector<int> graph[v];
  
  int a, b;
  for(int i = 0; i < e; i++) { 
      cin >> a >> b;
      add_edge(graph, a, b);
  }

  return DSatur(graph, v);
}

int main() {
  int cn = chromatic_number();
  cout << "Total containers: " << cn << endl;
  return 0;
}
