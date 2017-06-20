
#include <assert.h>
#include <string>
using namespace std;
template<typename Item>
class MaxHeap//������
{
public:

public:
	MaxHeap(int capacity)
	{
		data = new int[capacity+1];//������洢�����1�±꿪ʼ������
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
		data[count] = item;//ע�����Ѵ��±�1��ʼ����
		shiftUP(count);
	}

private:
	Item *data;//�洢�����������
	int count;//Ԫ�ظ���
	int capacity;//������

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
