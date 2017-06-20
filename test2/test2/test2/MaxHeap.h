
#include <assert.h>
#include <string>
using namespace std;
template<typename Item>
class MaxHeap//最大堆类
{
public:

public:
	MaxHeap(int capacity)
	{
		data = new int[capacity+1];//最大树存储数组从1下标开始！！！
		count = 0;
		this->capacity = capacity;
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

	void insert(Item item)
	{
		assert(count+1 <= capacity);
				
		count ++;
		data[count] = item;//注意最大堆从下标1开始！！
		shiftUP(count);
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

};
