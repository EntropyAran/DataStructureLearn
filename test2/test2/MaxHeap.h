
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
		data = new Item[capacity+1];//������洢�����1�±꿪ʼ������
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

	void insert(Item item)//����Ԫ��
	{
		assert(count+1 <= capacity);
				
		count ++;
		data[count] = item;//ע�����Ѵ��±�1��ʼ����
		shiftUP(count);
	}

	Item ExtractMax()//����Ԫ��
	{
		assert(count > 0);

		Item ret = data[1];
		count --;
		swap(data[1], data[count+1]);
		shiftDown(1);

		return ret;
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

	void shiftDown(int k)
	{
		while (2*k <= count)//�����Ӵ���ʱ����ѭ��
		{
			int j = 2*k;//������Ҫ������Ԫ��data[j]
			if(data[j+1] > data[j] && j+1 <= count)//�Һ��Ӵ�������ʱ���Һ��ӽ���
				j++;

			if (data[k] > data[j])//���������λ��ʱֹͣ
				break;

			swap(data[k], data[j]);
			k = j;
		}
	}

};
