#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	void addEdge(int v, int w);

	void BFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int v)
{			
	list<int> queue;
  	queue.push_back(v);
  	visited[v] = true;

  	list<int>::iterator i;

  	while (!queue.empty()) 
	{
    	int currVertex = queue.front();
    	cout << currVertex << " "; 
    	queue.pop_front();

    	for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i) 
		{
//      		int adjVertex = *i;
      		if (!visited[*i]) 
			{
        		visited[*i] = true;
        		queue.push_back(*i);
      		}
      	}
    }
}

int main()
{
	int e, u, v;
	Graph g;
	cout << "Enter no of edges : ";
	cin >> e;
	for(int i = 0; i < e; i++)
	{
		cout<<"Enter from"<<endl;
		cin>>u;
		cout<<"Enter To"<<endl;
		cin>>v;
		g.addEdge(u,v);
		g.addEdge(v,u);
	}
	
	cout << "Enter the starting index : ";
	int startIndex;
	cin >> startIndex;
	cout << "Following is Breadth First Traversal" << endl;
	g.BFS(startIndex);

	return 0;
}

