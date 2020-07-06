#include <iostream>
#include <vector>
using namespace std;

#define TC 1

void printArray(vector<int>& arr, int length, const char *message)
{
	printf_s("%s", message);
	for (int i = 0; i < length; i++)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}

void bubbleSort(vector<int>& arr, int length)
{
	// ���� ���ڿ� ���ؼ� �ڽź��� ���� ���� ������, �ڸ� �ٲ�. ���� ū ���� ���� �����ʿ� ��ġ�ϵ��� �ݺ�
	for (int i = 0; i < length - 1; i++)
	{
		// Inner loop �� �̹� ���ĵ� ���� �����ϰ� ���ƾ� ��.
		for (int j = 0; j < length - 1 - i; j++)
		{
			// ���� ���ҿ� ��
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}

	}
}


int main()
{
#if TC == 1
	// Test Case �Է� �ޱ�
	int T;

	printf_s("Please input num of TestCase:\n");
	scanf_s("%d", &T);

	vector<int> arr_num;
	int num;
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &num);
		arr_num.push_back(num);
	}

	// ���� �� ������ ���
	printArray(arr_num, T, "Before sort:");

	// Bubble Sort ���� ����
	bubbleSort(arr_num, T);

	// ���� �� ������ ���
	printArray(arr_num, T, "After sort:");

	return 0;
#else
#endif
}