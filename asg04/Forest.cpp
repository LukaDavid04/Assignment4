//
// Created by Khai Tran on 2022-12-08.
//

#include "Graph.h"
#include "Forest.h"

using namespace std;

void Forest::add_edge(int u, int v) {
//    make sure that the edge does not make the graph cyclic
    vector<bool> visited(size, false);

    if (checkCycle(u, v, visited)) return;

    add_edge(u, v);
}

bool Forest::checkCycle(int u, int v, vector<bool> &visited) {
    visited[u] = true;
    for (int i = 0; i < size; i++) {
        if (path_exist(u, i)) {
            if (i == v) {
                return true;
            }
            if (!visited[i]) {
                if (checkCycle(i, v, visited)) {
                    return true;
                }
            }
        }
    }
    return false;
}