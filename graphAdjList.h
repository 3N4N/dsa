#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "ArrayList.h"

class Graph {
public:
    Graph(bool, int, int);
    ~Graph();
    bool isEdge(int, int);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    int getDegree(int u);
    void dfs(int);
    void bfs(int);
private:
    bool isDirected;
    int noOfVertices;
    int noOfEdges;
    ArrayList<int> * matrix;
    bool * visited;
};

Graph::Graph(bool isDirected, int noOfVertices, int noOfEdges) {
    this->isDirected = isDirected;
    this->noOfVertices = noOfVertices;
    this->noOfEdges = noOfEdges;
    matrix = new ArrayList<int>[noOfVertices];
    visited = new bool[noOfVertices];
}

Graph::~Graph() {
    if (matrix)
        delete [] matrix;
}

bool Graph::isEdge(int u, int v) {
    if (matrix[u].search(v) != -1) return true;
    else return false;
}

void Graph::addEdge(int u, int v) {
    if (!isEdge(u, v))
        matrix[u].add(v);
    if (!isDirected && isEdge(v, u))
        matrix[v].add(u);
}
void Graph::removeEdge(int u, int v) {
    matrix[u].remove(v);
    if (!isDirected)
        matrix[v].remove(u);
}
int Graph::getDegree(int u) {
    int counter = 0;

    for (int i=0; i<noOfVertices; ++i) {
        if (i == u) {
            if (isEdge(u, i)) counter++;
            continue;
        }

        if (isDirected) {
            if (isEdge(u, i)) counter++;
            if (isEdge(i, u)) counter++;
        }
        else {
            if (isEdge(u, i)) counter++;
        }
    }

    return counter;
}
void Graph::dfs(int source) {
    for (int i=0; i<noOfVertices; ++i)
        visited[i] = false;

    Stack<int> st(noOfVertices);
    st.push(source);

    while (st.size() > 0) {
        source = st.peek();
        st.pop();
        visited[source] = true;
        std::cout << source << " ";

        for (int i=0; i<noOfVertices; ++i) {
            if (!isEdge(source, i))
                continue;
            else if (!visited[i])
                st.push(i);
        }
    }

    std::cout << std::endl;
}
void Graph::bfs(int source) {
    for (int i=0; i<noOfVertices; ++i) {
        visited[i] = false;
    }

    Queue<int> q(noOfVertices);
    q.enqueue(source);
    visited[source] = true;
    std::cout << source << " ";

    while (q.size() > 0) {
        source = q.first();
        q.dequeue();

        for (int i=0; i<noOfVertices; ++i) {
            if (!isEdge(source, i)) continue;
            else if (!visited[i]) {
                q.enqueue(i);
                visited[i] = true;
                std::cout << i << " ";
            }
        }
    }
    std::cout << std::endl;
}

#endif          // GRAPH_H
