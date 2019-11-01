#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int *p = (int *)(&i);
	*p = NULL;
	p = NULL;
}