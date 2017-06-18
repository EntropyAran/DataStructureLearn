//
//created by ryoishiki
//

#include <algorithm>
#include <ctime>


//插入排序
template<typename T>
void InsertSort( T arr[], int n)
{
	T temp;

	for ( int i=0; i<n; i++)
	{
		int j;
		temp = arr[i];
		for ( j=i; j>0 && arr[j-1] > temp; j--)
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
		for ( j=i; j>l && arr[j-1] > temp; j--)
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

	return;
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
			for(j=i; j>=gap && arr[j-gap] > temp; j-=gap )
				arr[j] = arr[j-gap];

			arr[j] = temp;
		}

	return;
}

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T *aux = new T[r-l+1];

	//增加一段内存复制当前的数组供排序用
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

	//优化1
	if(r - l < 15)//当分裂的数组小到一定时用插入排序或许更快，因为此时的数组更加有序
	{
		InsertSort(arr, l, r);
		return;
	}

	int mid = (r + l) / 2;

	//注意左闭右闭
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);

	//优化2
	if(arr[mid] > arr[mid+1])//如果arr[mid]<=arr[mid+1]时，说明两边已经有序了 //适用于近乎有序的数组
		__merge(arr, l, mid, r);
}

//归并排序
template<typename T>
void MergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n-1);//注意左闭右闭

	return;
}

//自底向上的归并排序
template<typename T>
void MergeSortBU(T arr[], int n)
{
	// 优化1
	// 对于小数组, 使用插入排序优化
	for( int i = 0 ; i < n ; i += 16 )
		InsertSort(arr,i,min(i+15,n-1));

	for(int sz=16; sz<=n; sz+=sz)
		for(int i=0; i+sz<n; i+=sz*2)
			if( arr[i+sz-1] > arr[i+sz] )// 优化2 对于arr[mid] <= arr[mid+1]的情况,不进行merge
				__merge(arr, i, i+sz-1, min(i+sz*2-1, n-1));//如果i+2*sz-1超过边界就用n-1作为右半部分边界

	return;
}

// 对arr[l...r]部分进行partition操作并返回p, 即中间分界线的元素v的位置
// 同时处理数组使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r)
{
	swap(arr[rand()%(r-l+1) + l], arr[l]);//选择随机元素作为分界点元素

	T v = arr[l];//选择第一个元素为分界点

	int j = l;// 定义初始化时记得满足定义
	for (int i = l+1; i <= r; i++)//i为每次比较的元素位置
	{
		//处理中始终保持[l+1,j]<v, [j+1,i-1]>v
		if (arr[i] < v)//大于v时直接什么也不做向后拓展右半部分即可
		{
			swap(arr[i], arr[j+1]);
			j++;
		}
	}

	swap(arr[l], arr[j]);
	return j;
}

//对范围是[l,r]的数组进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r)
{
	if(l >= r)
		return;

	int p = __partition(arr, l, r);//p为中间分界线元素v的位置
	__quickSort(arr, l, p-1);
	__quickSort(arr, p+1, r);
}

//快速排序
template<typename T>
void QuickSort(T arr[], int n)
{
	srand(time(NULL));
	__quickSort(arr, 0, n-1);//注意区间

	return;
}

// 双路快速排序的partition
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r)
{
	swap(arr[l], arr[rand()%(r-l+1) + l]);
	T v = arr[l];

	// arr[l+1...i) <= v; arr(j...r] >= v
	int i=l+1, j=r;
	while (true)
	{
		while(i<=r && arr[i] < v) i++;//注意边界
		while(j>= l+1 && arr[j] > v) j--;

		if(i>j) 
			break;

		//i和j元素相等的情况
		swap(arr[i], arr[j]); i++; j--;
	}

	swap(arr[j], arr[l]);
	return j;
}


//对范围是[l,r]的数组进行快速排序
template<typename T>
void __quickSort2(T arr[], int l, int r)
{
	if(l >= r)
		return;

	int p = __partition2(arr, l, r);//p为中间分界线元素v的位置
	__quickSort2(arr, l, p-1);
	__quickSort2(arr, p+1, r);
}

//快速排序
template<typename T>
void QuickSort2(T arr[], int n)
{
	srand(time(NULL));
	__quickSort2(arr, 0, n-1);//注意区间

	return;
}