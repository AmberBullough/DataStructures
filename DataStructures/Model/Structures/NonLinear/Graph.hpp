//
//  Graph.hpp
//  DataStructures
//
//  Created by Bullough, Amber on 3/19/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <assert.h>
#include <queue>
#include <set>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix[MAXIMUM] [MAXIMUM];
    int weightCostMatrix [MAXIMUM] [MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> & graph, int vertex, bool markedVerticies[]);
    
public:
    Graph();
    // Graph Operations
    
    void addVertex(const Type& value);
    
    //Connect Verticies
    void addEdge(int source, int target);
    void addEdgeUndirected(int source, int target);
    void addEdgeCost(int source, int target, int cost);
    //Disconnect Verticies
    void removeEdge(int source, int target);
    void removeEdgeUndirected(int source, int target);
    void removeEdgeCost(int source, int target);
    
    //Accessors
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    
    //Check connections
    bool hasUndirectedConnection(int source, int target) const;
    bool areConnected(int source, int target) const;
    std::set<int> neightbors(int vertex) const;
    
    // Transversals
    void dephFirstTranversal(Graph<Type> & currentGraph, int vertex);
    void breadtheFirstTransversia(Graph<Type> & currentGraph, int vertex);
    int costTraversal(Graph<Type> & currentGraph, int vertex);
};

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
    this-> vertexCount = 0;

}

    /*
     Since we cannot "remove: from an array in C++,
     we only implement adding to a graph.
     Java allowed for all objects to be set to null
     but C++ does not.
     */
template <class Type>
int Graph<Type> :: size() const
{
    return vertexCount;
}

//Left hand side operator
template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

// Right hand side operator
template <class Type>
Type Graph<Type> :: operator[] (int vertex) const
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(vertexCount < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber] [newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
    graphData[newVertexNumber] = value;
}

template<class Type>
void Graph<Type> :: removeEdge(int source, int target)
    {
        assert(source >= 0 && source < vertexCount && target>= 0 && target < vertexCount);
        adjacencyMatrix[source][target] = false;
    }
template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][source] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeCost(int source,int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weightCostMatrix[source][target] = 0;
    weightCostMatrix[target][source] = 0;
}

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = true;
}
template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target, int cost)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target <vertexCount);
    weightCostMatrix[source][target] = cost;
    weightCostMatrix[target][source]= cost;
}

template <class Type>
void Graph<Type> :: addEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}

template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
    assert(source >=0 && source < vertexCount && target >= 0 && target < vertexCount);
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}

template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target];
    
    return isAnEdge;
}

template <class Type>
std::set<int>Graph<Type> :: neightbors(int vertex) const
{
    assert(vertex < vertexCount);
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < vertexCount; index ++)
    {
        if(adjacencyMatrix[vertex][index])
        {
            vertexNeighbors.insert(index);
        
        }
        return vertexNeighbors;
    }
}

template <class Type>
void Graph<Type> :: dephFirstTranversal(Graph<Type> & currentGraph, int vertex)
{
    bool visitedVerticies[MAXIMUM];
    assert(vertex < currentGraph.size());
    std::fill_n(visitedVerticies, currentGraph.size(), false);
    dephFirstTranversal(currentGraph, vertex, visitedVerticies);
    
}

template <class Type>
void Graph<Type>:: depthFirstTraversal(Graph<Type> & currentGraph , int vertex, bool * visited)
{
    std::set<int> connections = currentGraph.neightbors(vertex);
    std::set<int> :: iterator setInterator;
    
    visited[vertex] = true;
    cout << currentGraph[vertex] << ", " << endl;
    
    for(setInterator = connections.begin();setInterator != connections.end(); setInterator++)
    {
        if(!visited[*setInterator])
        {
            dephFirstTranversal(currentGraph, *setInterator, visited);
        }
    }
}

template <class Type>
void Graph <Type> :: breadtheFirstTransversia(Graph<Type> & currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited,currentGraph.size(),false);
    visited[vertex] = true;
    cout<< currentGraph[vertex]<< endl;
    vertexQueue.push(vertex);
    while(!vertexQueue.empty())
    {
        connections = currentGraph.neightbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                visited[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator);
        }
            
}
        
template <class Type>
int Graph<Type> :: costTraversal(Graph<Type> & currentGraph, int start)
{
    asstert(start>= 0 && start <vertexCount);
    int cost = 0;
    bool visited[MAXIMUM];
    std::set<int>connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    std::fill_n(visited,currentGraph.size(), false);
    visited[start]= true;
    
    vertexQueue.push(start);
    while(!vertexQueue.empty())
    {
        int currentIndex = vertexQueue.front();
        connections = currentGraph.neightbors(currentIndex);
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                cost += weightCostMatrix[currentIndex][*setIterator];
                visited[*setIterator] = true;
                vertexQueue.push(*setIterator);
            }
        }
    }
    return cost;
}



#endif /* Graph_hpp */
