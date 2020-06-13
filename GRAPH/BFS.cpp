#include<iostream>
#include<list>
using namespace std;

class DiGraph
{
    int numVertices;       //no. of vertices
    std::list<int>*adj;           //adj is a pointer to a list of integers

public:
    DiGraph(int V);
    void addEdge(int v1,int v2);      //add edge from vertex v1 to v2
    void BFS(int start_vertex);     //traversal starting with starting node
};

DiGraph::DiGraph(int V)
{
    numVertices=V;
    adj=new list<int>[V];           //adj is changed to an array
                                  //now adj is an array which has adj list at each index
}

void DiGraph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
}

void DiGraph::BFS(int start_vertex)
{
    bool *visited=new bool[numVertices];
    for(int i{0};i<numVertices;i++)
        visited[i]=false;

    list<int>Queue;

    visited[start_vertex]=true;
    Queue.push_back(start_vertex);

    list<int>::iterator it;

    while(!Queue.empty())
    {
        int curr_vertex=Queue.front();
        cout<<"VISITED "<<curr_vertex<<" ";
        Queue.pop_front();

        for (it=adj[curr_vertex].begin();it!=adj[curr_vertex].end();it++)
        {
            int adjVertex=*it;
            if(!visited[adjVertex])
            {
                visited[adjVertex]=true;
                Queue.push_back(adjVertex);
            }
        }

    }
}

int main()
{
  DiGraph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);
}

