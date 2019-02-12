#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

class Vertex
{
public:

    Vertex () {
        this->value = 0;
        this->weight = 0;
    }

    Vertex (int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
    virtual ~Vertex () {
    }
    void setValue(int value) {
        this-> value = value;
    }
    void setWeight(int weight) {
        this-> weight = weight;
    }
    int getValue() const {
        return value;
    }
    int getWeight() const {
        return weight;
    }
    Vertex operator=(const Vertex& v) {
        setValue(v.getValue());
        setWeight(v.getWeight());
        return v;
    }
    bool operator==(const Vertex& v) {
        if (this->value!=v.getValue()) return false;
        if (this->weight!=v.getWeight()) return false;
        return true;
    }
    bool operator!=(const Vertex& v) {
        if (this->operator==(v)) return false;
        else return true;
    }

private:
    int value;
    int weight;
};

class Graph {
public:
    Graph(bool, int, int);
    ~Graph();
    LinkedList<Vertex> getNeighbours(int u);
    bool isEdge(int u, int v);
    void addEdge(int u, int v, int w);
    void removeEdge(int u, int v);
    int getDegree(int u);
    int getNoOfVertices();
    int getNoOfEdges();
    int getEdgeWeight(int u, int v);
    void dfs(int source);
    void bfs(int source);

private:
    bool isDirected;
    int noOfVertices;
    int noOfEdges;
    LinkedList<Vertex> * arr;
    bool * visited;
};

Graph::Graph(bool isDirected, int noOfVertices, int noOfEdges) {
    this->isDirected = isDirected;
    this->noOfVertices = noOfVertices;
    this->noOfEdges = noOfEdges;
    arr = new LinkedList<Vertex>[noOfVertices];
    visited = new bool[noOfVertices];
}

Graph::~Graph() {
    if (arr)
        delete [] arr;
}

LinkedList<Vertex> Graph::getNeighbours(int u) {
    return arr[u];
}

bool Graph::isEdge(int u, int v) {
    LinkedList<Vertex> neighbours = getNeighbours(u);
    Node<Vertex>* root = neighbours.getRoot();
    if (root==NULL) return false;
    if (root->getValue().getValue() == v)
        return true;

    Node<Vertex> *currentNode = root;
    while (currentNode->getNext() != NULL) {
        currentNode = currentNode->getNext();
        if (currentNode->getValue().getValue() == v)
            return true;
    }
    return false;
}

void Graph::addEdge(int u, int v, int w) {
    Vertex *tmp = new Vertex(v, w);
    if (!isEdge(u, v)) {
        arr[u].add(*tmp);
    }
    tmp = NULL;
    if (!isDirected && !isEdge(v, u)) {
        tmp = new Vertex(u, w);
        arr[v].add(*tmp);
        tmp = NULL;
    }
}

void Graph::removeEdge(int u, int v) {
    Node<Vertex>* root = arr[u].getRoot();
    if (root==NULL) return ;
    if (root->getValue().getValue() == v) {
        Vertex *vert = new Vertex( v, root->getValue().getWeight() );
        arr[u].remove(*vert);
    }
    if (isDirected) return;
    root = arr[v].getRoot();
    if (root==NULL) return ;
    if (root->getValue().getValue() == u) {
        Vertex *vert = new Vertex( u, root->getValue().getWeight() );
        arr[v].remove(*vert);
    }
}

int Graph::getNoOfVertices() {
    return noOfVertices;
}

int Graph::getNoOfEdges() {
    return noOfEdges;
}

int Graph::getEdgeWeight(int u, int v) {
    Node<Vertex> *currentNode = arr[u].getRoot();
    while (currentNode!=NULL) {
        if (currentNode->getValue().getValue() == v)
            return currentNode->getValue().getWeight();
        currentNode = currentNode->getNext();
    }
    return 0;
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
