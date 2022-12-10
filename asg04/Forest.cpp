// Luka David 300134324
// Khai Tran 300112587

#include "Graph.h"
#include "Forest.h"

using namespace std;

Forest::Forest(){
    
}

Forest::Forest(int x) : Graph(x){
    if (x <= 0) cout << "Not valid input" << endl;
}

bool Forest::add_edge(int a, int b) {
//    make sure that the edge does not make the graph cyclic
    if (a < 0 || a > size || b < 0 || b > size || a == b) return false;
    vector<bool> visited(size, false);

    if (checkCycle(a, b, visited)) return false;

//    add edge
    Graph::add_edge(a, b);
}

bool Forest::checkCycle(int u, int v, vector<bool> &visited) {
    visited[u - 1] = true;
    for (int i = 0; i < size; i++) {
        if (path_exist(u, i + 1)) {
            if (i + 1 == v) {
                return true;
            }
            if (!visited[i]) {
                if (checkCycle(i + 1, v, visited)) {
                    return true;
                }
            }
        }
    }
    return false;
}