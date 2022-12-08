//
// Created by Khai Tran on 2022-10-30.
//

#include "Graph.h"
#include <list>
#include <stack>
// assumption: nodes are numbered from 0 to n

Graph::Graph() {
    size = 0;
    adjList = NULL;
}

Graph::Graph(int nodes) {
    size = nodes;
    adjList = new Node*[size];

    for (int i = 0; i<size; i++) {
        adjList[i] = NULL;
    }
}

Graph::Graph(const Graph& g) {
    size = g.size;
    adjList = new Node*[size];

    for (int i = 0; i<size; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i<size; i++) {
        Node* current = g.adjList[i];
        while (current != NULL) {
            add_edge(i, current->data);
            current = current->next;
        }
    }
}

Graph::~Graph() {
    delete[] adjList;
}

bool Graph::add_edge(int a, int b) {
    a = a - 1;
    b = b - 1;
    if (a > size || b > size || a == b)
        return false;

    //    for node A to B
    Node* new_node = new Node;
    new_node->data = b;

    Node* current = adjList[a];

    if (current == NULL) {
        adjList[a] = new_node;
        new_node->next = NULL;
//        check if b already contains a
        current = adjList[b];
        new_node = new Node;
        new_node->data = a;

        if (current == NULL) {
            adjList[b] = new_node;
            new_node->next = NULL;
        } else {
            while (current->next != NULL) {
                if (current->data == a)
                    return true;
                current = current->next;
            }
            current->next = new_node;
            new_node->next = NULL;
        }

        return true;
    }

    while (current != NULL) {
        if (current->data == b)
            return false;
        if (current->data < b && (current->next == NULL || current->next->data > b)) {
            current->next = new_node;
//            check if b already contains a
            current = adjList[b];
            new_node = new Node;
            new_node->data = a;

            if (current == NULL) {
                adjList[b] = new_node;
                new_node->next = NULL;
            } else {
                while (current->next != NULL) {
                    if (current->data == a)
                        return true;
                    current = current->next;
                }
                current->next = new_node;
                new_node->next = NULL;
            }
            return true;
        }
        current = current->next;
    }


    return false;
}

bool Graph::edge_exist(int a, int b) {
    a = a - 1;
    b = b - 1;
    if (a > size || b > size)
        return false;

    Node* current = adjList[a];
    while (current != NULL) {
        if (current->data == b)
            return true;
        current = current->next;
    }

    return false;
}

int Graph::get_degree(int a) {
    a = a - 1;
    if (a > size)
        return -1;

    Node* current = adjList[a];
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void Graph::remove_edge(int a, int b) {
    a = a - 1;
    b = b - 1;
    if (a > size || b > size)
        return;

    Node* current = adjList[a];
    if (current == NULL)
        return;

    if (current->data == b) {
        adjList[a] = current->next;
        delete current;
        return;
    }

    while (current->next != NULL) {
        if (current->next->data == b) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

bool Graph::path_exist(int a, int b) {
    a = a - 1;
    b = b - 1;
    if (a > size || b > size)
        return false;

    bool* visited = new bool[size];
    for (int i = 0; i<size; i++) {
        visited[i] = false;
    }

    std::list<int> queue;
    queue.push_back(a);
    visited[a] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();

        Node* temp = adjList[current];
        while (temp != NULL) {
            if (temp->data == b) {
                delete[] visited;
                return true;
            }
            if (!visited[temp->data]) {
                visited[temp->data] = true;
                queue.push_back(temp->data);
            }
            temp = temp->next;
        }
    }

    delete[] visited;
    return false;
}

int* Graph::DFS(int a) {
    a = a - 1;
    if (a > size)
        return NULL;

    int* result = new int[size];
    int count = 0;

    bool* visited = new bool[size];
    for (int i = 0; i<size; i++) {
        visited[i] = false;

    }

    stack<int> idk;

    stack<int> stack;


    stack.push(a);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        cout << "<- popped: " << current+1 << endl;
        if (!visited[current]) {
            visited[current] = true;
            result[count] = current + 1;
            count++;
            Node* temp = adjList[current];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                idk.push(temp->data);
                }
                temp = temp->next;
            }
            while (!idk.empty()) {
                stack.push(idk.top());
                idk.pop();
            }
        }
    }

    return result;
}

int* Graph::BFS(int a) {
    a = a - 1;
    if (a > size)
        return NULL;

    list<int> q;

    bool* visited = new bool[size];
    for (int i = 0; i<size; i++) {
        visited[i] = false;
    }

    int* result = new int[size];
    int count = 0;

    q.push_back(a);
    visited[a] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();

        result[count] = current+1;

        count++;

        Node* temp = adjList[current];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                q.push_back(temp->data);
                visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }

    delete[] visited;
    return result;
}

Graph Graph::operator++() {
    Node** newAdjList = new Node* [size + 1];

    for (int i = 0; i<size; i++) {
        newAdjList[i] = adjList[i];
    }

    newAdjList[size+1] = NULL;

    delete[] adjList;

    adjList = newAdjList;
    size = size + 1;

    return *this;
}

Graph Graph::operator++(int n) {
    Graph result  = *this;
    Node** newAdjList = new Node* [size + 1];

    for (int i = 0; i<size; i++) {
        newAdjList[i] = adjList[i];
    }

    newAdjList[size + 1] = NULL;

    delete[] adjList;

    adjList = newAdjList;
    size = size + 1;

    return result;
}

Graph Graph::operator--() {
    for (int i = 0; i<size-1; i++) {
        Node* current = adjList[i];
        if (current != NULL) {
            if (current->data == size-1) {
                adjList[i] = current->next;
            }
            while (current->next != NULL) {
                if (current->next->data == size+1) {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
                current = current->next;
            }
        }
    }

    size = size - 1;
    Node **newAdjList = new Node *[size];

    for (int i = 0; i < size; i++) {
        newAdjList[i] = adjList[i];
    }

    delete[] adjList;

    adjList = newAdjList;
    return *this;
}

int Graph::get_size() {
    return size;
}

Graph Graph::operator=(Graph g) {
    size = g.get_size();
    adjList = new Node* [size];

    for (int i = 0; i<size; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i<size; i++) {
        Node* current = g.adjList[i];
        while (current != NULL) {
            add_edge(i+1, current->data+1);
            current = current->next;
        }
    }

    return *this;
}

Graph Graph::operator--(int n) {
    Graph result = *this;
    for (int i = 0; i<size-1; i++) {
        Node *current = adjList[i];
        if (current != NULL) {
            if (current->data == size - 1) {
                adjList[i] = current->next;
            }
            while (current->next != NULL) {
                if (current->next->data == size + 1) {
                    Node *temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
                current = current->next;
            }
        }
    }

    size = size - 1;
    Node **newAdjList = new Node *[size];

    for (int i = 0; i < size; i++) {
        newAdjList[i] = adjList[i];
    }

    delete[] adjList;

    adjList = newAdjList;
    return result;
}

//  0 for not connected
//  1 for weakly connected
//  2 for unilaterally connected
//  3 for strongly connected
int Graph::connectivity_type() {
    int* result = DFS(1);
    for (int i = 0; i<size; i++) {
        if (result[i] == 0)
            return 0;
    }
    return 1;
}

ostream& operator << (ostream& out, const Graph& g) {
    out << "V = {";
    for (int i = 0; i < g.size; i++) {
        out << i + 1;
        if (i != g.size - 1)
            out << ", ";
    }
    out << "}" << endl;

    out << "E = {" << endl;
    for (int i = 0; i<g.size; i++) {
        out << "   " << i+1 << " => ";
        Node* current = g.adjList[i];
        if (current == NULL) {
            out << "None";
        }
        while (current != NULL) {
            out << current->data+1 << " ";
            current = current->next;
        }
        out << endl;
    }
    out << "}" << endl;

    return out;
}

