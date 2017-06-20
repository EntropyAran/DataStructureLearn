
template<typename Item>
class MaxHeap
{
public:
	MaxHeap(int capacity)
	{
		data = new int[capacity+1];//������洢�����1�±꿪ʼ
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
	Item *data;//�洢�����������
	int count;//Ԫ�ظ���
};
