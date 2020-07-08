/**
* input file redirect 할 때, subsystem console 유지가 안됨. output file redirect로 결과를 내보내는 방식으로 진행해도 무방
*/

#include <stdio.h>
#include <iostream>

int main()
{
	int num;
	char ch = 0;
	printf("Input Number: \n");
	scanf("%d", &num);
	printf("num: %d\n", num);

	printf("Program Done !");

	return 0;
}