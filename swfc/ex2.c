#include <stdio.h>

/***********************************************************/
// 1��. ���� ������
/***********************************************************/

/***********************************************************/
// [1-2-3] : global static => Exam01.C�� �Բ� ����
/***********************************************************/

#if 0

#include <stdio.h>
	
extern int a;
static int b = 20;
static int c = 30;

void func(void)
{
	a++;
	b++;
	c++;

	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("c=%d\n", c);
}

#endif

/***********************************************************/
// [1-2-4] : �Լ��� static => Exam01.c�� �Բ� ���
/***********************************************************/

#if 0


#include <stdio.h>

static int sqr(int a)
{
	return a * a * 2;
}

void func(void)
{
	printf("%d\n", sqr(3));
}

#endif

/***********************************************************/
// [1-2-8] : typedef => Exam01.C�� �Բ� ����
/***********************************************************/

#if 0

typedef signed int INT;

void func(void)
{
	INT a = 1;

	if(-1 < a) printf("TRUE1\n");
	else printf("FALSE1\n");

	{
		typedef unsigned int INT;
		INT a = 1;

		if(-1 < a) printf("TRUE2\n");
		else printf("FALSE2\n");
	}
}

#endif
