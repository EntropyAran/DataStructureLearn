// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// test1.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

#include "test.h"
#include "Sort.h"

using namespace std;



int main()
{
	using namespace test1;
	int num = 1000;
	int* arr1 = new int[num];GenerateIntTestArray(arr1, num, 0, num);
	int* arr2 = new int[num];CopyArray(arr1,arr2,num);
	int* arr3 = new int[num];CopyArray(arr1,arr3,num);
	int* arr4 = new int[num];CopyArray(arr1,arr4,num);
	int* arr5 = new int[num];CopyArray(arr1,arr5,num);
	int* arr6 = new int[num];CopyArray(arr1,arr6,num);
	int* arr7 = new int[num];CopyArray(arr1,arr7,num);
	int* arr8 = new int[num];CopyArray(arr1,arr8,num);

	//testSort("InsertSort", InsertSort, arr1, num);
	//testSort("SelectionSort", SelectionSort, arr2, num);
	//testSort("BubbleSort", BubbleSort, arr3, num);
	testSort("ShellSort", ShellSort, arr4, num);
	testSort("MergeSort", MergeSort, arr5, num);
	testSort("QuickSort", QuickSort2, arr6, num);
	testSort("HeapSort1", HeapSort1, arr7, num);
	testSort("HeapSort2", HeapSort2, arr8, num);
	//PrintArr(arr, num);

	delete []arr1;arr1 = NULL;
	delete []arr2;arr2 = NULL;
	delete []arr3;arr3 = NULL;
	delete []arr4;arr4 = NULL;
	delete []arr5;arr5 = NULL;
	delete []arr6;arr6 = NULL;
	delete []arr7;arr7 = NULL;
	delete []arr8;arr8 = NULL;
	system("pause");
	return 1;
}
// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
