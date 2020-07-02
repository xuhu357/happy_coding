#include <iostream>
#include <vector>

using namespace std;

#define TC 1

void printArray(vector<int>& arr, const char* message)
{
	printf_s("%s\n", message);
	for (int num : arr)
	{
		printf_s("%d ", num);
	}
	printf_s("\n");
}

void merge(vector<int>& arr, int left, int mid, int right)
{
	// left 부터 mid까지, mid + 1 부터 right 까지 정렬된 결과를 merge하는 과정
	vector<int> result;

	/**
	왼쪽과 오른쪽 비교해서 작은 쪽을 결과에 넣는다. (왼쪽과 오른쪽이 모두 끝에 도달하지 않은 전제)
	만약 왼쪽이 이미 다 없어지면, 오른쪽의 나머지 부분 모두 결과에 넣는다.
	만약 오른쪽이 이미 다 없어지면, 왼쪽의 나머지 부분을 모두 결과에 넣는다.
	*/

	int p_left = left;
	int p_right = mid + 1;
	
	while (p_left <= mid && p_right <= right)
	{
		// 왼쪽이 오른쪽보다 작거나 같다면, 왼쪽은 추가하고 p_left++;
		if (arr[p_left] <= arr[p_right])
		{
			result.push_back(arr[p_left]);
			p_left++;
		}
		else
		{
			result.push_back(arr[p_right]);
			p_right++;
		}

	}

	if (p_left > mid && p_right <= right)
	{
		// 오른쪽 나머지를 모두 결과에 넣는다.
		while (p_right <= right)
		{
			result.push_back(arr[p_right]);
			p_right++;
		}
	}

	if (p_right > right && p_left <= mid)
	{
		// 왼쪽 나머지 모두 결과에 넣는다.
		while (p_left <= mid)
		{
			result.push_back(arr[p_left]);
			p_left++;
		}
	}

	//printArray(result, "result:");	// debugging

	//  result에 내용을 모두 arr에 복사해준다.
	for (int i = 0; i < result.size(); i++)
	{
		arr[i + left] = result[i];
	}
}


void mergeSort(vector<int>& arr, int left, int right)
{
	// mergetSort은 [left, right] 형식이다. 왜 [0, length-1]까지 넘기기 때문에.

	// base condition
	if (left >= right)
	{
		return;
	}

	// 절반 나누기
	int mid = (left + right) / 2;

	// 왼쪽 절반에 대해서 mergeSort
	mergeSort(arr, left, mid);

	// 오른쪽 절반에 대해서 mergeSort
	mergeSort(arr, mid + 1, right);

	// 정렬된 왼쪽 절반과 오른쪽 절반을 merge하기
	merge(arr, left, mid, right);
}


int main()
{
#if TC == 1
	// 입력 받기
	int T;
	vector<int> arr_num;
	printf_s("Please input test case:\n");
	scanf_s("%d", &T);

	printf_s("Please input value:\n");

	int num;
	while (T--)
	{
		scanf_s("%d", &num);
		arr_num.push_back(num);
	}

	// 정렬 전 array print 하기
	printArray(arr_num, "Before sorting:");

	// 병합 정렬 진행하기
	mergeSort(arr_num, 0, arr_num.size() - 1);

	// 정렬 후 array print 하기
	printArray(arr_num, "After sorting:");

	return 0;
#else
#endif
}