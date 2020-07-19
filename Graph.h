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
	~Graph();
	void Create();
	void showDFS();
	void showBFS();
	void DistroyGraph();//����ͼ
	void Search_shortestPath(int startLocation, int endLocation, int weights);
	void find_shortestpath(int startLocation, int endLocation, int weights);
	int Location(char data);

private:
	void DFS(int index);//������ȱ���
	void DFS_all();//�����ж��������ȱ���
	void BFS(int index);//�����ȱ���
	void BFS_all();//�����ж�����й�ȱ���
	int vex_num;//��������
	int edge_num;//ͼ�ı���
	AdjList* adjList;//ͼ�����ж���
	bool visit[MaxSize];//�������״̬
	int min_weight;//��С·��Ȩ��
	int shortest_path[MaxSize];//�������·�����±�
	int path[MaxSize];//�����߹���·���±�
	int steps;//�߹��Ĳ���;
};





