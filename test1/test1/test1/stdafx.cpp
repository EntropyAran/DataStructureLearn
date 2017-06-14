// stdafx.cpp : 只包括标准包含文件的源文件
// test1.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "test.h"

using namespace std;

//插入排序函数
template<typename T>
void InsertSort( T arr[], int n)
{
	T temp;

	for ( int i=0; i<n; i++)
	{
		int j;
		temp = arr[i];
		for ( j=i; j>0 && temp < arr[j-1]; j--)
			arr[j] = arr[j-1];

		arr[j] = temp;
	}

	return;
}

//选择排序函数
template<typename T>
void SelectionSort( T arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		int minindex = i;
		for(int j=i+1; j<n; j++)
			if( arr[j] < arr[minindex])
				minindex = j;

		swap(arr[i],arr[minindex]);
	}

	return;
}


int main()
{
	using namespace test1;
	int num = 100000;
	int* arr1 = new int[num];
	GenerateIntTestArray(arr1, num, 0, num);

	int* arr2 = new int[num];
	CopyArray(arr1,arr2,num);

	SortTestor("InsertSort", InsertSort, arr1, num);
	SortTestor("SelectionSort", SelectionSort, arr2, num);
	//PrintArr(arr, num);

	delete []arr1;arr1 = NULL;
	delete []arr2;arr2 = NULL;
	system("pause");
	return 1;
}
// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用
