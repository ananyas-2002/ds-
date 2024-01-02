#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{			
	stack<int> stack; 
    stack.push(v); 
  	
  	list<int>::iterator i;
    while (!stack.empty()) 
    { 
        v = stack.top(); 
        stack.pop(); 
        if (!visited[v]) 
        { 
            cout << v << " "; 
            visited[v] = true; 
        } 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) 
                stack.push(*i); 
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
	cout << "Following is Depth First Traversal" << endl;
	g.DFS(startIndex);

	return 0;
}

