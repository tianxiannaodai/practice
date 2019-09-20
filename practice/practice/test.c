


//编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int DifferentBit(int num1,int num2)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int num1, num2;
	int total;
	printf("请输入两个数：");
	scanf("%d%d", &num1,&num2);
	total = DifferentBit(num1, num2);
	printf("二进制表达中共有%d位不同.",total);
	return 0;
}




#if 0
//输出一个整数的每一位
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Print(int num)
{
		if (num /10 > 0)
		{
			Print(num / 10);
		}
		printf("%d  ", num % 10);
}
int main()
{
	int num = 0;
	int	i = 0;
	printf("请输入一个正整数：");
	scanf("%d", &num);
	Print(num);
	return 0;
}





//.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num = 0;
	int	i = 0;
	printf("请输入一个正整数：");
	scanf("%d", &num);
	printf("奇数序列为：");
	for (i = 31; i >= 0; i -= 2)  
	{
		printf("%d ", (num >> i) & 1);    
	}
	printf("\n");
	printf("偶数序列为：");
	for (i = 30; i >= 0; i -= 2)   
	{
		printf("%d ", (num >> i) & 1);  
	}
	printf("\n");
	return 0;
}





//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
//第一种
int count_one_bits_1(unsigned int value)
{
	int count = 0;
	while (value != 0)
	{
		count++;
		value = value & (value - 1);
	}
	return count;
}
//第二种
int count_one_bits_2(unsigned int value)
{
	int count = 0;
	while (value != 0)
	{
		if ((value % 2) == 1)
		{
			count++;
		}
		value /= 2;;
	}
	return count;
}
//第三种
int count_one_bits_3(unsigned int value)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	unsigned int num = 0;
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	printf("请输入一个正整数：");
	scanf("%d", &num);
	count_1 = count_one_bits_1(num);
	count_2 = count_one_bits_2(num);
	count_3 = count_one_bits_3(num);
	printf("该数二进制中 1 的个数为：%d\n", count_1);
	printf("该数二进制中 1 的个数为：%d\n", count_2);
	printf("该数二进制中 1 的个数为：%d", count_3);
	return 0;
}


void Print(int n)
{
	if (n / 10 != 0)
	{
		Print(n / 10);
	}
	printf("%d\n", n % 10);
}
int main()
{
	int n;
	scanf("%d", &n);
	Print(n);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fun(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	return n * fun(n - 1);
}
int fun2(int n)
{
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}
	return num;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fun(n));
	printf("%d", fun2(n));
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Strlen(char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return  1 + Strlen(++str);
}
int Strlen2(char *str)
{
	int account = 0;
	while (*str != '\0')
	{
		account++;
		str++;
	}
	return account;
}
int main()
{
	char arr[] = "helloWorld";
	int num1 = Strlen(arr);
	int num2 = Strlen2(arr);
	printf("%d", num1);
	printf("%d", num2);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse_string(char * string)
{
	if (*string == '\0')
		printf("%c", *string);
	else
	{
		reverse_string(++string);
		printf("%c", *(--string));
	}
}
int main()
{
	char arr[] = "HelloWorld";

	reverse_string(arr);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int DigitSum(n)
{
	while (n / 10 != 0)
	{
		return n % 10 + DigitSum(n / 10);
	}
	return n;
}
int main()
{
	int num;
	int sum;
	printf("请输入num:");
	scanf("%d", &num);
	sum = DigitSum(num);
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int product(int n, int k)
{
	while (k > 1) {
		return n * product(n, k - 1);
	}
	return n;
}
int main()
{
	int k;
	int n;
	int num;
	printf("请输入n,k:");
	scanf("%d%d", &n, &k);
	num = product(n, k);
	printf("%d\n", num);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//递归
int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
//非递归
int fabonacci2(int n)
{
	int n1 = 1;
	int n2 = 1;
	int n3 = 1;
	while (n > 2)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		n--;
	}
	return n3;
}
int main()
{
	int n;
	int num1;
	int num2;
	printf("请输入n:");
	scanf("%d", &n);
	num1 = fibonacci(n);
	num2 = fabonacci2(n);
	printf("%d\n", num1);
	printf("%d\n", num2);
	system("pause");
	return 0;
}
#endif