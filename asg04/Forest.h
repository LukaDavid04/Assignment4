//
// Created by Khai Tran on 2022-12-08.
//

#ifndef ASG04_FOREST_H
#define ASG04_FOREST_H
#include "Graph.h"
#include <vector>

class Forest : public Graph {
public:
    bool add_edge(int, int);
    bool checkCycle();
    bool checkCycle(int, int, vector<bool> &visited);
};


#endif //ASG04_FOREST_H
