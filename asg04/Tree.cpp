//
// Created by Khai Tran on 2022-12-09.
//

// NOTE: In this given example, the root is 1
// 1 contains [2, 5, 6]
// in which which case 2 contains [3, 4]

//1
//    --- 2
//        --- 3
//        --- 4
//    --- 5
//    --- 6
//        --- 7
//    --- 8


#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;


Tree::Tree() {
    Graph(1);
    set_root();
}

// sets a vertex as the root of the tree
void Tree::set_root() {
    root = arrayList[0]->data;
}

// connects given vertex to a new vertex
void Tree::add_vertex(int a) {
    if (a < 0 || a > size) return;

//  NOTE: each added edge will be an arrayList
    if (arrayList[a - 1] != NULL) {
        Node* current;
        Node* new_node = new Node;

        // navigate to end of current vertex
        for (current = arrayList[a - 1]; current != NULL; current = current->next) {
            // at end of current vertex, add in new vertex that is connected to current vertex
            if (current->next == NULL) {
                new_node->data = size;
                current->next = new_node;
                new_node->next = NULL;

                // add the new vertex to the arrayList
                add_edge(size, a);
                return;
            }
        }
    }

}

// add a left to the tree, has to add an edge to keep it as a tree
void Tree::operator++() {
    add_vertex(size);
}

// remove the last vertex added to the tree
void Tree::operator--() {
    // iterate through array list to delete all occurrences of the last vertex
    // in other words, delete vertex of value size
    for (int i = 0; i < size; i++) {
        Node* current = arrayList[i];
        Node* prev = NULL;

//        delete occurrences of vertex of value size if found
        while (current != NULL) {
            // delete
            if (current->data == size) {
                // if the vertex is the first vertex in the arrayList
                if (prev == NULL) {
                    arrayList[i] = current->next;
                    delete current;
                    current = arrayList[i];
                }
                // if the vertex is not the first vertex in the arrayList
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            prev = current;
            current = current->next;
        }
    }

    // TODO: trim the array list to remove the last vertex
};

void Tree::show_node(int a) {
    vector<bool> visited(size, false);
    show_node(a, 0, visited);
}

void Tree::show_node(int n, int depth, vector<bool> visited) {
    string indent = "";
    for (int i = 0; i < depth; i++) {
        indent += "   ---";
    }

    // iterate through the arrayList
    for (Node* current = arrayList[n - 1]; current != NULL; current = current->next) {
        // if the vertex has not been visited
        if (!visited[current->data - 1]) {
            cout << indent << current->data << endl;
            visited[current->data - 1] = true;
            show_node(current->data, depth + 1, visited);
        }
    }

}

ostream& operator <<(ostream& out, Tree tree) {
//    TODO: use show_node
    return out;
}