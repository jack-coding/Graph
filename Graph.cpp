#include "Graph.h"
#include<iostream>
#include<queue>

using namespace std;


Graph::Graph():visit{false}
{
	this->adjList = new Vertex[MaxSize];
	this->edge_num = 0;
	this->vex_num = 0;
}


Graph::~Graph()
{
	
}

void Graph::Create() {
	cout << "������ͼ�ı����Լ�������:";
	cin >> this->edge_num >> this->vex_num;

	cout << "���������ж���:" << endl;
	for (int i = 0; i < this->vex_num; ++i) {
		cin >> this->adjList[i].data;
		this->adjList[i].first = nullptr;
	}

	cout << "���������й����ĵ�:" << endl;
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

void Graph::showDFS() {
	this->DFS_all();
}

void Graph::showBFS()
{
	this->BFS_all();
}
