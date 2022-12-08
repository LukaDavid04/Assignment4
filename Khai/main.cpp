#include <iostream>
#include "Graph.h"

using namespace std;

int main() {

    Graph g(4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 1);


//    g.add_edge(3, 4);
//    g.add_edge(4, 4);

//    Graph a(6);
//    a.add_edge(1, 2);
//    a.add_edge(2, 1);
//    a.add_edge(2, 3);
//    a.add_edge(2, 4);
//    a.add_edge(3, 3);
//    a.add_edge(4, 1);
//    a.add_edge(4, 3);
//    a.add_edge(5, 6);

    cout << g << endl;

    return 0;
}
