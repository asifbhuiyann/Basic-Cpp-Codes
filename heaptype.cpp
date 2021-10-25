#include "graphtype.h"
#include "stacktype.cpp"
#include "quetype.cpp"
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
const int NULL_EDGE = 0;
template<class VertexType>
GraphType<VertexType>::GraphType()
{
    numVertices = 0;
    maxVertices = 50;
    countMarkedVertices = 0;
    cycle = false;
    vertices = new VertexType[50];
    edges = new int*[50];
    for(int i=0; i<50; i++)
        edges[i] = new int [50];
    marks = new bool[50];
}
template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new int*[maxV];
    for(int i=0; i<maxV; i++)
        edges[i] = new int [maxV];
    marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete [] vertices;
    delete [] marks;
    for(int i=0; i<maxVertices; i++)
        delete [] edges[i];
    delete [] edges;
}
template<class VertexType>
void GraphType<VertexType>::MakeEmpty()
{
    numVertices = 0;
}
template<class VertexType>
bool GraphType<VertexType>::IsEmpty()
{
    return (numVertices == 0);
}
template<class VertexType>
bool GraphType<VertexType>::IsFull()
{
    return (numVertices == maxVertices);
}
template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType
                                      vertex)
{
    vertices[numVertices] = vertex;
    for (int index=0; index<numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType
            vertex)
{
    int index = 0;
    while (!(vertex == vertices[index]))
        index++;
    return index;
}
template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
    for(int i=0; i<maxVertices; i++)
        marks[i] = false;
}
template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType
                                       vertex)
{
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
    countMarkedVertices++;
}
template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType
                                     vertex)
{
    int index = IndexIs(vertices, vertex);
    return marks[index];
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
    int row = IndexIs(vertices, fromVertex);
    int col= IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}
template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
{
    int row = IndexIs(vertices, fromVertex);
    int col= IndexIs(vertices, toVertex);
    if(edges[row][col]!=0)
        return edges[row][col];
    else return 1e9;
}
template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, QueType<VertexType>& adjVertices)
{
    int fromIndex, toIndex;
    fromIndex = IndexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
}
template<class VertexType>
void
GraphType<VertexType>::DepthFirstSearch(VertexType startVertex, VertexType endVertex)
{
    StackType<VertexType> stack;
    QueType<VertexType> vertexQ;
    bool found = false;
    countMarkedVertices = 0;
    VertexType vertex, item;
    ClearMarks();
    stack.Push(startVertex);
    do
    {
        vertex = stack.Top();
        stack.Pop();
        if (vertex == endVertex)
        {
           // cout << vertex << " ";
            found = true;
        }
        else
        {
            if (!IsMarked(vertex))
            {
                MarkVertex(vertex);
             //   cout << vertex << " ";
                GetToVertices(vertex,vertexQ);
                while (!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if (!IsMarked(item))
                        stack.Push(item);
                }
            }
            else cycle = true;
        }
    }
   while (!stack.IsEmpty() && !found);
    cout << endl;
   // if (!found)
       // cout << "Path not found." << endl;
}

template<class VertexType>
void
GraphType<VertexType>::BreadthFirstSearch(VertexType startVertex, VertexType endVertex)
{
    QueType<VertexType> queue;
    QueType<VertexType> vertexQ;
    int cost[numVertices];
    memset(cost,0,sizeof(cost));
    bool found = false;
    VertexType vertex, item;
    ClearMarks();
    queue.Enqueue(startVertex);
    do
    {
        queue.Dequeue(vertex);
        if (vertex == endVertex)
        {
           // cout << vertex << " ";
            found = true;
        }
        else
        {
            if (!IsMarked(vertex))
            {
                MarkVertex(vertex);
              //  cout << vertex << " ";
                GetToVertices(vertex, vertexQ);
                while (!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if (!IsMarked(item))
                        queue.Enqueue(item);
                }
            }
        }
    }
    while (!queue.IsEmpty() && !found);
    cout << endl;
  //  if (!found)
     //   cout << "Path not found." << endl;
}

template<class VertexType>
int
GraphType<VertexType>:: dijkstraMDist(VertexType startVertex, VertexType endVertex)
{

    int inf = 1e9;
    int dist[numVertices];


    bool visited[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
        dist[i] = inf;
    }
    int index = IndexIs(vertices,startVertex);

    dist[index] = 0;
    VertexType current = startVertex;


    QueType<VertexType> vertexQ;
    unordered_set<VertexType> sett;
    while (true)
    {


        visited[index] = true;

        GetToVertices(current, vertexQ);
        while (!vertexQ.IsEmpty())
        {
            VertexType item;
            vertexQ.Dequeue(item);
            int x=IndexIs(vertices,item);

            if (visited[x])
                continue;

            sett.insert(item);
            int alt = dist[index] + WeightIs(current, item);

            if (alt < dist[x])
            {
                dist[x] = alt;

            }
        }


        sett.erase(current);
        if (sett.empty())
            break;

        // The new current
        int minDist = inf;
        //  cout<<minDist<<endl;
        int index2 = 0;
        VertexType now ='A' ;

        // Loop to update the distance
        // of the vertices of the graph
        for (VertexType a: sett)
        {
            // cout<<a<<endl;
            int index1 = IndexIs(vertices,a);
            if (dist[index1] < minDist)
            {
                minDist = dist[index1];
                index2 = index1;
                now=a;

            }
        }

        current = now;
        index = IndexIs(vertices,current);
    }

    return dist[IndexIs(vertices,endVertex)];
}

template<class VertexType>
int
GraphType<VertexType>:: dijkstraLDist(VertexType startVertex, VertexType endVertex)
{

    int inf = 0;
    int neg = -1;
    int dist[numVertices];


    bool visited[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
        dist[i] = neg;
    }
    int index = IndexIs(vertices,startVertex);
///////see
    dist[index] = inf;
    VertexType current = startVertex;


    QueType<VertexType> vertexQ;
    unordered_set<VertexType> sett;
    while (true)
    {


        visited[index] = true;

        GetToVertices(current, vertexQ);
        while (!vertexQ.IsEmpty())
        {
            VertexType item;
            vertexQ.Dequeue(item);
            int x=IndexIs(vertices,item);

            if (visited[x])
                continue;

            sett.insert(item);
            int alt = dist[index] + WeightIs(current, item);

            if (alt > dist[x])
            {
                dist[x] = alt;

            }
        }


        sett.erase(current);
        if (sett.empty())
            break;

        // The new current
        int minDist = neg;
        //  cout<<minDist<<endl;
        int index2 = 0;
        VertexType now ='A' ;

        // Loop to update the distance
        // of the vertices of the graph
        for (VertexType a: sett)
        {
            // cout<<a<<endl;
            int index1 = IndexIs(vertices,a);
            if (dist[index1] > minDist)
            {
                minDist = dist[index1];
                index2 = index1;
                now=a;

            }
        }

        current = now;
        index = IndexIs(vertices,current);
    }

    return dist[IndexIs(vertices,endVertex)];
}



template<class VertexType>
bool
GraphType<VertexType>::checkStCntd(VertexType u,VertexType v)
{
    countMarkedVertices = 0;
    DepthFirstSearch(u,v);
    //cout<<countMarkedVertices<<endl;
    return (countMarkedVertices==numVertices-1) ;
}

template<class VertexType>
bool
GraphType<VertexType>::checkCycle(VertexType u,VertexType v)
{
    cycle = false;
    DepthFirstSearch(u,v);
    return cycle;
}

template<class VertexType>
bool GraphType<VertexType>::FoundEdge(VertexType u, VertexType v)
{
    int row = IndexIs(vertices, u);
    int col= IndexIs(vertices,v);

    return edges[row][col]==1;
}
template<class VertexType>
int GraphType<VertexType>:: OutDegree(VertexType v)
{
    int cnt=0;
    int row = IndexIs(vertices, v);
    for (int index=0; index<numVertices; index++)
    {
        if(edges[row][index]==1)cnt++;
    }
    return cnt;
}
