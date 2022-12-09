//
// Created by Khai Tran on 2022-12-09.
//

#ifndef ASG04_TREE_H
#define ASG04_TREE_H
#include "Forest.h"
#include <iostream>
#include <vector>

using namespace std;

class Tree : public Forest {
private:
    int root;
public:
    Tree();
    void add_vertex(int a); // connects given vertex to a new vertex
    void set_root(); // sets a vertex as the root of the tree
    void operator--();
    void operator++();

    friend ostream& operator<<(ostream&, Tree);

    // helper
    void show_node(int n);
    void show_node(int n, int depth, vector<bool> visited);
};


#endif //ASG04_TREE_H
