#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <String.h>


#if 0
int main()
{
	int n = 9;
	float *pFloat = (float *)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);

	*pFloat = 9.0;
	printf("n的值为：%d\n", n); 
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}



int main()
{
	char a[1000]; 
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	/*for (i = 0; i < 1000; i++)
	{
		printf("%c",a[i]);
	}*/
	printf("%d", strlen(a));
	return 0;
}



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

unsigned char i = 0; 
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}


#include <stdio.h> 
#include <windows.h> 
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
	}
}


int main()
{
	Sleep(1000);
	int i = -20;
	unsigned	int	j = 10;
	
	printf("%d\n", i + j);
	//按照补码的形式进行运算，最后格式化成为有符号整数
}


int main()
{
	int x = 0xffff80;
	char a = -128;
	printf("%u\n", a);
	printf("%u\n", a);
	return 0;
}

int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d\nb=%d\nc=%d\n", a, b, c);
	return 0;
}



int check_sys()
{
	int i = 1;
	return (*(char *)&i);
}
int  IsLittle()
{

	int a = 0x11223344;
	char *pc = (char*)&a;
	if (*pc == 0x44)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int ret = IsLittle();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

//代码2
int check2_sys()
{

	union
	{
		int i;
		char c;
	}un;
	un.i = 1; return un.c;
#endif