
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<String.h>
typedef struct Day
{
	int year;
	int month;
	int day;
}Day;
int Today(Day day)
{
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int total = 0;
	if (day.year % 4 == 0 && day.year % 100 != 0 || day.year % 400 == 0)
	{
		arr[1] = 29;
	}
	switch (day.month)
	{
	case 11:
		total = total + arr[10];
	case 10:
		total = total + arr[9];
	case 9:
		total = total + arr[8];
	case 8:
		total = total + arr[7];
	case 7:
		total = total + arr[6];
	case 6:
		total = total + arr[5];
	case 5:
		total = total + arr[4];
	case 4:
		total = total + arr[3];
	case 3:
		total = total + arr[2];
	case 2:
		total = total + arr[1];
	case 1:
		total = total + day.day;
	default:
		break;
	}
	printf("%d.%d.%d是%d年的第%d天！\n",day.year,day.day,day.day,day.year,total);
}
int main()
{
	Day day = { 2019,9,21 };
	Today(day);
	return 0;
}
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<String.h>
typedef struct Student
{
	char name[10];
	int age;
}Stu;
void Show(Stu *p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%s,%d\n", p[i].name, p[i].age);
		printf("%s,%d\n", (*(p + i)).name, (*(p + i)).age);
		printf("%s,%d\n", (p + i)->name, (p + i)->age);
	}
}
int main()
{
	Stu arr[3] = { {"caocao",333},{"liubei",999},{"zhangfei",999} };
	int len = sizeof(arr) / sizeof(arr[0]);
	Show(arr, len);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct A
{
	int a;
	int *pa;
	struct A *ppA;
};
struct B
{
	int b;
	struct A Aa;
	struct B *pb;
	struct A *pBa;
};
int main()
{
	struct B Bb;
	Bb.b;
	Bb.pb;
	Bb.pBa;

	Bb.Aa.a;
	Bb.Aa.pa;
	Bb.Aa.ppA;

	Bb.pBa->a;
	Bb.pBa->pa;
	Bb.pBa->ppA;
	return 0;
}
#endif