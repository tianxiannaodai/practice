#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{

	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1)); return 0;
	return 0;
}
#if 0
int main()
{
	一维数组
		int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a)); //16
	printf("%d\n", sizeof(a + 0)); //4
	printf("%d\n", sizeof(*a)); //4
	printf("%d\n", sizeof(a + 1)); //4
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a)); //4
	printf("%d\n", sizeof(*&a)); //16
	printf("%d\n", sizeof(&a + 1)); //4
	printf("%d\n", sizeof(&a[0])); //4
	printf("%d\n", sizeof(&a[0] + 1));//4
	字符数组
		char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr)); //6
	printf("%d\n", sizeof(arr + 0)); //4
	printf("%d\n", sizeof(*arr)); //1
	printf("%d\n", sizeof(arr[1])); //1
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr + 1)); //4
	printf("%d\n", sizeof(&arr[0] + 1));//4
	printf("%d\n", strlen(arr)); //随机
	printf("%d\n", strlen(arr + 0)); //随机
	printf("%d\n", strlen(*arr)); //语法错误
	printf("%d\n", strlen(arr[1])); //语法错误
	printf("%d\n", strlen(&arr)); //语法错误
	printf("%d\n", strlen(&arr + 1)); //语法错误
	printf("%d\n", strlen(&arr[0] + 1));//随机
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr)); //7
	printf("%d\n", sizeof(arr + 0)); //4
	printf("%d\n", sizeof(*arr)); //1
	printf("%d\n", sizeof(arr[1])); //1
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr + 1)); //4
	printf("%d\n", sizeof(&arr[0] + 1));//4
	printf("%d\n", strlen(arr)); //6
	printf("%d\n", strlen(arr + 0)); //6
	printf("%d\n", strlen(*arr)); //语法错误
	printf("%d\n", strlen(arr[1])); //语法错误
	printf("%d\n", strlen(&arr)); //语法错误
	printf("%d\n", strlen(&arr + 1)); //语法错误
	printf("%d\n", strlen(&arr[0] + 1));//5
	char *p = "abcdef";
	printf("%d\n", sizeof(p)); //4
	printf("%d\n", sizeof(p + 1)); //4
	printf("%d\n", sizeof(*p));//1
	printf("%d\n", sizeof(p[0]));//1
	printf("%d\n", sizeof(&p)); //4
	printf("%d\n", sizeof(&p + 1)); //4
	printf("%d\n", sizeof(&p[0] + 1));//4
	printf("%d\n", strlen(p)); //6
	printf("%d\n", strlen(p + 1)); //5
	printf("%d\n", strlen(*p));//
	printf("%d\n", strlen(p[0]));//
	printf("%d\n", strlen(&p)); //3
	printf("%d\n", strlen(&p + 1)); //11
	printf("%d\n", strlen(&p[0] + 1));//5

	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a)); //48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4
	printf("%d\n", sizeof(*(a[0] + 1))); //4
	printf("%d\n", sizeof(a + 1)); //4
	printf("%d\n", sizeof(*(a + 1)));//16
	printf("%d\n", sizeof(&a[0] + 1));//4
	printf("%d\n", sizeof(*(&a[0] + 1))); //16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16
	return 0;
}
#endif

#if 0
int int_cmp(const void * p1, const void * p2);
void _swap(void *p1, void * p2, int size);
void BubbleSort(int *arr, int len);
void MyQsort(void *base, int count, int size, int(*cmp)(void *p1, void *p2));
void Show(int *arr, int len);

int int_cmp(const void * p1, const void * p2)
{
	return (*(int *)p1 - *(int *)p2);
}

void _swap(void *p1, void * p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		//一个字节一个字节的交换
		char tmp = *(((char *)p1) + i);
		*(((char *)p1) + i) = *(((char *)p2) + i);
		*(((char *)p2) + i) = tmp;
	}
}

//冒泡排序
void BubbleSort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//不是有序的，flags设置为1；
			}
		}
		if (flags == 0)
			return;
	}
}

void MyQsort(void *base, int count, int size, int(*cmp)(void *p1, void *p2))
{
	//冒泡排序
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
			{
				_swap((char *)base + j * size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}

void Show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"}; 
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	Show(arr, len);
	MyQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	Show(arr, len);
	return 0;
}
#endif

#if 0
//qosrt函数的使用者得实现一个比较函数
//void qsort(void *base, 
//		     size_t num, 
//			 size_t width, 
//			 int(__cdecl *compare)(const void *elem1, const void *elem2));

int int_cmp(const void * p1, const void * p2)
{
	return (*(int *)p1 > *(int *)p2);
}

void Show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n"); return 0;
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, arrLength, sizeof(int), int_cmp);
	Show(arr, arrLength);
	return 0;
}
#endif