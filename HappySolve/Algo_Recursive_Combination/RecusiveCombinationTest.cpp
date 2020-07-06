/*
* Ǯ���� �ϴ� ����: n(0~n-1)���� ���ڿ��� k���� �����ϴ� ��� ������ ���� ����ϱ�
*/
#include <iostream>
#include <vector>
using namespace std;

#define TC 1

void printArray(vector<int>& pickedNums, const char *message)
{
	printf_s("%s\n", message);
	for (int i = 0; i < pickedNums.size(); i++)
	{
		printf_s("%d ", pickedNums[i]);
	}
	printf_s("\n");
}


void selectNum(int n, vector<int>& pickedIndex, int toPick)
{
	// ������ ������ ������ 0�̶��, vector �� ���.
	if (toPick == 0)
	{
		printArray(pickedIndex, "Select Done:");
		// ���̻� �������� �����Ƿ� return ����� ��.
		return;
	}

	// ���� ���� ���� index�� ��������
	int smallestIndex = pickedIndex.empty() ? 0 : pickedIndex.back() + 1;

	for (int i = smallestIndex; i < n; i++)
	{
		pickedIndex.push_back(i);
		selectNum(n, pickedIndex, toPick-1);

		pickedIndex.pop_back();
	}

}

void selectNum2(int n, vector<int>& pickedIndex, int toPick)
{
	// ������ ������ ������ 0�̶��, vector �� ���.
	if (toPick == pickedIndex.size())
	{
		printArray(pickedIndex, "Select Done:");
		return;
	}

	// ���� ���� ���� index�� ��������
	int smallestIndex = pickedIndex.empty() ? 0 : pickedIndex.back() + 1;

	for (int i = smallestIndex; i < n; i++)
	{
		pickedIndex.push_back(i);
		selectNum2(n, pickedIndex, toPick);

		pickedIndex.pop_back();
	}

}


int main()
{
#if TC == 1
	int n;
	int k;

	printf_s("Please input N and K:\n");
	scanf_s("%d %d", &n, &k);

	vector<int> pickedVector;

	// ���� ����� ����
	selectNum(n, pickedVector, k);
	//selectNum2(n, pickedVector, k);  // �ƶ��� �Ȱ���.

	return 0;
#else
	vector<int> nums;
	nums.push_back(100);
	printArray(nums, "test:");
#endif
}