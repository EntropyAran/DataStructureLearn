// test2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "MaxHeap.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	MaxHeap<int> *heap = new MaxHeap<int>(10);
	srand(time(NULL));

	for (int i=0; i<30; i++)
	{
		heap->insert(rand()%100);
	}
	
	cout << heap->size() <<endl;
	heap->testPrint();
	system("pause");
	return 0;
}

