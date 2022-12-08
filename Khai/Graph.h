//
// Created by Khai Tran on 2022-10-30.
//

#ifndef ASG02_GRAPH_H
#define ASG02_GRAPH_H
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Graph {
private:
    int size;
    Node** adjList;
public:
    Graph();
    Graph(int nodes);
    Graph(const Graph&);
    ~Graph();
    bool add_edge(int, int);
    void remove_edge(int, int);
    bool edge_exist(int, int);
    int get_degree(int);
    Graph operator++();
    Graph operator++(int a);
    Graph operator--();
    Graph operator--(int a);
    Graph operator =(Graph);
    bool path_exist(int, int);
    int get_size();
    int connectivity_type(); // bro what even is this
    int* BFS(int);
    int* DFS(int);
    friend ostream& operator<<(ostream&, const Graph&);
};


#endif //ASG02_GRAPH_H
