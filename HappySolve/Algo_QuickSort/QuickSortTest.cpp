#include <iostream>
#include <vector>
using namespace std;


#define TC 1


int partition(vector<int>& arr, int start, int end)
{
	int low = start;
	int high = end + 1;

	int pivotValue = arr[start];

	// ������ low+1, high ���� ������.
	do
	{
		low++;
		high--;

		while (low <= high && arr[low] < pivotValue)
		{
			low++;
		}

		while (high >= low && arr[high] > pivotValue)
		{
			high--;
		}
		printf_s("low: %d, high: %d \n", low, high);

		if (low < high)
		{
			swap(arr[low], arr[high]);
		}
	} while (low < high);

	swap(arr[start], arr[high]);
	
	return high;
}


void quickSort(vector<int>& arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	// pivot ��ġ ���ϱ�, partition ������
	int pivot_index = partition(arr, start, end);
	printf_s("pivot index: %d\n", pivot_index);

	// pivot ���� �κп� ���ؼ� quickSort ����
	printf_s("# 1. [start]: %d, [end]: %d\n", start, pivot_index - 1);
	quickSort(arr, start, pivot_index - 1);

	// pivot ������ �κп� ���ؼ� quickSort ����
	printf_s("# 2. [start]: %d, [end]: %d\n", pivot_index + 1, end);
	quickSort(arr, pivot_index + 1, end);
}



void printArray(vector<int>& arr, int length, const char *msg)
{
	printf_s("%s\n", msg);
	for (int i = 0; i < length; i++)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}


int main()
{
#if TC == 1

	// �Է� �޴� �κ�, T, T ��ŭ ���� �Է� �ޱ�
	int numOfTestCase = 0;
	printf_s("Please input num of test case:\n");
	scanf_s("%d", &numOfTestCase);

	vector<int> arr_num;
	int num;


	for (int i = 0; i < numOfTestCase; i++)
	{
		scanf_s("%d", &num);
		arr_num.push_back(num);
	}

	printf_s("Size of vector: %d\n", arr_num.size());

	printArray(arr_num, arr_num.size(), "Before sorting:");

	// �Է� ���� ���ڵ鿡 ���ؼ� QuickSort�� �����ϱ�
	quickSort(arr_num, 0, arr_num.size() - 1);

	// Sort �� �Ϸ�Ǹ� ��� print �ϱ�
	printArray(arr_num, arr_num.size(), "After sorting:");

	return 0;

#elif TC == 2
	vector<int> arr = { 2, 3 };
	printArray(arr, 2);

	swap(arr[0], arr[1]);

	printArray(arr, 2);

#endif
}