#include <iostream>
#include "Graph.h"
#include <string>
#include <queue>
#include <list>

using namespace std;

Graph::Graph()
{
    size = 0;
    arrayList = new Node*[1];
    if (arrayList == NULL) cout << "Not enough memory" << endl;
    else {
        arrayList[0] = NULL;
        size = 1;
    }
}

Graph::Graph(int x)
{
    if (x <= 0) cout << "Not valid input" << endl;
    else {
        size = 0;
        arrayList = new Node*[x];
        if (arrayList == NULL) cout << "Not enough memory" << endl;
        else {
            size = x;
            int i;
            for (int i = 0; i < size; ++i)
            {
                arrayList[i] = new Node();
                arrayList[i] = NULL;
            }
        }
    }
}

Graph::Graph(const Graph& gr)
{
    int i;
    size = 0;
    arrayList = new Node*[gr.size];
    if (arrayList == NULL) cout << "Not enough memory" << endl;
    else {
        for (int i = 0; i < gr.size; ++i)
        {
            arrayList[i] = gr.arrayList[i];
            size = gr.size;
        }
    }
}

Graph::~Graph()
{
    delete[] arrayList;
}

bool Graph::add_edge(int a, int b)
{
    if (a < 0 || a > size || b < 0 || b > size || a == b ) return false;

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

bool Graph::edge_exist(int a, int b)
{
    Node* current;

    if (arrayList[a - 1] == NULL)
    {
        return false;
    }


    for (current = arrayList[a - 1]; current != NULL; current = current->next) {
        if (current->data == b)
        {
            return true;
        }
    }


    return false;
}

void Graph::remove_edge(int a, int b)
{
    if (a < 0 || a > size || b < 0 || b > size || a == b) return;

    Node* current;
    Node* previous;

    bool firstDeleted = false;
    bool secondDeleted = false;

    if (!edge_exist(a,b))
    {
        return;
    }

    if (arrayList[a-1]->data == b)
    {
        Node* temp = arrayList[a - 1];
        arrayList[a - 1] = arrayList[a - 1]->next;
        delete temp;
        firstDeleted = true;
        if (secondDeleted) return;
    }

    if (arrayList[b - 1]->data == a)
    {
        Node* temp = arrayList[b - 1];
        arrayList[b - 1] = arrayList[b - 1]->next;
        delete temp;
        secondDeleted = true;
        if (firstDeleted) return;
    }

    previous = arrayList[a - 1];
    for (current = arrayList[a - 1]; current != NULL; current = current->next) {
        if (current->next->data == b)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            firstDeleted = true;
            if (secondDeleted) return;
            break;
        }
        previous = current;
    }

    previous = arrayList[b - 1];
    for (current = arrayList[b - 1]; current != NULL; current = current->next) {
        if (current->next->data == a)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            secondDeleted = true;
            if (firstDeleted) return;
            break;
        }
        previous = current;
    }

    return;
}


int Graph::get_degree(int a)
{
    if (a < 1 || a > size)
    {
        cout << "Degree does not exist, please try again" << endl;
        return -1;
    }

    Node* current;
    int count = 0;

    for (current = arrayList[a - 1]; current != NULL; current = current->next)
        count++;

    return count;
}

Graph Graph::operator ++()
{
    int i;
    Node** temp;
    temp = new Node*[size + 1];
    if (temp == NULL) cout << "Not enough memory!" << endl;
    else
    {
        for (int i = 0; i < size; ++i) {
            temp[i] = arrayList[i];
        }

        temp[size] = new Node();
        temp[size] = NULL;
        delete[] arrayList;
        arrayList = temp;
        ++size;
        return (*this);
    }
}

Graph Graph::operator ++(int a)
{
    int i;
    Node** temp;
    Graph result = (*this);
    temp = new Node * [size + 1];
    if (temp == NULL) cout << "Not enough memory!" << endl;
    else
    {
        for (int i = 0; i < size; ++i) {
            temp[i] = arrayList[i];
        }

        temp[size] = new Node();
        temp[size] = NULL;
        delete[] arrayList;
        arrayList = temp;
        ++size;
        return (result);
    }
}

Graph Graph::operator --()
{
    if (size != 0)
    {
        int i,j;
        Node** temp;
        temp = new Node * [size - 1];
        if (temp == NULL) cout << "Not enough memory!" << endl;
        else
        {
            for (j = 0; j < size; ++j) {
                if (edge_exist(j + 1, size + 1)) remove_edge(j + 1, size + 1);
            }

            for (int i = 0; i < size - 1; ++i) {
                temp[i] = arrayList[i];
            }

            delete[] arrayList;
            arrayList = temp;
            --size;

            return (*this);
        }
    }
    cout << "Graph is already empty!" << endl;
    return (*this);
}

Graph Graph::operator --(int a)
{
    if (size != 0)
    {
        int i, j;
        Graph result = (*this);
        Node** temp;
        temp = new Node * [size - 1];
        if (temp == NULL) cout << "Not enough memory!" << endl;
        else
        {
            for (j = 0; j < size; ++j) {
                if (edge_exist(j + 1, size + 1)) remove_edge(j + 1, size + 1);
            }

            for (int i = 0; i < size - 1; ++i) {
                temp[i] = arrayList[i];
            }

            delete[] arrayList;
            arrayList = temp;
            --size;

            //cout << size << endl;
            return (result);
        }
    }
    cout << "Graph is already empty!" << endl;
    Graph result = (*this);
    return (result);
}


bool Graph::path_exist(int a, int b)
{
    if (edge_exist(a, b)) return true;
    Node* current;

    bool* visited = new bool[size];
    int i, s;

    for (i = 0; i < size; ++i) visited[i] = false;

    queue<int> Q;

    visited[a - 1] = true;
    Q.push(a - 1);

    while (!Q.empty()) {

        s = Q.front();
        // cout << s + 1 << " ";
        if (s + 1 == b) return true;
        Q.pop();

        Node* current;
        for (current = arrayList[s]; current != NULL; current = current->next) {
            if (!visited[current->data - 1]) {
                visited[current->data - 1] = true;
                Q.push(current->data - 1);
            }
        }

    }


    return false;
}

int* Graph::BFS(int a)
{
    int* bfs = new int[size];
    bool* visited = new bool[size];
    int i, s;

    for (i = 0; i < size; ++i)
    {
        visited[i] = false;
        bfs[i] = -1;
    }

    queue<int> Q;

    visited[a - 1] = true;
    Q.push(a - 1);

    while (!Q.empty()) {

        s = Q.front();
        cout << s + 1 << " ";
        for (i = 0; i < size; ++i)
        {
            if (bfs[i] == -1)
            {
                bfs[i] = s + 1;
                break;
            }
        }
        Q.pop();

        Node* current;
        for (current = arrayList[s]; current != NULL; current = current->next) {
            if (!visited[current->data - 1]) {
                visited[current->data - 1] = true;
                Q.push(current->data - 1);
            }
        }

    }
    return bfs;
}

ostream& operator <<(ostream& out, Graph gr)
{
    int i, j, k = 0;
    string output;
    output += "V = {";
    for (i = 0; i < gr.size; ++i)
    {
        if (i != gr.size - 1) output += to_string(i + 1) + ", ";
        else {
            output += to_string(i + 1) + "} \n";
        }
    }
    output += "E = \n";
    output += "{ \n";
    for (j = 0; j < gr.size; ++j)
    {
        Node* current;
        output += to_string(j + 1) + " => ";

        if (gr.arrayList[j] == NULL) output += "None \n";

        output += gr.getNodes(j);
    }
    output += "}";
    out << output << endl;
    return out;
}

string Graph::getNodes(int j) {
    Node* current;
    string output = "";
    for (current = arrayList[j]; current != NULL; current = current->next)
    {
        if (current->next != NULL) output += to_string(current->data) + ", ";
        else {
            output += to_string(current->data) + "\n";
        }
    }
    return output;
}

void Graph::print() {
    int i,j,k = 0;
    cout  << "V = {";
    for (i = 0; i < size; ++i)
    {
        if (i != size - 1) cout << i + 1 << ", ";
        else {
            cout << i + 1 << "}" << endl;
        }
    }
    cout << "E = " << endl;
    cout << "{" << endl;
    for (j = 0; j < size; ++j)
    {
        Node* current;
        cout << j + 1 << " => ";

        if (arrayList[j] == NULL) cout << "None" << endl;

        for (current = arrayList[j]; current != NULL; current = current->next)
        {
            if (current->next != NULL) cout << current->data << ", ";
            else {
                cout << current->data << endl;
            }
        }
    }
    cout << "}" << endl;
}
