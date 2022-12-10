// Luka David 300134324
// Khai Tran 300112587

//#ifndef ASG04_FOREST_H
//#define ASG04_FOREST_H
#pragma once
#include "Graph.h"
#include <vector>

//class Node
//{
//    friend class Forest;
//    Node* next;
//    int data;
//};

class Forest : public Graph {
public:
    Forest();
    Forest(int);
    bool add_edge(int, int);
    //bool checkCycle();
    bool checkCycle(int, int, vector<bool> &visited);
};


//#endif //ASG04_FOREST_H
