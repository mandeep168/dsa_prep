#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
	int V; //number of vertices 
	list<int> *l;
public:
	Graph(int v){
		V = v;

		//V number of linked lists
		l = new list<int> [V];
	}
	//creates a list of lists

	void addEdge(int i,int j,bool undirected = true){
		l[i].push_back(j);
		if(undirected){
			l[j].push_back(i);
		}
	}

	//level order traversal
	void bfs(int source){

		queue<int> q;
		bool *visited = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V]{0};

		for(int i=0;i<V;i++){
			parent[i] = -1;
		}

		q.push(source);
		visited[source] = true;
		parent[source] = source;
		dist[source] = 0;

		while(!q.empty()){
			int f = q.front();
			cout<<f<<"\n";
			q.pop();

			//push the nbrs if not already visited
			for(auto nbr : l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;

					//parent and distance
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
				}
			}
		}

	}

	//depth first search
	void dfs(int source){
		bool *visited = new bool[V]{0};
		dfsHelper(source, visited);
		cout<<"\n";
	}

	void dfsHelper(int source, bool* visited){
		visited[source] = 1;
		cout<<source<<"-->";

		for(auto nbr : l[source]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return;
		
	}

	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			for(auto node:l[i]){
				cout<<node<<",";
			}cout<<"\n";
		}
	}
};

// class Node{
// public:
// 	string name;
// 	list<string> nbrs;

// 	Node(string name){
// 		this->name = name;
// 	}
// };

// class Graph{
// 	//hashmap
// 	unordered_map<string, Node*> m;
// public:
// 	Graph(vector<string> cities){
// 		for(auto city:cities){
// 			m[city] = new Node(city);
// 		}
// 	}

// 	void addEdge(string x,string y,bool undir = true){
// 		m[x] -> nbrs.push_back(y);
// 		if(undir){
// 			m[y] -> nbrs.push_back(x);
// 		}
// 	}

// };

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);

	// g.bfs(1);
	g.dfs(1);
	// g.printAdjList();


}