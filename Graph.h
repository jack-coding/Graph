#pragma once
#define MaxSize 1024

typedef struct _Edge {	//边
	int adjIndex;		//邻接点的下标
	int weight;			//边的权重
	struct _Edge *next;	//下一条边
}Edge;

typedef struct _Vertex {//顶点
	char data;			//数据
	Edge* first;		//第一条边
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

	void DFS(int index);//顶点深度遍历
	void DFS_all();//对所有定点进行深度遍历

	void BFS(int index);//顶点广度遍历
	void BFS_all();//对所有顶点进行广度遍历
	int vex_num;//定点数量
	int edge_num;//图的边数
	AdjList* adjList;//图的所有定点
	bool visit[MaxSize];//顶点访问状态
};





