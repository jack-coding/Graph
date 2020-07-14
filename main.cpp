#include<iostream>
#include<Windows.h>
#include"Graph.h"

using namespace std;


int main(int argc, char * argv) {
	Graph g1;
	g1.Create();
	g1.showBFS();
	system("pause");
	return EXIT_SUCCESS;
}