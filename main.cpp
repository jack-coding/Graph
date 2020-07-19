#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>

#ifdef  _DEBUG
#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ ,__LINE__)
#define new DBG_NEW 
#endif #endif
#endif #endif

#include<iostream>
#include<Windows.h>
#include"Graph.h"

using namespace std;

int main(int argc, char * argv) {
	{
		Graph g1;
		g1.Create();
		g1.showBFS();
		char v1, v2;
		cout << "\n请输入起点以及终点:";
		cin >> v1 >> v2;
		g1.find_shortestpath(g1.Location(v1), g1.Location(v2), 0);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return EXIT_SUCCESS;
}