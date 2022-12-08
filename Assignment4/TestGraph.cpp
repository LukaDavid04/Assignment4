#include "Graph.h"

using namespace std;

int main() 
{
	Graph a(6);

	Graph b(6);
	b.add_edge(2,1);
	b.add_edge(2,3);


	a.add_edge(1, 2);
	a.add_edge(2, 3);
	a.add_edge(2, 4);
	a.add_edge(3, 3);
	a.add_edge(4, 1);
	a.add_edge(4, 3);
	a.add_edge(5, 6);

    //int* bfs1 = a.BFS(1);

    Graph c(a);

    //a.remove_edge(1, 2);
    //cout << a << endl;
    //cout << c << endl;

    //c.add_edge(1, 2);
    //c.add_edge(2, 3);
    //c.add_edge(2, 4);
    //c.add_edge(3, 3);
    //c.add_edge(4, 1);
    //c.add_edge(4, 3);
    //c.add_edge(5, 6);


    cout << "Testing Edge Exist" << endl;
    if (a.edge_exist(6, 5) == 1)
        cout << "Test 1 Passed" << endl;
    else
        cout << "Test 1 Failed" << endl;
    if (a.edge_exist(5, 6) == 1)
        cout << "Test 2 Passed" << endl;
    else
        cout << "Test 2 Failed" << endl;
    if (a.edge_exist(1, 2) == 1)
        cout << "Test 3 Passed" << endl;
    else
        cout << "Test 3 Failed" << endl;
    if (a.edge_exist(3, 3) == 0)
        cout << "Test 4 Passed" << endl;
    else
        cout << "Test 4 Failed" << endl;
    if (a.edge_exist(4, 3) == 1)
        cout << "Test 5 Passed" << endl;
    else
        cout << "Test 5 Failed" << endl;
    if (a.edge_exist(4, 1) == 1)
        cout << "Test 6 Passed" << endl;
    else
        cout << "Test 6 Failed" << endl;
    if (a.edge_exist(2, 4) == 1)
        cout << "Test 7 Passed" << endl;
    else
        cout << "Test 7 Failed" << endl;
    if (a.edge_exist(3, 5) == 0)
        cout << "Test 8 Passed" << endl;
    else
        cout << "Test 8 Failed" << endl;
    if (a.edge_exist(6, 6) == 0)
        cout << "Test 9 Passed" << endl;
    else
        cout << "Test 9 Failed" << endl;
    if (a.edge_exist(1, 6) == 0)
        cout << "Test 10 Passed" << "\n" << endl;
    else
        cout << "Test 10 Failed" << "\n" << endl;


    cout << "Testing Get Degree" << endl;
    cout << a.get_degree(1) << endl;
    cout << a.get_degree(2) << endl;
    cout << a.get_degree(3) << endl;
    cout << a.get_degree(4) << endl;
    cout << a.get_degree(5) << endl;
    cout << a.get_degree(6) << "\n" << endl;

    //-------------------------------//
    cout << "Testing Remove Edge" << endl;
    c.add_edge(2, 5);
    c.remove_edge(2, 5);
    cout << a << endl;

    if (c.edge_exist(2, 5) == 0)
        cout << "Test 1 Passed" << endl;
    else
        cout << "Test 1 Failed" << endl;
    cout << a << endl;
    //c.remove_edge(1, 2); // This breaks the code if we print a
    //cout << a << endl;
    if (c.edge_exist(1, 2) == 0)
        cout << "Test 2 Passed" << endl;
    else
        cout << "Test 2 Failed" << endl;
    if (c.edge_exist(2, 1) == 0)
        cout << "Test 3 Passed" << endl;
    else
        cout << "Test 3 Failed" << endl;
    //cout << a << endl;
    c.remove_edge(4, 1); // For some reason this alters Graph a
    //cout << a << endl;
    if (c.edge_exist(4, 1) == 0)
        cout << "Test 4 Passed" << endl;
    else
        cout << "Test 4 Failed" << endl;
    c.remove_edge(6, 1);
    if (c.edge_exist(6, 1) == 0)
        cout << "Test 5 Passed" << "\n" << endl;
    else
        cout << "Test 5 Failed" << "\n" << endl;

    //cout << c << endl;

    //-------------------------------//
    cout << "Testing Get Degree" << endl;
    cout << c.get_degree(1) << endl;
    cout << c.get_degree(2) << endl;
    cout << c.get_degree(3) << endl;
    cout << c.get_degree(4) << endl;
    cout << c.get_degree(5) << endl;
    cout << c.get_degree(6) << "\n" << endl;

    cout << "Testing Prefix Postfix --/++" << endl;
    c--;

    int l;
    // for (l = 0; l < 8; ++l) c--;

    cout << a++ <<endl;
    cout << a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << a-- << endl;
    cout << a-- << endl;
    cout << a << endl;
    cout << ++a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << --a << endl;
    cout << ++a << endl;
    cout << a-- << endl;
    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << --a << endl;
    cout << a-- << endl;
    cout << a << "\n" << endl;

    cout << "Testing Prefix Postfix --/++" << endl;
    cout << c << endl;
    if (c.path_exist(1, 2) == 1)
        cout << "Test 1 Passed" << endl;
    else
        cout << "Test 1 Failed" << endl;

    if (c.path_exist(1, 4) == 0)
        cout << "Test 2 Passed" << endl;
    else
        cout << "Test 2 Failed" << endl;
    
    if (c.path_exist(1, 5) == 0)
        cout << "Test 3 Passed" << endl;
    else
        cout << "Test 3 Failed" << endl;

    if (c.path_exist(1, 6) == 0)
        cout << "Test 4 Passed" << endl;
    else
        cout << "Test 4 Failed" << endl;

    if (c.path_exist(2, 6) == 0)
        cout << "Test 5 Passed" << endl;
    else
        cout << "Test 5 Failed" << endl;

    if (c.path_exist(1, 1) == 0)
        cout << "Test 6 Passed" << endl;
    else
        cout << "Test 6 Failed" << endl;

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