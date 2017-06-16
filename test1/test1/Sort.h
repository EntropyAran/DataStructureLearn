//
//created by ryoishiki
//

#include <algorithm>


//插入排序
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

//插入排序
template<typename T>
void InsertSort( T arr[], int l, int r)
{
	T temp;

	for ( int i=l+1; i<=r; i++)
	{
		int j;
		temp = arr[i];
		for ( j=i; j>l && temp < arr[j-1]; j--)
			arr[j] = arr[j-1];

		arr[j] = temp;
	}

	return;
}

//选择排序
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

//冒泡排序
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

//希尔排序
template<typename T>
void ShellSort(T arr[], int n)
{
	for(int gap=n/2; gap>=1; gap/=2)
		for(int i=gap; i<n; i++)
		{
			int j;
			T temp = arr[i];
			// 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
			for(j=i; j>=gap && arr[j-gap]>temp; j-=gap )
				arr[j] = arr[j-gap];

			arr[j] = temp;
		}

	return;
}

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int r, int mid)
{
	T *aux = new T[r-l+1];

	for(int i=l; i<=r; i++)
		aux[i-l] = arr[i];

	int i = l;
	int j = mid + 1;
	for(int k = l; k<=r; k++)
	{
		if (i > mid)//如果左半部分已经处理完毕
		{
			arr[k] = aux[j-l];
			j++;
		}
		else if (j > r)//如果右半部分已经处理完毕
		{
			arr[k] = aux[i-l];
			i++;
		}
		else if(aux[i-l] < aux[j-l])//如果左边元素大于右边元素
		{
			arr[k] = aux[i-l];
			i++;
		}
		else
		{
			arr[k] = aux[j-l];
			j++;
		}
	}

	delete []aux;aux = NULL;
	return;
}

//对范围是[l,r]的数组进行归并
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	
	/*if(l >= r)
		return;*/

	if(r - l < 15)//当分裂的数组小到一定时用插入排序或许更快，因为此时的数组更加有序
	{
		InsertSort(arr, l, r);
		return;
	}

	int mid = (r + l) / 2;

	//注意左闭右闭
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);

	if(arr[mid] > arr[mid+1])//如果arr[mid]<=arr[mid+1]时，说明两边已经有序了 //适用于近乎有序的数组
		__merge(arr, l, r, mid);
}

//归并排序
template<typename T>
void MergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n-1);//注意左闭右闭
}