// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// test1.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "test.h"

using namespace std;

//����������
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

//ѡ��������
template<typename T>
void SelectionSort( T arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int minindex = i;
		for(int j=i+1; j<n; j++)
			if( arr[j] < arr[minindex])
				minindex = j;

		swap(arr[i],arr[minindex]);
	}

	return;
}

template<typename T>
void BubbleSort( T arr[], int n)
{
	for(int i=1; i<n; i++)
		for(int j=0; j<n-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
}

int main()
{
	using namespace test1;
	int num = 10000;
	int* arr1 = new int[num];
	GenerateIntTestArray(arr1, num, 0, num);

	int* arr2 = new int[num];
	CopyArray(arr1,arr2,num);

	int* arr3 = new int[num];
	CopyArray(arr1,arr3,num);

	SortTestor("InsertSort", InsertSort, arr1, num);
	SortTestor("SelectionSort", SelectionSort, arr2, num);
	SortTestor("BubbleSort", BubbleSort, arr3, num);
	//PrintArr(arr, num);

	delete []arr1;arr1 = NULL;
	delete []arr2;arr2 = NULL;
	delete []arr3;arr3 = NULL;
	system("pause");
	return 1;
}
// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
