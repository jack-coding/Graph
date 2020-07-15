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
	Graph g1;
	g1.Create();
	g1.showBFS();
	g1.DistroyGraph();

	_CrtDumpMemoryLeaks();
	system("pause");
	return EXIT_SUCCESS;
}