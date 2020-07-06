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
	// 다음 숫자와 비교해서 자신보다 작은 것이 있으면, 자리 바꿈. 제일 큰 것이 제일 오른쪽에 위치하도록 반복
	for (int i = 0; i < length - 1; i++)
	{
		// Inner loop 는 이미 정렬된 것은 제외하고 돌아야 함.
		for (int j = 0; j < length - 1 - i; j++)
		{
			// 다음 원소와 비교
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
	// Test Case 입력 받기
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

	// 정렬 전 데이터 출력
	printArray(arr_num, T, "Before sort:");

	// Bubble Sort 정렬 진행
	bubbleSort(arr_num, T);

	// 정렬 후 데이터 출력
	printArray(arr_num, T, "After sort:");

	return 0;
#else
#endif
}