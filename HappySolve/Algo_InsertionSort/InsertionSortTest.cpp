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
	// 만약 제일 처음 숫자라면, arr[0] 에 할당하면 됨.
	if (currentIndex == 0)
	{
		arr[0] = numToInsert;
	}

	// currentIndex 보다 앞에 있는 숫자들과 비교했을 때, numToInsert 보다 작을 것을 만날 때까지 앞으로 이동.
	if (currentIndex > 0)
	{
		// 앞에 숫자가 key보다 크면, 더 앞에 것과 비교

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

	// 삽입이 끝나면, 그 뒤에 숫자들은 하나씩 뒤로 이동
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
	// 정렬 전 배열 출력
	printArray(arr, T, "After insertion sorting");

	delete arr;

	return 0;
#else

#endif
}