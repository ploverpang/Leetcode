#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Graph
{
public:
	Graph();
	void build_graph();
	void print_graph();
	void dfs_graph();
	void bfs_graph();
	~Graph();
//private:
	void insert_edge(int x, int y);
	void init_graph();
	void dfs_one_node(UndirectedGraphNode *node, map<int, bool> &visited, int &clock);
	void bfs_one_node(UndirectedGraphNode *node, map<int, bool> &visited, queue<int> &nodeQueue);

	//void destory_graph();

	map<int, UndirectedGraphNode*> verteces;
	vector<int> degree;

	int nVerteces;
	int nEdges;
};

void Graph::init_graph()
{
	nVerteces = 0;
	nEdges = 0;
}
Graph::Graph()
{
	init_graph();
}
Graph::~Graph()
{

}

void Graph::build_graph()
{
	cout << "Please input vertex number and edge number" << endl;
	cin >> nVerteces >> nEdges;

	int x, y;
	cout << "Please input every edge" << endl;
	for (int i = 0; i < nEdges; i++)
	{
		cin >> x >> y;
		insert_edge(x, y);
		insert_edge(y, x);
	}
}

void Graph::insert_edge(int x, int y)
{
	UndirectedGraphNode *p = nullptr;
	if (verteces.count(y) == 0)
	{
		p = new UndirectedGraphNode(y);
		verteces[y] = p;
	}
	else
	{
		p = verteces[y];
	}

	if (verteces.count(x) == 0)
	{
		verteces[x] = new UndirectedGraphNode(x);
	}
	verteces[x]->neighbors.push_back(p);
}

void Graph::print_graph()
{
	for (auto it = verteces.begin(); it != verteces.end(); it++)
	{
		UndirectedGraphNode *node= it->second;
		int label = it->first;
		cout << "Label " << label << ": ";
		for(auto it_vec = node->neighbors.begin(); it_vec != node->neighbors.end(); it_vec++)
		{
			cout << (*it_vec)->label << " ";
		}
		cout << endl;
	}
}

void Graph::dfs_one_node(UndirectedGraphNode *node, map<int, bool> &visited, int &clock)
{
	if(visited[node->label] == true)
	{
		return;
	}
	visited[node->label] = true;
	//cout << node->label << endl;
	cout << node->label << "begin :" << clock << endl;
	clock++;
	for (int i = 0; i < node->neighbors.size(); i++)
	{
		dfs_one_node(node->neighbors[i], visited, clock);	
	}
	cout << node->label << "end: " << clock << endl;
	clock++;
}

void dfs_one_node(UndirectedGraphNode *node, map<int, int> &visited) 
{
	if(visited.count(node->label) != 0)
	{
		return;
	}
	visited[node->label] ++;
	cout << node->label << endl;
	for (int i = 0; i < node->neighbors.size(); i++)
	{
		dfs_one_node(node->neighbors[i], visited);	
	}
}

void Graph::dfs_graph()
{
	map<int, bool> visited;
	for(auto it_map=verteces.begin(); it_map != verteces.end(); it_map++)
	{
		visited[it_map->first] = false;
	}
	int clock = 0;
	dfs_one_node(verteces.begin()->second, visited, clock);
}

void Graph::bfs_one_node(UndirectedGraphNode *node, map<int, bool> &visited, queue<int> &nodeQueue)
{
	if (visited[node->label] == false)
	{
		cout << node->label << endl;
		visited[node->label] = true;
	}
	for (int i = 0; i < node->neighbors.size(); i++)
	{
		if (visited[node->neighbors[i]->label] == false)
		{
			cout << node->neighbors[i]->label << endl;
			visited[node->neighbors[i]->label] = true;
			nodeQueue.push(node->neighbors[i]->label);
		}
	}
	while (nodeQueue.empty() == false)
	{
		int nodeLabel = nodeQueue.front();
		nodeQueue.pop();
		bfs_one_node(verteces[nodeLabel], visited, nodeQueue); 
	}
}


void Graph::bfs_graph()
{
	map<int, bool> visited;
	queue<int> nodeQueue;
	for(auto it_map=verteces.begin(); it_map != verteces.end(); it_map++)
	{
		visited[it_map->first] = false;
	}
	bfs_one_node(verteces.begin()->second, visited, nodeQueue);
}
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		UndirectedGraphNode* cloned = NULL;
		map<int, UndirectedGraphNode*> recodeMap;
		queue<UndirectedGraphNode*> nodeQueue;
		map<int, int> visited;
		processOneNode(node, cloned, visited, nodeQueue, recodeMap);
		return cloned;
    }

	void processOneNode(UndirectedGraphNode* node, 
		UndirectedGraphNode* &cloned,
		map<int, int> &visited, 
		queue<UndirectedGraphNode*> &nodeQueue,
		map<int, UndirectedGraphNode*> &recodeMap)
	{
		if (node == NULL)
		{
			cloned = NULL;
			return;
		}	
		if(visited.count(node->label) == 0)
		{
			visited[node->label]++ ;
			if (recodeMap.count(node->label) == 0)
			{
				cloned = new UndirectedGraphNode(node->label);
				recodeMap[node->label] = cloned;
			}
		}
		
		for (int i = 0; i < node->neighbors.size(); i++)
		{
			if (recodeMap.count(node->neighbors[i]->label) == 0)
			{
				// New a node if the leighbor doesn't exist
				UndirectedGraphNode *p = new UndirectedGraphNode(node->neighbors[i]->label);
				recodeMap[node->neighbors[i]->label] = p;

				cloned->neighbors.push_back(p);
			}	
			else
			{
				cloned->neighbors.push_back(recodeMap[node->neighbors[i]->label]);
			}

			if (visited.count(node->neighbors[i]->label) == 0)
			{
				visited[node->neighbors[i]->label]++;
				nodeQueue.push(node->neighbors[i]);
			}
		}	

		while (!nodeQueue.empty())
		{
			UndirectedGraphNode *popedNode = nodeQueue.front();
			nodeQueue.pop();
			processOneNode(popedNode, recodeMap[popedNode->label], visited, nodeQueue, recodeMap); 
		}
	}
};

/*
int main()
{
	Graph g;
	g.build_graph();
	g.print_graph();
	//g.dfs_graph();
	//g.bfs_graph();
	Solution sln;
	UndirectedGraphNode *cloned = 
		sln.cloneGraph(g.verteces.begin()->second);

	map<int, int> visited;
	dfs_one_node(cloned,visited);
	system("PAUSE");
	return 0;
}
*/