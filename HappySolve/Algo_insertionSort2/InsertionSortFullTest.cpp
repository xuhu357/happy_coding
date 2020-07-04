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

void insertionSortFull(vector<int>& arr, int length)
{
	printf_s("Length of data to sort: %d\n", length);

	int currentValue;
	for (int i = 1; i < length; i++)
	{
		int prev = i - 1;
		currentValue = arr[i];
		printf_s("Current Value: %d\n", currentValue);

		// �տ� ���ڵ鿡 ���ؼ� ������ ���� ���ڸ� ���������� �̵�
		while (prev >= 0 && arr[prev] > currentValue)
		{
			// ������ �ϳ� �̵�
			prev--;
		}

		// currnt Value ���� ū ���ڵ��� �ϳ��� �ڷ� �̵�
		for (int j = i; j >= prev + 2; j--)
		{
			arr[j] = arr[j - 1];

		}

		arr[prev + 1] = currentValue;
		printf_s("Loop: %d done.\n", i);
	}
}


int main()
{
#if TC ==1
	int T;
	vector<int> arr_num;
	printf_s("Please input num of Test:\n");
	scanf_s("%d", &T);

	int num;
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &num);
		arr_num.push_back(num);
	}

	printf_s("array num size: %d\n", arr_num.size());

	// �����ϱ� ��
	printArray(arr_num, T, "Before sorting:");
	
	// ���� ����
	insertionSortFull(arr_num, T);

	// ������ ��
	printArray(arr_num, T, "After sorting:");

	return 0;
#else

#endif
}
