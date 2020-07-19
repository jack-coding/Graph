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
	cout << "������ͼ�ı����Լ�������:";
	cin >> this->edge_num >> this->vex_num;

	cout << "���������ж���:" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		cin >> this->adjList[i].data;
		this->adjList[i].first = nullptr;
	}

	cout << "���������й����ĵ��Լ��ߵ�Ȩ��:" << endl;
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

void Graph::DFS(int index) {//������ȱ���
	if (visit[index]) return;//����˵��Ѿ������ʹ���,�Ǿ�ֱ�ӷ���

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
	cout << "---------------������ȱ������----------------" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		if (this->visit[i] == false)
			DFS(i);
	}
	for (int i = 0; i < this->vex_num; ++i) {
		visit[i] = 0;
	}
}

void Graph::BFS(int index) {//������ȱ���
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
		while (temp) {//����ǰ����������ڵĽڵ��±����
			next_index = temp->adjIndex;
			q.push(next_index);
			temp = temp->next;
		}
	}
	
}

void Graph::BFS_all() {
	cout << "---------------������ȱ������----------------" << endl;
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
	for (int i = 0; i < this->vex_num;++i) {//��ɾ����
		Edge* temp = this->adjList[i].first;
		Edge* next = nullptr;
		while (temp) {
			next = temp->next;
			delete temp;
			temp = next;
		}
	}
	delete this->adjList;//��ɾ������
	cout << "����ͼ�ɹ�!" << endl;
}

void Graph::Search_shortestPath(int startLocation, int endLocation, int weights)//��Ѱ���·��
{
	if (startLocation < 0 || endLocation < 0)
		return;

	if (startLocation == endLocation) {//�Ѿ��ҵ��յ�,��ֹͣ����ͼ
		cout << "�ҵ����ܵ�·��Ϊ:";
		for (int i = 0; i < steps;i++) {
			cout << this->adjList[path[i]].data << "\t";
		}
		cout << "\t·��Ȩ��Ϊ:" << weights<<endl;

		if (weights < this->min_weight) {//�������·��
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
	cout << "���·��Ϊ:";
	int i = 0;
	while(i<MaxSize&&shortest_path[i]) {
		cout << this->adjList[shortest_path[i]].data << "\t";
		i++;
	}
	cout << "·��Ȩ��Ϊ:" << this->min_weight << endl;
}

void Graph::showDFS() {
	this->DFS_all();
}

void Graph::showBFS()
{
	this->BFS_all();
}
