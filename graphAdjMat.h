#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include "Stack.h"
#include "Queue.h"

class Graph {
public:
    Graph(bool, int, int);
    ~Graph();
    bool isEdge(int, int);
    void addEdge(int, int, int);
    void removeEdge(int, int);
    int getDegree(int);
    int getNoOfVertices();
    int getNoOfEdges();
    int getEdgeWeight(int, int);
    void dfs(int);
    void bfs(int);
private:
    bool isDirected;
    int ** adjMat;
    bool * visited;
    int noOfVertices;
    int noOfEdges;
};

Graph::Graph(bool isDirected, int noOfVertices, int noOfEdges) {
    this->isDirected = isDirected;
    this->noOfVertices = noOfVertices;
    this->noOfEdges = noOfEdges;
    visited = new bool[noOfVertices];
    adjMat = new int * [noOfVertices];
    for (int i=0; i<noOfVertices; i++) {
        adjMat[i] = new int[noOfVertices];
        for (int j=0; j<noOfVertices; ++j)
            adjMat[i][j] = 0;
    }
}

Graph::~Graph() {
    for (int i=0; i<noOfVertices; ++i)
        if (adjMat[i])
            delete[] adjMat[i];
    if (adjMat) delete[] adjMat;
    adjMat = NULL;
}

bool Graph::isEdge(int u, int v) {
    return adjMat[u][v];
}

void Graph::addEdge(int u, int v, int w)
{
    if(u<0 || u>=noOfVertices || v<0 || v>=noOfVertices) return;
    adjMat[u][v] = w;
    if(!isDirected) adjMat[v][u] = w;
}

void Graph::removeEdge(int u, int v)
{
    if (u<0 || u>=noOfVertices || v<0 || v>=noOfVertices) return;
    adjMat[u][v] = 0;
    if (!isDirected) adjMat[v][u] = 0;
}

int Graph::getDegree(int u) {
    int counter = 0;
    for (int i=0; i<noOfVertices; ++i) {
        if (i==u) {
            if (adjMat[u][i]) counter++;
            continue;
        }

        if (isDirected) {
            if (adjMat[u][i]) counter++;
            if (adjMat[i][u]) counter++;
        } else {
            if (adjMat[u][i]) counter++;
        }
    }

    return counter;
}

int Graph::getNoOfVertices() {
    return noOfVertices;
}
int Graph::getNoOfEdges() {
    return noOfEdges;
}

int Graph::getEdgeWeight(int u, int v) {
    return adjMat[u][v];
}

void Graph::dfs(int source) {
    if (source <0 || source >= noOfVertices) return;

    for (int i=0; i<noOfVertices; ++i)
        visited[i] = false;

    Stack<int> st(noOfVertices);
    st.push(source);

    while (st.size() > 0) {
        source = st.peek();
        st.pop();
        visited[source] = true;
        std::cout << source << " " ;

        for (int i=0; i<noOfVertices; ++i) {
            if (!isEdge(source, i))
                continue;
            else if (!visited[i]) {
                st.push(i);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::bfs(int source) {
    if (source <0 || source >= noOfVertices) return;

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
