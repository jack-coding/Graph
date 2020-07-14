#pragma once
#define MaxSize 1024

typedef struct _Edge {	//��
	int adjIndex;		//�ڽӵ���±�
	int weight;			//�ߵ�Ȩ��
	struct _Edge *next;	//��һ����
}Edge;

typedef struct _Vertex {//����
	char data;			//����
	Edge* first;		//��һ����
}Vertex, AdjList;

class Graph
{
public:
	Graph();
	void Create();
	void showDFS();
	void showBFS();
	~Graph();

private:
	int Location(char data);

	void DFS(int index);//������ȱ���
	void DFS_all();//�����ж��������ȱ���

	void BFS(int index);//�����ȱ���
	void BFS_all();//�����ж�����й�ȱ���
	int vex_num;//��������
	int edge_num;//ͼ�ı���
	AdjList* adjList;//ͼ�����ж���
	bool visit[MaxSize];//�������״̬
};





