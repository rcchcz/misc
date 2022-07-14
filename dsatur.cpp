#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

void printadlist(vector<int> graph[], int v) {
  cout << "Adjacency list" << endl;
  for(int i = 0; i < v; i++) {
    cout << "[" << i << "]: ";
    for(int j = 0; j < graph[i].size(); j++) { cout << graph[i][j] << " "; }
    cout << "" << endl;
  }
}

// adjacency list
void addEdge(vector<int> graph[], int a, int b) {
  graph[a].push_back(b);
  graph[b].push_back(a);
}
 
class vertexInfo {
  public:
    int sat; // saturation degree
    int deg; // degree in uncolored graph
    int vertex; // index
};
 
struct maxSat {
  bool operator()(const vertexInfo &lhs, const vertexInfo &rhs) const {
    return tie(lhs.sat, lhs.deg, lhs.vertex) > tie(rhs.sat, rhs.deg, rhs.vertex); }
};

void printksets(vector<int> &color, set<int> &ans) {
  vector<vector<int>> ksets;
  vector<int> k;
  
  for(int i = 0; i < ans.size(); i++) { ksets.push_back(k); }
  
  for(int i = 0; i < color.size(); i++) { ksets[color[i]].push_back(i); }

  cout << "" << endl;
  cout << "" << endl;
  for(int i = 0; i < ksets.size(); i++) {
    cout << "Container " << i << ": [ ";
    for(int j = 0; j < ksets[i].size(); j++) { cout << ksets[i][j] << " "; }
    cout << "]" << endl;
  }
}
 
int dsatur(vector<int> graph[], int V) {
  int a, b;
  vector<bool> use(V, false); // store status of used colors
  vector<int> color(V), d(V); 
  vector<set<int>> adjCols(V);
  set<vertexInfo, maxSat> Q;
  set<vertexInfo, maxSat>::iterator maxPtr;

  for(a = 0; a < V; a++) {
    color[a] = -1;
    d[a] = graph[a].size();
    adjCols[a] = set<int>();
    Q.emplace(vertexInfo{0, d[a], a});
  }

  while(!Q.empty()) {
    maxPtr = Q.begin();
    a = (*maxPtr).vertex;
    Q.erase(maxPtr);

    for(int v : graph[a]) {
      if(color[v] != -1) { use[color[v]] = true; }
    }
          
    b = 0;
    while(b != use.size()) {
      if(use[b] == false) { break; }
      b++;
    }
  
    for(auto v : graph[a]) {
      if(color[v] != -1) { use[color[v]] = false; }
    }
      
    color[a] = b;
    for(auto v : graph[a]) {
      if(color[v] == -1) {
        Q.erase({int(adjCols[v].size()), d[v], v});
        adjCols[v].insert(b);
        d[v]--;
        Q.emplace(vertexInfo{int(adjCols[v].size()),d[v], v});
      }
    }
  }

  set<int> ans;
  for(int i = 0; i < V; i++) { ans.insert(color[i]); }
      
  printksets(color, ans);
  
  // return chromatic number (number of containers)
  return ans.size();
}

// file handling and graph building
int buildGraph(istream& f) { 
  string line = "";
  int a, b, v;
  bool first_line = true;  

  getline(f, line); // number of vertices and edges
  v = stoi(line.substr(0, line.find_first_of(" "))); // get the vertices
  vector<int> graph[v]; // create graph

  while(getline(f, line)) {
    a = stoi(line.substr(0, line.find_first_of(" ")));
    b = stoi(line.substr(line.find_first_of(" ") + 1, line.length()));
    addEdge(graph, a, b); 
  }

  // printadlist(graph, v);

  return dsatur(graph, v);
}

// driver code
int main(int argc, char* argv[]) {
  if (argc <= 1) { return -1; }
  
  ifstream data(argv[1]);
  if(data.is_open() && data.good()) {  
    int cn = buildGraph(data); 
    cout << "" << endl;
    cout << "Total containers: " << cn << endl;
    cout << "" << endl;
    cout << "" << endl;
  }
  
  return 0;
}
