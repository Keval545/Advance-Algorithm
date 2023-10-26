//Randomized approximation of MVC.
//Time complexity (average) : O(E), E = no. of Edges. POLYNOMIAL.

#include<bits/stdc++.h>
using namespace std;

// To perform the approx. algorithm for Vertex Cover using Sets.

set<int> approximateVertexCover(vector<pair<int, int>> edges) {
    srand(time(NULL));
    
    set<int> result;
    //converting vector of edges into set.
    set<pair<int, int>> E(edges.begin(), edges.end());
    
    //Loop till all edges are not removed (Basically, till all vertices are not covered).
    while (!E.empty()) {
        // Pick an edge (u, v) from set E
        int randomIndex = rand() % E.size();

        // Advance the iterator to the random index
        auto it = E.begin();
        advance(it, randomIndex);
        
        int u = it->first;
        int v = it->second;

        // Add 'u' and 'v' to the result
        result.insert(u);
        result.insert(v);

        // Remove all edges from E which are either incident on u or v
        vector<pair<int, int>> toRemove;
        for (const auto& edge : E) {
            if (edge.first == u || edge.first == v || edge.second == u || edge.second == v) {
                toRemove.push_back(edge);
            }
        }
        
        //Erase those edges which are present in toRemove vec from original edge vector.
        for (const auto& edgeToRemove : toRemove) {
            E.erase(edgeToRemove);
        }
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter no. of vertices and Edges in a graph :\n";
    cin >> V >> E;
    
    vector<pair<int, int>> edges(E);
    
    int u, v;
    for(int i=0; i<E; i++) {
        cout << "Enter endpoints of edge " << i+1 << " in a graph :\n";
        cin >> u >> v;
        
        edges[i] = {u, v};
    }
    
    set<int> VC = approximateVertexCover(edges);
    
    cout << "Approximate Vertex cover :\n";
    for(auto v: VC) cout << v << " ";
  
    
    return 0;
}
