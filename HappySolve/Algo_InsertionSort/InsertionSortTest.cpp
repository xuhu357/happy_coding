#include <iostream>
#include <vector>


#define TC 1

void printArray(int arr[], int length, const char *message)
{
	printf_s("%s:\n", message);
	for (int i = 0; i < length; i++)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}

void insertionSort(int arr[], int numToInsert, int currentIndex)
{
	// ���� ���� ó�� ���ڶ��, arr[0] �� �Ҵ��ϸ� ��.
	if (currentIndex == 0)
	{
		arr[0] = numToInsert;
	}

	// currentIndex ���� �տ� �ִ� ���ڵ�� ������ ��, numToInsert ���� ���� ���� ���� ������ ������ �̵�.
	if (currentIndex > 0)
	{
		// �տ� ���ڰ� key���� ũ��, �� �տ� �Ͱ� ��

		int prev = currentIndex - 1;
		while (prev >= 0 && arr[prev] > numToInsert)
		{
			prev--;
		}

		
		for (int i = currentIndex; i >= prev + 2; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[prev + 1] = numToInsert;
	}

	// ������ ������, �� �ڿ� ���ڵ��� �ϳ��� �ڷ� �̵�
}

int main()
{
#if TC == 1
	int T;
	scanf_s("%d", &T);
	int *arr = new int[T];

	int num;
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &num);
		arr[i] = num;
		insertionSort(arr, num, i);
	}
	// ���� �� �迭 ���
	printArray(arr, T, "After insertion sorting");

	delete arr;

	return 0;
#else

#endif
}