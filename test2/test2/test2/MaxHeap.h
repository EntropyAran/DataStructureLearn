
template<typename Item>
class MaxHeap
{
public:
	MaxHeap(int capacity)
	{
		data = new int[capacity+1];//最大树存储数组从1下标开始
		count = 0;
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

private:
	Item *data;//存储最大树的数组
	int count;//元素个数
};
