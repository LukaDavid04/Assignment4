#include "Graph.h"

using namespace std;

int main() 
{
	Graph a(6);
	Graph b(6);
	b.add_edge(2,1);
	b.add_edge(2,3);
    //b.print();
	//cout << b << endl;

	a.add_edge(1, 2);
	a.add_edge(2, 1);
	a.add_edge(2, 3);
	a.add_edge(2, 4);
	a.add_edge(3, 3);
	a.add_edge(4, 1);
	a.add_edge(4, 3);
	a.add_edge(5, 6);

    Graph c(a);

    // Testing edge exist
    //if (a.edge_exist(6, 5) != 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(5, 6) == 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(1, 2) == 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(3, 3) == 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(4, 3) == 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(4, 1) == 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(2, 1) == 0)
    //    cout << "False" << endl;
    //else
    //    cout << "True" << endl;
    //if (a.edge_exist(3, 5) == 0)
    //    cout << "True" << endl;
    //else
    //    cout << "False" << endl;
    //if (a.edge_exist(6, 6) == 0)
    //    cout << "True" << endl;
    //else
    //    cout << "False" << endl;
    //if (a.edge_exist(1, 6) == 0)
    //    cout << "True" << endl;
    //else
    //    cout << "False" << endl;

    // Testing remove_edge
    c.add_edge(2, 5);
    c.print();
    c.remove_edge(2, 5);
    if (c.edge_exist(2, 5) == 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    c.print();
    c.remove_edge(1, 2);
    if (c.edge_exist(1, 2) == 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    c.print();
    c.remove_edge(4, 1);
    if (c.edge_exist(4, 1) == 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    c.print();
    /*if (c.remove_edge(6, 1) == 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;*/
    c.print();

    //// Testing get_degree
    //cout << a.get_degree(1) << endl;
    //cout << a.get_degree(2) << endl;
    //cout << a.get_degree(3) << endl;
    //cout << a.get_degree(4) << endl;
    //cout << a.get_degree(5) << endl;
    //cout << a.get_degree(6) << endl;

    /*a.print();
    b.print();
    c.print();
    cout << "cunt" << endl;*/

    /*int l;
    for (l = 0; l < 8; ++l) a--;*/

    //cout << a++ <<endl;
    //cout << a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << a-- << endl;
    //cout << a-- << endl;
    //cout << a << endl;
    //cout << ++a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << --a << endl;
    //cout << ++a << endl;
    //cout << a-- << endl;
    //cout << ++a << endl;
    //cout << a++ << endl;
    //cout << a << endl;
    //cout << --a << endl;
    //cout << a-- << endl;
    //cout << a << endl;

    cout << c << endl;
    if (c.path_exist(1, 2) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;

    if (c.path_exist(1, 4) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;
    
    if (c.path_exist(1, 5) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;

    if (c.path_exist(1, 6) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;

    if (c.path_exist(2, 6) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;

    if (c.path_exist(1, 1) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;

    Graph g(4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(3, 4);
    g.add_edge(4, 4);

    if (g.path_exist(2, 1) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;

    int* bfs = g.BFS(3);
}