#include "Graph.h"
#include<iostream>
#include<queue>

using namespace std;

Graph::Graph():visit{false},min_weight(0x7FFFFFF),shortest_path{0},steps(0),path{0}
{
	this->adjList = new Vertex[MaxSize];
	this->edge_num = 0;
	this->vex_num = 0;
}


Graph::~Graph()
{
	this->DistroyGraph();
}

void Graph::Create() {
	cout << "请输入图的边数以及顶点数:";
	cin >> this->edge_num >> this->vex_num;

	cout << "请输入所有顶点:" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		cin >> this->adjList[i].data;
		this->adjList[i].first = nullptr;
	}

	cout << "请输入所有关联的点以及边的权重:" << endl;
	char v1, v2;
	int v1_index, v2_index,weight;
	for (int i = 0; i < this->edge_num; ++i) {
		cin >> v1 >> v2>> weight;
		v1_index = Location(v1);
		v2_index = Location(v2);
		if (v1_index != -1 && v2_index != -1) {
			Edge* tempEdge = new  Edge;
			tempEdge->weight = weight;
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
	cout << "---------------深度优先遍历结果----------------" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		if (this->visit[i] == false)
			DFS(i);
	}
	for (int i = 0; i < this->vex_num; ++i) {
		visit[i] = 0;
	}
}

void Graph::BFS(int index) {//广度优先遍历
	if (this->visit[index])
		return;

	queue<int> q;
	int cur_index=index;
	int next_index=-1;

	q.push(index);
	while (!q.empty()) {
		cur_index = q.front();
		if (visit[cur_index] == false) {
			cout << this->adjList[cur_index].data << " ";
			visit[cur_index] = true;
		}

		q.pop();
		Edge* temp = this->adjList[cur_index].first;
		while (temp) {//将当前点的所有相邻的节点下标入队
			next_index = temp->adjIndex;
			q.push(next_index);
			temp = temp->next;
		}
	}
	
}

void Graph::BFS_all() {
	cout << "---------------广度优先遍历结果----------------" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		if (!visit[i])
			this->BFS(i);
	}
	for (int i = 0; i <this->vex_num;++i ) {
		visit[i] = 0;
	}
}

void Graph::DistroyGraph()
{
	for (int i = 0; i < this->vex_num;++i) {//先删除边
		Edge* temp = this->adjList[i].first;
		Edge* next = nullptr;
		while (temp) {
			next = temp->next;
			delete temp;
			temp = next;
		}
	}
	delete this->adjList;//再删除顶点
	cout << "销毁图成功!" << endl;
}

void Graph::Search_shortestPath(int startLocation, int endLocation, int weights)//搜寻最短路径
{
	if (startLocation < 0 || endLocation < 0)
		return;

	if (startLocation == endLocation) {//已经找到终点,则停止遍历图
		cout << "找到可能的路径为:";
		for (int i = 0; i < steps;i++) {
			cout << this->adjList[path[i]].data << "\t";
		}
		cout << "\t路径权重为:" << weights<<endl;

		if (weights < this->min_weight) {//更新最短路径
			this->min_weight = weights;
			memcpy(shortest_path,path,sizeof(int)*steps);
		}

		return;
	}
	int cur = startLocation;

	visit[startLocation] = true;
	Edge* temp = this->adjList[cur].first;
	
	while (temp) {
		int weight = temp->weight;
		cur = temp->adjIndex;
	
		if (visit[cur]==false) {
			visit[cur] = true;
			path[steps++] = cur;
			Search_shortestPath(cur, endLocation, weights + weight);
			visit[cur] = false;
			path[--steps] =0;
		}
		temp = temp->next;
	}

}

void Graph::find_shortestpath(int startLocation, int endLocation, int weights)
{
	this->Search_shortestPath(startLocation,  endLocation,  weights);
	cout << "最短路径为:";
	int i = 0;
	while(i<MaxSize&&shortest_path[i]) {
		cout << this->adjList[shortest_path[i]].data << "\t";
		i++;
	}
	cout << "路径权重为:" << this->min_weight << endl;
}

void Graph::showDFS() {
	this->DFS_all();
}

void Graph::showBFS()
{
	this->BFS_all();
}
