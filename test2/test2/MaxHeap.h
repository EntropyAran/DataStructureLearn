
#include <assert.h>
//#include <string>

//using namespace std;

template<typename Item>
class MaxHeap//最大堆类
{
public:

public:
	MaxHeap(int capacity)
	{
		data = new Item[capacity+1];//最大树存储数组从1下标开始！！！
		count = 0;
		this->capacity = capacity;
	}

	MaxHeap(Item arr[], int n)
	{
		data = new Item[n+1];
		count = n;
		capacity = n;
		for (int i=0; i<n; i++)
			data[i+1] = arr[i];

		for (int i=count/2; i>=0; i--)
			shiftDown(i);
		
	}

	~MaxHeap()
	{
		delete []data;data = NULL;
	}

	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	void insert(Item item)//插入元素
	{
		assert(count+1 <= capacity);
				
		count ++;
		data[count] = item;//注意最大堆从下标1开始！！
		shiftUP(count);
	}

	Item ExtractMax()//弹出元素
	{
		assert(count > 0);

		Item ret = data[1];
		count --;
		swap(data[1], data[count+1]);
		shiftDown(1);

		return ret;
	}

private:
	Item *data;//存储最大树的数组
	int count;//元素个数
	int capacity;//堆容量

private:
	void shiftUP(int k)
	{
		while ( k>1 && data[k/2] < data[k])
		{
			swap(data[k/2], data[k]);
			k /= 2;
		}
	}

	void shiftDown(int k)
	{
		while (2*k <= count)//当左孩子存在时继续循环
		{
			int j = 2*k;//接下来要交换的元素data[j]
			if(data[j+1] > data[j] && j+1 <= count)//右孩子大于左孩子时跟右孩子交换
				j++;

			if (data[k] > data[j])//当到达合适位置时停止
				break;

			swap(data[k], data[j]);
			k = j;
		}
	}

};
