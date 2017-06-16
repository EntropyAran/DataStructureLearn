//
//created by ryoishiki
//

#include <algorithm>


//��������
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
			for(j=i; j>=gap && arr[j-gap]>temp; j-=gap )
				arr[j] = arr[j-gap];

			arr[j] = temp;
		}

	return;
}

// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
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
	if(l >= r)
		return;

	int mid = (r + l) / 2;

	//ע������ұ�
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);

	__merge(arr, l, r, mid);
}

//�鲢����
template<typename T>
void MergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n-1);//ע������ұ�
}