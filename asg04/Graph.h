// Luka David 300134324
// Khai Tran 300112587

//#ifndef ASG04_GRAPH_H
//#define ASG04_GRAPH_H

#pragma once
#include <iostream>
#include <list>

using namespace std;

class Node
{
    friend class Graph;
    Node* next;
    int data;
};

class Graph
{
protected:
    Node** arrayList;
    int size;
public:
    Graph();
    Graph(int);
    Graph(const Graph&);
    ~Graph();
    bool add_edge(int, int);
    bool edge_exist(int, int);
    void remove_edge(int, int);
    int get_degree(int);
    bool path_exist(int, int);
    int* BFS(int);
    Graph operator ++();
    Graph operator ++(int);
    Graph operator --();
    Graph operator --(int);
    friend ostream& operator<<(ostream&, Graph);
    string getNodes(int);
    void print();
};


//#endif //ASG04_GRAPH_H
