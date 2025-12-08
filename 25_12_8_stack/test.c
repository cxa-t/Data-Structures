#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void test01()
{
		ST s;
		STInit(&s);
		STPush(&s, 1);
		STPush(&s, 2);
		STPush(&s, 3);
		STPush(&s, 4);
	
		printf("%d\n", STTop(&s));
		STPop(&s);
		printf("%d\n", STTop(&s));

		STPop(&s);

		while (!STIsEmpty(&s))
		{
			printf("%d ", STTop(&s));
			STPop(&s);
		}
	
		//printf("%d\n", STTop(&s));
	
		STDestroy(&s);
}

int main()
{
	test01();
	return 0;
}