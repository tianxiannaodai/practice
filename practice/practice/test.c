#define _CRT_SECURE_NO_WARNINGS 1
//代码5
#include <stdio.h> 
int main()
{
int i = 1;
int ret = (++i) + (++i) + (++i); printf("%d\n", ret);
printf("%d\n", i); return 0;
}
//尝试在linux  环境gcc编译器，VS2013环境下都执行，看结果。
#if 0
void Print(int n)
{
	if(n/10!=0)
	{
		Print(n / 10);
	}	
	printf("%d\n", n%10);
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
	return n*fun(n-1);
}
int fun2(int n)
{
	int num=1;
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
	printf("%d",fun2(n));
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
	int account=0;
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
	int num1=Strlen(arr);
	int num2=Strlen2(arr);
	printf("%d",num1);
	printf("%d",num2);
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
		printf("%c",*(--string));  
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
	while (n/10!=0) 
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
	printf("sum=%d\n",sum);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int product(int n,int k)
{
	while (k>1) {
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
	scanf("%d%d", &n,&k);
	num = product(n,k);
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
		return fibonacci(n-1) + fibonacci(n - 2);
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
		n3 = n1+ n2;
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
	scanf("%d",&n);
	num1=fibonacci(n);
	num2=fabonacci2(n);
	printf("%d\n",num1);
	printf("%d\n",num2);
	system("pause");
	return 0;
}
#endif