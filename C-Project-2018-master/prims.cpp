#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

//directed graph
class Graph{
	int V;
	list<iPair> *adj;

	public:
		Graph(int N){
			V = N;
			adj = new list<iPair>[N];
		}
	
		void AddEdge(int u, int v, int w){// w=>weight
			adj[u].push_back(make_pair(v, w));
		}
		
		void MST(int s);//s => src
};


void Graph::MST(int s){
	int *parent = new int[V];
	int *wt = new int[V];
	
	priority_queue<iPair, vector<iPair>, greater<iPair> > PQ;//min priority queue
	
	for(int i=0; i<V; i++)
		wt[i] = INT_MAX;

	wt[s] = 0;
	PQ.push(make_pair(wt[s], s));
	
	while(!PQ.empty()){
		int u = PQ.top().second;
		PQ.pop();

		list<iPair>::iterator i;
		
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int v = (*i).first;
			int w = (*i).second;//w=>weight 
				

			if(wt[v] > w){
				wt[v] = w;
				parent[v] = u;
				PQ.push(make_pair(wt[v], v));
			}
			 
		}
	}
		
	for(int i=0; i<V; i++)
		printf("%d - %d = %d\n", parent[i], i, wt[i]);
}



int main(){
	Graph G(4);
	G.AddEdge(0, 1, 3);
	G.AddEdge(0, 3, 9);
	G.AddEdge(1, 2, 3);
	G.AddEdge(2, 3, 4);

	G.MST(0);
	return 0;
}


//working properly
