//
// Created by Khai Tran on 2022-12-08.
//

#include "Graph.h"
#include "Forest.h"

using namespace std;

bool Forest::add_edge(int a, int b) {
//    make sure that the edge does not make the graph cyclic
    vector<bool> visited(size, false);

    if (checkCycle(a, b, visited)) return false;

//    add edge
    if (a < 0 || a > size || b < 0 || b > size || a == b ) return false;
    if (edge_exist(a, b)) return false;


    Node* current;
    Node* new_node = new Node;
    Node* new_node2 = new Node;

    bool firstAdded = false;
    bool secondAdded = false;

    if (new_node == NULL)
        return false;

    if (new_node2 == NULL)
        return false;

    if (arrayList[a - 1] == NULL)
    {
        new_node->data = b;
        arrayList[a - 1] = new_node;
        new_node->next = NULL;
        firstAdded = true;
        if (secondAdded) return true;
    }

    if (arrayList[b - 1] == NULL)
    {
        new_node2->data = a;
        arrayList[b - 1] = new_node2;
        new_node2->next = NULL;
        secondAdded = true;
        if (firstAdded) return true;
    }

    for (current = arrayList[a - 1]; current != NULL; current = current->next) {
        if (current->next == NULL)
        {
            new_node->data = b;
            current->next = new_node;
            new_node->next = NULL;
            firstAdded = true;
            if (secondAdded) return true;
        }
    }

    for (current = arrayList[b - 1]; current != NULL; current = current->next) {
        if (current->next == NULL)
        {
            new_node2->data = a;
            current->next = new_node2;
            new_node2->next = NULL;
            secondAdded = true;
            if (firstAdded) return true;
        }
    }
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