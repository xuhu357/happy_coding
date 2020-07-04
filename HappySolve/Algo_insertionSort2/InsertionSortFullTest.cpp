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

		// 앞에 숫자들에 대해서 나보다 작은 숫자를 만날때까지 이동
		while (prev >= 0 && arr[prev] > currentValue)
		{
			// 앞으로 하나 이동
			prev--;
		}

		// currnt Value 보다 큰 숫자들은 하나씩 뒤로 이동
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

	// 정렬하기 전
	printArray(arr_num, T, "Before sorting:");
	
	// 삽입 정렬
	insertionSortFull(arr_num, T);

	// 정렬한 후
	printArray(arr_num, T, "After sorting:");

	return 0;
#else

#endif
}
