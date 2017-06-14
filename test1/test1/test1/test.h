
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <string>
#include <iomanip>
using namespace std;

namespace test1
{
	//产生整型测试序列
	void GenerateIntTestArray( int* det_p , int num, int RangeL, int RangeR )
	{
		//assert( RangeL > RangeR );

		int* arr = new int[num];
		srand(time(NULL));
		for ( int i=0; i < num; i++ )
			arr[i] = rand() % ( RangeR - RangeL + 1 ) + RangeL;

		copy( arr, arr+num, det_p );
		delete []arr;arr = NULL;

		return;
	}

	//测试排序的正确性
	template<typename T>
	bool IsSorted( T arr[], int num)
	{
		for (int i = 1; i<num; i++ )
			if(arr[i] < arr[i-1])
				return false;

		return true;
	}

	//运行排序函数并计算耗时
	//template<typename T>
	void SortTestor( string FunName, void (*sort)(int [],int ), int arr[], int num )
	{
		clock_t sort_begin_time = clock();
		sort(arr, num);
		clock_t sort_end_time = clock();

		if(IsSorted(arr, num))
			cout << "Sorted!" << endl;
		else 
			cout << "Not Sorted！" << endl;
		
		cout << setprecision(10);
		cout << FunName << ":" << (sort_end_time - sort_begin_time)*1.0 / CLOCKS_PER_SEC << "s" << endl;
		
	}
	
	template<typename T>
	void PrintArr( T arr[], int n)
	{
		for (int i=0; i<n; i++)
			cout << arr[i] << " ";

		cout << endl;
	}

	template<typename T>
	void CopyArray(T arr1[], T arr2[], int n)
	{
		for(int i = 0; i<n; i++)
			arr2[i] = arr1[i];

		return;
	}

}
