#include "Graph.h"
#include<iostream>
#include<queue>

using namespace std;


Graph::Graph()
{
	this->adjList = new Vertex[MaxSize];
	this->edge_num = 0;
	this->vex_num = 0;
	for (int i = 0; i < MaxSize; ++i) {
		this->visit[i] = false;
	}
}


Graph::~Graph()
{
}

void Graph::Create() {
	cout << "请输入图的边数以及顶点数:";
	cin >> this->edge_num >> this->vex_num;

	cout << "请输入所有顶点:" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		cin >> this->adjList[i].data;
		this->adjList[i].first = nullptr;
	}

	cout << "请输入所有关联的点:" << endl;
	char v1, v2;
	int v1_index, v2_index;
	for (int i = 0; i < this->edge_num; ++i) {
		cin >> v1 >> v2;
		v1_index = Location(v1);
		v2_index = Location(v2);
		if (v1_index != -1 && v2_index != -1) {
			Edge* tempEdge = new  Edge;
			tempEdge->adjIndex = v2_index;
			tempEdge->next = this->adjList[v1_index].first;
			this->adjList[v1_index].first = tempEdge;
		}
	}

}

int Graph::Location(char data) {
	for (int i = 0; i < this->vex_num; ++i) {
		if (this->adjList[i].data == data)
			return i;
	}
	return -1;
}

void Graph::DFS(int index) {//深度优先遍历
	if (visit[index]) return;//如果此点已经被访问过了,那就直接返回

	cout << this->adjList[index].data << " ";
	this->visit[index] = true;

	Edge* temp = this->adjList[index].first;
	int next_index;
	while (temp) {
		next_index = temp->adjIndex;
		if (!visit[next_index]) {
			DFS(next_index);
		}
		temp = temp->next;
	}
}

void Graph::DFS_all() {
	for (int i = 0; i < this->vex_num; ++i) {
		if (this->visit[i] == false)
			DFS(i);
	}
}

void Graph::BFS(int index) {//广度优先遍历
	if (this->visit[index])
		return;

	queue<int> q;

}

void Graph::BFS_all() {
	for (int i = 0; i < this->vex_num; ++i) {
		if (!visit[i])
			this->BFS(i);
	}
}

void Graph::showDFS() {
	this->DFS_all();
}

void Graph::showBFS()
{
}
#include "Graph.h"
#include<iostream>
#include<queue>

using namespace std;

Graph::Graph()
{
	this->adjList = new Vertex[MaxSize];
	this->edge_num = 0;
	this->vex_num = 0;
	for (int i = 0; i < MaxSize; ++i) {
		this->visit[i] = false;
	}
}


Graph::~Graph()
{
}

void Graph::Create() {
	cout << "请输入图的边数以及顶点数:";
	cin >> this->edge_num >> this->vex_num;

	cout << "请输入所有顶点:" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		cin >> this->adjList[i].data;
		this->adjList[i].first = nullptr;
	}

	cout << "请输入所有关联的点:" << endl;
	char v1, v2;
	int v1_index, v2_index;
	for (int i = 0; i < this->edge_num; ++i) {
		cin >> v1 >> v2;
		v1_index = Location(v1);
		v2_index = Location(v2);
		if (v1_index != -1 && v2_index != -1) {
			Edge* tempEdge = new  Edge;
			tempEdge->adjIndex = v2_index;
			tempEdge->next = this->adjList[v1_index].first;
			this->adjList[v1_index].first = tempEdge;
		}
	}

}

int Graph::Location(char data) {
	for (int i = 0; i < this->vex_num; ++i) {
		if (this->adjList[i].data == data)
			return i;
	}
	return -1;
}

void Graph::DFS(int index) {//深度优先遍历
	if (visit[index]) return;//如果此点已经被访问过了,那就直接返回

	cout << this->adjList[index].data << " ";
	this->visit[index] = true;

	Edge* temp = this->adjList[index].first;
	int next_index;
	while (temp) {
		next_index = temp->adjIndex;
		if (!visit[next_index]) {
			DFS(next_index);
		}
		temp = temp->next;
	}
}

void Graph::DFS_all() {
	for (int i = 0; i < this->vex_num; ++i) {
		if (this->visit[i] == false)
			DFS(i);
	}
}

void Graph::BFS(int index) {//广度优先遍历
	if (this->visit[index])
		return;

	queue<int> q;

}

void Graph::BFS_all() {
	for (int i = 0; i < this->vex_num; ++i) {
		if (!visit[i])
			this->BFS(i);
	}
}

void Graph::showDFS() {
	this->DFS_all();
}

void Graph::showBFS()
{
}