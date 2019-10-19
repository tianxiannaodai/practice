#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#if 0
//���ַ������� strlen();
//size_t strlen ( const char * str );
//�ַ����Ѿ� '\0' ��Ϊ������־;
//strlen�������ص������ַ����� '\0' ǰ����ֵ��ַ������������� '\0' );
//����ָ����ַ�������Ҫ��  '\0' ����;
//ע�⺯���ķ���ֵΪsize_t�����޷��ŵģ� �״� ��; 
//ѧ��strlen������ģ��ʵ��;

//strlen������ģ��ʵ��;
//��һ�֣�������ʽ
int my_strlen(const char * str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		++count;
		++str;
	}
	return count;
}
//�ڶ��֣��ݹ�
int my_strlen(const char * str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + strlen(str + 1);
	}
	
}
//�����֣�ָ�����
int my_strlen(const char * str)
{
	assert(str);
	const char*end = str;
	while (*end)
	{
		++end;
	}
	return end-str;
}
int main()
{
	char* p = "hello world";
	printf("%d",my_strlen(p));
	return 0;
}
#endif

#if 0
//�ַ������� strcpy����
//Դ�ַ��������� '\0' ������
//�ὫԴ�ַ����е� '\0' ������Ŀ��ռ�
//Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ��� 
//Ŀ��ռ����ɱ�
//ѧ��ģ��ʵ��

//strcpy������ģ��ʵ��

char* my_strcpy(char * dst, const char * src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	do
	{
		*dst = *src;
		++src;
		++dst;
	} while (*src);
	return ret;
}
char* my_strcpy(char * dst, const char * src)
{
	assert(dst);
	assert(src);
	char *ret= dst;
	while (*dst++ = *src++);
	//while (*dst=*src);
	//{
	//	src++;
	//	dst++;
	//}
	return ret;
}
int main()
{
	char*p1 = "hello";
	char p2[10];
	my_strcpy(p2,p1);
	printf("%s\n",p2);
	return 0;
}
#endif

#if 0

//�ַ���ƴ�� strcat()
//Դ�ַ��������� '\0' ����
//Ŀ��ռ�������㹻�Ĵ���������Դ�ַ���������
//Ŀ��ռ������޸�

//strcat������ģ��ʵ��
char * my_strcat(char * dst, const char * src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	while (*dst)
	{
		++dst;
	}
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	my_strcat(p1, p2);
	printf("%s\n", p1);
	return 0;
}
#endif

//#if 0
//�ַ����Ƚ�ʱstrcmp()
int my_strcmp(const char * str1, const char * str2)
{
	assert(str1&&str2);
	while (*str1&&str2)
	{
		if (*str1 > str2)
		{
			return 1;
		}
		else if (*str1 < str2)
		{
			return -1;
		}
		else
		{
			str1++; 
			str2++;
		}
	}
	if (*str1=='\0'&&*str2== '\0')
	{
		return 0;
	}
	else if (*str1 == '\0')
	{
		return -1;
	}
	else if (*str2 == '\0')
	{
		return 1;
	}
	
}
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	printf("%d\n", my_strcmp(p1, p2));
	return 0;
}
//#endif

#if 0
//strstr������ģ��ʵ��
char * my_strstr(const char * str1, const char * str2)
{
	assert(str1&&str2);
	char * src = (char*)str1;
	char * sub = (char*)str2;
	char * p = NULL;
	if (*str2 == '\0')
	{
		return NULL;
	}
	while (*src)
	{
		p = src;
		sub = str2;
		while (*p&&*sub && (*src == *sub))
		{
			p++;
			sub++;
		}
		if (*sub == '\0')
		{
			return p;
		}
		else
		{
			src = ++p;
			sub = str2;
		}
	}
}
int main()
{
	char str1[] = "hello world";
	char str2[] = "world";
	printf("%c\n", my_strstr(str1, str2));
	return 0;
}
#endif

#if 0
//memcpy������ģ��ʵ��
void * my_memcpy(void * dst, const void * src, size_t count)
{
	assert(dst&&src);
	while (count--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
	return dst;
}
struct
{
	char name[20];
	int age;
}person, person_copy;
int main()
{
	char myname[] = "abcdefgh";
	//using memcpy to copy string
	my_memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	//using memcpy to copy structure
	my_memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy:%s,%d", person_copy.name, person_copy.age);
	return 0;
}
#endif

#if 0
//memmove������ģ��ʵ��
void * my_memmove(void * dst, const void * src, size_t count)
{
	assert(dst&&src);
	if (dst < src || (char *)dst >= ((char *)src + count))
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
}
int main()
{
	char str[] = "memmove an be very usefull";
	my_memmove(str + 20, str + 15, 11);
	printf("%s\n", str);
	return 0;
}
#endif
