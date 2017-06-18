//
//created by ryoishiki
//

#include <algorithm>
#include <ctime>


//��������
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

//��������
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

//ѡ������
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

//ð������
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

//ϣ������
template<typename T>
void ShellSort(T arr[], int n)
{
	for(int gap=n/2; gap>=1; gap/=2)
		for(int i=gap; i<n; i++)
		{
			int j;
			T temp = arr[i];
			// �� arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... ʹ�ò�������
			for(j=i; j>=gap && arr[j-gap] > temp; j-=gap )
				arr[j] = arr[j-gap];

			arr[j] = temp;
		}

	return;
}

// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T *aux = new T[r-l+1];

	//����һ���ڴ渴�Ƶ�ǰ�����鹩������
	for(int i=l; i<=r; i++)
		aux[i-l] = arr[i];

	int i = l;
	int j = mid + 1;
	for(int k = l; k<=r; k++)
	{
		if (i > mid)//�����벿���Ѿ��������
		{
			arr[k] = aux[j-l];
			j++;
		}
		else if (j > r)//����Ұ벿���Ѿ��������
		{
			arr[k] = aux[i-l];
			i++;
		}
		else if(aux[i-l] < aux[j-l])//������Ԫ�ش����ұ�Ԫ��
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

//�Է�Χ��[l,r]��������й鲢
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	/*if(l >= r)
		return;*/

	//�Ż�1
	if(r - l < 15)//�����ѵ�����С��һ��ʱ�ò������������죬��Ϊ��ʱ�������������
	{
		InsertSort(arr, l, r);
		return;
	}

	int mid = (r + l) / 2;

	//ע������ұ�
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);

	//�Ż�2
	if(arr[mid] > arr[mid+1])//���arr[mid]<=arr[mid+1]ʱ��˵�������Ѿ������� //�����ڽ������������
		__merge(arr, l, mid, r);
}

//�鲢����
template<typename T>
void MergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n-1);//ע������ұ�

	return;
}

//�Ե����ϵĹ鲢����
template<typename T>
void MergeSortBU(T arr[], int n)
{
	// �Ż�1
	// ����С����, ʹ�ò��������Ż�
	for( int i = 0 ; i < n ; i += 16 )
		InsertSort(arr,i,min(i+15,n-1));

	for(int sz=16; sz<=n; sz+=sz)
		for(int i=0; i+sz<n; i+=sz*2)
			if( arr[i+sz-1] > arr[i+sz] )// �Ż�2 ����arr[mid] <= arr[mid+1]�����,������merge
				__merge(arr, i, i+sz-1, min(i+sz*2-1, n-1));//���i+2*sz-1�����߽����n-1��Ϊ�Ұ벿�ֱ߽�

	return;
}

// ��arr[l...r]���ֽ���partition����������p, ���м�ֽ��ߵ�Ԫ��v��λ��
// ͬʱ��������ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r)
{
	swap(arr[rand()%(r-l+1) + l], arr[l]);//ѡ�����Ԫ����Ϊ�ֽ��Ԫ��

	T v = arr[l];//ѡ���һ��Ԫ��Ϊ�ֽ��

	int j = l;// �����ʼ��ʱ�ǵ����㶨��
	for (int i = l+1; i <= r; i++)//iΪÿ�αȽϵ�Ԫ��λ��
	{
		//������ʼ�ձ���[l+1,j]<v, [j+1,i-1]>v
		if (arr[i] < v)//����vʱֱ��ʲôҲ���������չ�Ұ벿�ּ���
		{
			swap(arr[i], arr[j+1]);
			j++;
		}
	}

	swap(arr[l], arr[j]);
	return j;
}

//�Է�Χ��[l,r]��������п�������
template<typename T>
void __quickSort(T arr[], int l, int r)
{
	if(l >= r)
		return;

	int p = __partition(arr, l, r);//pΪ�м�ֽ���Ԫ��v��λ��
	__quickSort(arr, l, p-1);
	__quickSort(arr, p+1, r);
}

//��������
template<typename T>
void QuickSort(T arr[], int n)
{
	srand(time(NULL));
	__quickSort(arr, 0, n-1);//ע������

	return;
}

// ˫·���������partition
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r)
{
	swap(arr[l], arr[rand()%(r-l+1) + l]);
	T v = arr[l];

	// arr[l+1...i) <= v; arr(j...r] >= v
	int i=l+1, j=r;
	while (true)
	{
		while(i<=r && arr[i] < v) i++;//ע��߽�
		while(j>= l+1 && arr[j] > v) j--;

		if(i>j) 
			break;

		//i��jԪ����ȵ����
		swap(arr[i], arr[j]); i++; j--;
	}

	swap(arr[j], arr[l]);
	return j;
}


//�Է�Χ��[l,r]��������п�������
template<typename T>
void __quickSort2(T arr[], int l, int r)
{
	if(l >= r)
		return;

	int p = __partition2(arr, l, r);//pΪ�м�ֽ���Ԫ��v��λ��
	__quickSort2(arr, l, p-1);
	__quickSort2(arr, p+1, r);
}

//��������
template<typename T>
void QuickSort2(T arr[], int n)
{
	srand(time(NULL));
	__quickSort2(arr, 0, n-1);//ע������

	return;
}