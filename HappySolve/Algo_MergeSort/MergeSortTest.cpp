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
	// left ���� mid����, mid + 1 ���� right ���� ���ĵ� ����� merge�ϴ� ����
	vector<int> result;

	/**
	���ʰ� ������ ���ؼ� ���� ���� ����� �ִ´�. (���ʰ� �������� ��� ���� �������� ���� ����)
	���� ������ �̹� �� ��������, �������� ������ �κ� ��� ����� �ִ´�.
	���� �������� �̹� �� ��������, ������ ������ �κ��� ��� ����� �ִ´�.
	*/

	int p_left = left;
	int p_right = mid + 1;
	
	while (p_left <= mid && p_right <= right)
	{
		// ������ �����ʺ��� �۰ų� ���ٸ�, ������ �߰��ϰ� p_left++;
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
		// ������ �������� ��� ����� �ִ´�.
		while (p_right <= right)
		{
			result.push_back(arr[p_right]);
			p_right++;
		}
	}

	if (p_right > right && p_left <= mid)
	{
		// ���� ������ ��� ����� �ִ´�.
		while (p_left <= mid)
		{
			result.push_back(arr[p_left]);
			p_left++;
		}
	}

	//printArray(result, "result:");	// debugging

	//  result�� ������ ��� arr�� �������ش�.
	for (int i = 0; i < result.size(); i++)
	{
		arr[i + left] = result[i];
	}
}


void mergeSort(vector<int>& arr, int left, int right)
{
	// mergetSort�� [left, right] �����̴�. �� [0, length-1]���� �ѱ�� ������.

	// base condition
	if (left >= right)
	{
		return;
	}

	// ���� ������
	int mid = (left + right) / 2;

	// ���� ���ݿ� ���ؼ� mergeSort
	mergeSort(arr, left, mid);

	// ������ ���ݿ� ���ؼ� mergeSort
	mergeSort(arr, mid + 1, right);

	// ���ĵ� ���� ���ݰ� ������ ������ merge�ϱ�
	merge(arr, left, mid, right);
}


int main()
{
#if TC == 1
	// �Է� �ޱ�
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

	// ���� �� array print �ϱ�
	printArray(arr_num, "Before sorting:");

	// ���� ���� �����ϱ�
	mergeSort(arr_num, 0, arr_num.size() - 1);

	// ���� �� array print �ϱ�
	printArray(arr_num, "After sorting:");

	return 0;
#else
#endif
}