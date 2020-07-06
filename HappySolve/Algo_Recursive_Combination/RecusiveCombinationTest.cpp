/*
* 풀려고 하는 문제: n(0~n-1)개의 숫자에서 k개를 선택하는 모든 가능한 조합 출력하기
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
	// 선택할 숫자의 개수가 0이라면, vector 를 출력.
	if (toPick == 0)
	{
		printArray(pickedIndex, "Select Done:");
		// 더이상 진행하지 않으므로 return 해줘야 함.
		return;
	}

	// 현재 제일 작은 index를 가져오기
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
	// 선택할 숫자의 개수가 0이라면, vector 를 출력.
	if (toPick == pickedIndex.size())
	{
		printArray(pickedIndex, "Select Done:");
		return;
	}

	// 현재 제일 작은 index를 가져오기
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

	// 조합 만들기 시작
	selectNum(n, pickedVector, k);
	//selectNum2(n, pickedVector, k);  // 맥락은 똑같음.

	return 0;
#else
	vector<int> nums;
	nums.push_back(100);
	printArray(nums, "test:");
#endif
}