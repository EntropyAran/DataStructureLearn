
#include <algorithm>


//≤Â»Î≈≈–Ú
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

//—°‘Ò≈≈–Ú
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

//√∞≈›≈≈–Ú
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

//œ£∂˚≈≈–Ú
template<typename T>
void ShellSort(T arr[], int n)
{
	for(int gap=n/2; gap>=1; gap/=2)
		for(int i=gap; i<n; i++)
		{
			int j;
			T temp = arr[i];
			// ∂‘ arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]...  π”√≤Â»Î≈≈–Ú
			for(j=i; j>=gap && arr[j-gap]>temp; j-=gap )
				arr[j] = arr[j-gap];

			arr[j] = temp;
		}

	return;
}