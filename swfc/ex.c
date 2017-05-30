/***********************************************************/
// 1��. ���� ������
/***********************************************************/
 
/***********************************************************/
// [1-1-1] : ������ �޸� ǥ��
/***********************************************************/

#if 0
#include <stdio.h>
int main(void) {
	int si = -1;
	unsigned int ui = 0xffffffff;
	
	printf("%d\n", si); //-1
	printf("%u\n", si); //INT_MAX  4294967295
	printf("%#x\n", si); //0xffffffff

	printf("%d\n", ui); //-1
	printf("%u\n", ui); //4294967295
	printf("%#x\n", ui); //0xffffffff
}
#endif

/***********************************************************/
// [1-1-2] : ������ �����? �����϶�
/***********************************************************/

#if 0
#include <stdio.h>
int main(void) {
	unsigned char c = 0xff;
	if(c == 0xff) printf("%#x\n",c+1); //0x100
	else printf("%#x\n",c-1);
}
#endif

#if 0
#include <stdio.h>
int main(void) {
	signed char c = 0xff;
	if(c == 0xff) printf("%#x\n",c+1);
	else printf("%#x\n",c-1); //0xfffffffe
}
#endif

#if 0 
#include <stdio.h>
int main(void) {
	//Caution: The char type is totally different from other char types which are 'signed char' and 'unsigned char'.
	//char: 0
	//signed char: -127 ~ 127
	//unsigned char: 0 ~ 255
	//This result depends on compiler.
	char c = 0xff; 
	if(c == 0xff) printf("%x\n",c+1);
	else printf("%hhd %x\n",c, c-1);
}
#endif

/***********************************************************/
// [1-1-3] : ������ �����? �����϶�
/***********************************************************/

#if 1
#include <stdio.h>
int main(void) {
	int a[4] = {1,2,3,4};
	if(a[0]-a[1] < sizeof(a)) 
		printf("%d\n", a[sizeof(char)]);
	else
		printf("%d\n", a[sizeof(short)]);
}
#endif

#if 0
#include <stdio.h>
int main(void)
{
	int a = -1;

	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(-1));
	printf("%d\n", sizeof a);
	printf("%d\n", sizeof - 1);

	// printf("%d\n", sizeof int);
}

#endif

/***********************************************************/
// [1-1-4] : signed short vs. unsigned short
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	signed short ss = -1;
	unsigned short us = -1;

	if(ss < us) printf("UNSIGNED SHORT\n");
	else if(ss > us) printf("SIGNED SHORT\n");
	else printf("SAME\n");
}

#endif

/***********************************************************/
// [1-1-5] : �񱳺б⿬���? ����ȯ
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	signed int test = -1;
	signed int si = 1;
	unsigned int ui = 2;

	printf("%d\n", (0 ? si : ui) > test);
	printf("%d\n", (1 ? si : ui) > test);
}

#endif

/***********************************************************/
// [1-1-6] : �Ǽ��� ��
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	float a = 3.1;
	float b = 3.5;

	if(a == 3.1) printf("TRUE1\n");
	else printf("FALSE1\n");
	
	if(b == 3.5) printf("TRUE2\n");
	else printf("FALSE2\n");
}

#endif

/***********************************************************/
// [1-1-7] : �Ǽ��� ��ȿ����
/***********************************************************/

#if 0

#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("a=%.20f\n", 100.f/3.f);
	printf("b=%.20f\n", 100./3.);
}

#endif

/***********************************************************/
// [1-1-8] : 10ȸ �ݺ� ����
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	int i, cnt;
	float f;

	for(cnt=0, i=1; i<=10; i++) cnt++;
	printf("INT=%d\n", cnt);

	for(cnt=0, f=0.1; f<=1.0; f+=0.1) cnt++;
	printf("FLOAT=%d\n", cnt);
}

#endif

/***********************************************************/
// [1-1-9] : �Ǽ� �޸��� dump
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	float f = 3.5f;

	printf("%#x\n", f);
}

#endif

/***********************************************************/
// [1-1-10] : MMU ��ȯ Table ���� �Լ�
/***********************************************************/

#if 0

#include <stdio.h>

static unsigned int x[4096];

#define _MMUTT_STARTADDRESS x
#define RW_NCNB 0x234

typedef unsigned int U32;

void MMU_SetMTT(int vaddrStart, int vaddrEnd, int paddrStart,int attr)
{
	U32 *pTT;
	int i,nSec;
 
	pTT=(U32 *)_MMUTT_STARTADDRESS+(vaddrStart>>20);
	nSec=(vaddrEnd>>20)-(vaddrStart>>20);

	for(i=0;i<=nSec;i++)
	{
		*pTT++=attr |(((paddrStart>>20)+i)<<20);
		printf("TT[0x%.3X] = 0x%.8X\n", i, _MMUTT_STARTADDRESS[i]);
	}
}

int main(void)
{
    MMU_SetMTT(0x00000000,0x002FFFFF,0x30000000,RW_NCNB);
	MMU_SetMTT(0x7FF00000,0x801FFFFF,0x30000000,RW_NCNB);
}    

#endif

#if 0

#include <stdio.h>

static unsigned int x[4096];

#define _MMUTT_STARTADDRESS x
#define RW_NCNB 0x234

typedef unsigned int U32;

void MMU_SetMTT(U32 vaddrStart,U32 vaddrEnd,U32 paddrStart,int attr)
{
	U32 i, j;
	U32 start = vaddrStart >> 20;
	U32 end = vaddrEnd >> 20;

	paddrStart = (paddrStart & 0xfff00000) | (attr & 0x000fffff);
 
	for(i=start, j=0; i<=end; i++, j++)
	{
		_MMUTT_STARTADDRESS[i] = paddrStart + (j<<20);
		printf("TT[0x%.3X] = 0x%.8X\n", i, _MMUTT_STARTADDRESS[i]);
	}
}


int main(void)
{
    MMU_SetMTT(0x00000000,0x002FFFFF,0x30000000,RW_NCNB);
	MMU_SetMTT(0x7FF00000,0x801FFFFF,0x30000000,RW_NCNB);
}    

#endif

/***********************************************************/
// [1-1-11] : shift �������� ����
/***********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	unsigned int ux = 0x80000001;
	signed int sx = 0x80000001;

	printf("%#.8x, %#.8x\n\n", ux>>2, ux<<2);
	printf("%#.8x, %#.8x\n\n", sx>>2, sx<<2);
}

#endif

/***********************************************************/
// [1-1-12] : ���� Ȥ�� white space�� �����? ���� ���ڿ�
/***********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	printf("Hello ""Embedded ""C!\n");
	printf("Hello "  "Embedded "  "C!\n");
	printf("%s\n", "Hello ""Embedded ""C!\n");
}

#endif

/***********************************************************/
// [1-2-1] : �ٴ��� �Լ� ȣ��
/***********************************************************/

#if 0

#include <stdio.h>

int a;
int b = 100;
int c = 200;
int d = 300;

void f2(void)
{
	int c = 30;

	a++, b++, c++, d++;
	printf("f2: %d %d %d %d\n", a, b, c, d);
}

void f1(void)
{
	int b = 10;
	int c = 20;

	f2();
	a++, b++, c++, d++;
	printf("f1: %d %d %d %d\n", a, b, c, d);
}

int main(void)
{
	int a = 1000;
	int b = 2000;
	int c = 3000;

	f1();
	a++, b++, c++, d++;
	printf("main: %d %d %d %d\n", a, b, c, d);
}

#endif

/***********************************************************/
// [1-2-2] : local�� static 
/***********************************************************/

#if 0

#include <stdio.h>

void f1(void);

int a = 10; 
static int s = 20;

int main(void)
{
	static int s;

	a++, s++;
	printf("%d %d\n", a, s);
	f1();
	a++, s++;
	printf("%d %d\n", a, s);
	f1();
}

void f1(void)
{
	int a = 1; static int s = 2;

	a++, s++;
	printf("%d %d\n", a, s);
}

#endif

/***********************************************************/
// [1-2-3] : global static => Exam02.C�� �Բ� ����
/***********************************************************/

#if 0

#include <stdio.h>
	
extern void func(void);

int a;
static int b = 10;
extern int c;

int main(void)
{
	func();

	c++;
	a++;
	b++;

	printf("a=%d\n", a);
	printf("b=%d\n", b);
}

#endif

/***********************************************************/
// [1-2-4] : �Լ��� static => Exam02.c�� �Բ� ���?
/***********************************************************/

#if 0

#include <stdio.h>

extern void func(void);

static int sqr(int a)
{
	return a * a;
}

int main(void)
{
	func();
	printf("%d\n", sqr(3));
}

#endif


/***********************************************************/
// [1-2-5] : ���ȣ��?
/***********************************************************/

#if 0

#include <stdio.h>

int func(int x)
{
	if(x>0) 
	{
		return x + func(x-2);
	}
	else 
	{
		return 0; 	 
	}
}	
	
int main(void)                    
{                                      
	printf("%d\n", func(10));  
}    

#endif

/***********************************************************/
// [1-2-6] : ���� ������ ���ȣ��?
/***********************************************************/

#if 0

#include <stdio.h>

int prt(int x)
{
	if(x == 0) return x;

	else if(x%2)
	{
		printf("%d\n", x + prt(x-1)); //1:
		return x;
	}
	else
	{
		printf("%d\n", x + prt(x-1)); //2:
		return x;
	}
}

int main(void)
{
	int i;
	i = prt(5); //3:
}

#endif

/***********************************************************/
// [1-2-7] : ���ȣ��? �Լ��� ���� ����
/***********************************************************/

#if 0

#include <stdio.h>

void func(int x)
{
	int a = 10;
	static int b = 20;

	if(x == 0) return; 
	else func(x-1);
	
	a++; 
	b++;

	printf("a=%d b=%d x=%d\n", a, b, x);
}	
	
int main(void)                    
{                                      
	func(6);  
}    

#endif

/***********************************************************/
// [1-2-8] : typedef => Exam02.C�� �Բ� ����
/***********************************************************/

#if 0

#include <stdio.h>

typedef unsigned int INT;

extern void func(void);

int main(void)
{
	typedef signed int INT;
	INT a = 1;

	if(-1 < a) printf("TRUE1\n");
	else printf("FALSE1\n");

	{
		typedef unsigned int INT;
		INT a = 1;

		if(-1 < a) printf("TRUE2\n");
		else printf("FALSE2\n");
	}

	func();
}

#endif

/***********************************************************/
// [1-3-1] : *p++�� ���?
/***********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	int cnt = 0;
	char *p = "Embedded";

	while(*p)
	{
		if(*p++ == 'd') cnt ++;
	}

	printf("%d\n", cnt);
}

#endif

/***********************************************************/
// [1-3-2] : ���ڿ� ���� �Լ�
/***********************************************************/

#if 0

#include <stdio.h>

void str_copy(char * d, const char * s)
{
	while(*d++ = *s++);
}

int main(void)
{
	char a[5];
	char b[5] = "ABCD";

	str_copy(a, b);
	printf("%s\n%s\n", a, b);
}

#endif

/***********************************************************/
// [1-3-3] : ���ڿ� ���� ���� �Լ�
/***********************************************************/

#if 0

#include <stdio.h>

unsigned int  str_lenth(const char * d)
{



}

int main(void)
{
	char a[ ] = "Willtek";

	printf("%d\n", sizeof(a));
	printf("%d\n", str_lenth(a));
}

#endif

/***********************************************************/
// [1-3-4] : ���ڿ� ���� �Լ�
/***********************************************************/

#if 0

#include <stdio.h>

void str_add(char * d, const char * s)
{



}

int main(void)
{
	char a[15] = "Willtek";
	char b[15] = " Corp.";

	str_add(a, b);

	printf("%s\n", a);
}

#endif

/***********************************************************/
// [1-3-5] : ���ڿ� �� �Լ�
/***********************************************************/

#if 0

#include <stdio.h>

int str_comp(const char *a, const char *b)
{



}

int main(void)
{
	printf("%d\n", str_comp("ABC", "BC"));
	printf("%d\n", str_comp("ABC", "AC"));
	printf("%d\n", str_comp("ABC", "AB"));
	printf("%d\n", str_comp("abc", "ABC"));
	printf("%d\n", str_comp("ab", " "));
	printf("%d\n", str_comp("A", "AB"));
}

#endif

/***********************************************************/
// [1-3-6] : malloc�� calloc�� ����
/***********************************************************/

/*
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int i;
	int * p;

	p = malloc(10 * sizeof(int));
	if(p == 0x0) return;

	for(i = 0; i < 10; i++)
	{
		printf("malloc[%d]=%d\n", i, p[i]);
	}

	free(p);

	printf("\n\n");

	p = calloc(10, sizeof(int));
	if(p == 0x0) return;

	for(i = 0; i < 10; i++)
	{
		printf("calloc[%d]=%d\n", i, p[i]);
	}

	free(p);
}
*/

/***********************************************************/
// [1-3-7] : realloc�� ���輺
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, *p, *q, *r;

	r = p = malloc(40);
	q = malloc(40);

	for(i=0;i<10;i++)
	{
		p[i] = i;
	}

	r = realloc(r, 40*2);
	
	for(i=10;i<20;i++)
	{
		r[i] = i;
	}

	printf("p=%p, r=%p\n", p, r);

	for(i=0;i<20;i++)
	{
		printf("p[%d]=%d, r[%d]=%d\n", i, p[i], i, r[i]);
	}
}

#endif

/***********************************************************/
// [1-3-8] : �ʱ�ȭ �ʿ� ���� �ּ� ����
/***********************************************************/

#if 0

#include <stdio.h>

void func(int *p, int *q, int *r)
{
	*p += 1;
	*q += 1;
	*r += 1;
}

int main(void)
{
	int i = 10;

	int a[1];
	int *p = &i;

	a[0] = 100;
	*p = 100;

	printf("%d, %d\n", i, a[0]);

	func(&i, a, p);
	printf("%d, %d\n", i, a[0]);
}

#endif

/***********************************************************/
// [1-3-9] : ������ ���� ���� ����
/***********************************************************/

#if 0

#include <stdio.h>

int add(int a, int b)
{
	int *p = &a;
	p[-1] = 0;

	return a+b;
}

int main(void)
{
	printf("%d\n", add(3,4));
}

#endif

/***********************************************************/
// [1-3-10] : ���� �����Ϳ� ���� ������
/***********************************************************/

#if 0

#include <stdio.h>

void func(int *p)
{
	*p = 100;
	p++;
	printf("0x%p\n", p);
}

int main(void)
{
	int a[]={1,2,3,4};
	int *p = a;

	func(p);
	printf("%d\n", *p);
	printf("0x%p, 0x%p\n", a, p);
}

#endif

#if 0

#include <stdio.h>

void func(int **p)
{
	**p = 100;
	(*p)++;
	printf("0x%p\n", (*p));
}

int main(void)
{
	int a[]={1,2,3,4};
	int *p = a;

	func(&p);
	printf("%d\n", a[0]);
	printf("0x%p, 0x%p\n", a, p);
}

#endif 

/***********************************************************/
// [1-3-11] : ���� �������� Ȱ��
/***********************************************************/

#if 0

#include <stdio.h>

int func(const int **p)
{
	int i;
	int sum = 0;

	printf("=========%d\n", (*p)[0]);






	return sum;
}

int main(void)
{
	int i;
	int a[] = {1, 10, 2, -5, -20, 3, 100, 200, 300, 4, -10, -20, -30, -40};
	const int *p = a;

	for(i=0; i<4; i++)
	{
		printf("SUM=%d\n", func(&p));
	}
}

#endif

/***********************************************************/
// [1-4-1] :#, ## ������
/***********************************************************/

#if 0

#include <stdio.h>

// macro ����

#define PRT(x)  

int NO_1 = 128;
int NO_2 = 256;
int NO_A = 512;

int main(void)
{
	PRT(1);
	PRT(2);
	PRT(A);
}

#endif

/***********************************************************/
// [1-4-2] : #ifdef, #ifndef ���Ǻ� ������
/***********************************************************/

#if 0

#include <stdio.h>

#define PRT

int main(void)
{
#ifdef PRT
	printf("defined PRT\n");
#endif

#ifdef ABC
	printf("defined ABC\n");
#else
	printf("not defined ABC\n");
#endif
}

#endif

#if 0

#include <stdio.h>

#define PRT

int main(void)
{
#ifndef PRT
	printf("not defined PRT\n");
#endif

#ifndef ABC
	printf("not defined ABC\n");
#else
	printf("defined ABC\n");
#endif
}

#endif

/***********************************************************/
// [1-4-3] :#undef
/***********************************************************/

#if 0

#include <stdio.h>

#define DEBUG

int main(void)
{
#ifdef DEBUG
	#undef DEBUG
#endif

#ifdef DEBUG
	printf("[DBG Message] a = %d\n", a);
#endif
}

#endif

#if 0

#include <stdio.h>

#define TEST	0

int main(void)
{
#ifdef TEST
	#undef TEST
	#define TEST	1
#endif

	printf("TEST = %d\n", TEST);
}

#endif

/***********************************************************/
// [1-4-4] :#if, #elif, #else, #endif
/***********************************************************/

#if 0

#include <stdio.h>

#define SOUND_DEVICE_TYPE	0

int main(void)
{
#if !SOUND_DEVICE_TYPE
	printf("���� ��ġ�� �������? ����\n");

#elif SOUND_DEVICE_TYPE == 1
	printf("STEREO ���? ��ġ ���?\n");

#else
	printf("CODE 15 : Unknown Device!\n");

#endif
	printf("���� ���? = %d\n", SOUND_DEVICE_TYPE);
}

#endif

/***********************************************************/
// [1-4-5] : defined ������
/***********************************************************/

#if 0

#include <stdio.h>

#define SOUND_DEVICE_TYPE	0

int main(void)
{
#if SOUND_DEVICE_TYPE == 1
	printf("���� ��ġ�� �������? ����\n");
#else
	printf("CODE 15 : Unknown Device!\n");
#endif

#if defined SOUND_DEVICE_TYPE
	printf("define SOUND_DEVICE_TYPE\n");
#else
	printf("not define SOUND_DEVICE_TYPE\n");
#endif

#if !defined SOUND_DEVICE_TYPE
	printf("define SOUND_DEVICE_TYPE\n");
#else
	printf("not define SOUND_DEVICE_TYPE\n");
#endif
}

#endif

/***********************************************************/
// [1-4-6] : #error
/***********************************************************/

#if 0

#include <stdio.h>

#define SOUND_DEVICE_TYPE	1

int main(void)
{
#if !SOUND_DEVICE_TYPE
	printf("���� ��ġ�� �������? ����\n");

#else
	#error CODE 15: Unknown Device!

#endif
	printf("���� ���? = %d\n", SOUND_DEVICE_TYPE);
}

#endif

/***********************************************************/
// [1-4-7] : #pragma ���? ��
/***********************************************************/

#if 0

#include <stdio.h>

#pragma warning (disable : 4101 4700)
//#pragma warning (once : 4552)
//#pragma warning (error : 4700)

int main(void)
{
	unsigned int a, b; //(C4101 : b �̻��?)

	a + 1;		//(C4552 : "+" has no effect)
	a >> 4;		//(C4552 : ">>" has no effect)
	a = a;		//(C4700 : use not initialized a)
}

#endif

/**********************************************************/
// 2��. ���? ������ �м� �� ����
/**********************************************************/

/***********************************************************/
// [2-1-1] ������ ��Ҽ�? ���?
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	int a[10];

	int *start = &a[0];
	int *end = &a[9]+1;
	int *p = &a[3];
	
	printf("%d\n", sizeof(a)/sizeof(a[0]));

	printf("%d\n", (end-start)/sizeof(int));
	printf("%d\n", (p-start)/sizeof(int));
	printf("%d\n", (end-p)/sizeof(int));
}

#endif

/***********************************************************/
// [2-1-2] �ּ��� �����? Ÿ�� �°�
/***********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	int *p, *q;

	p = (int *)0x1008;
	q = (int *)0x1000;
	
	printf("%#x\n", p*q);
	printf("%#x\n", p/q);
	printf("%#x\n", p+q);
	printf("%#x\n", p-q);

	printf("%#x\n", p*2);
	printf("%#x\n", p/2);
	printf("%#x\n", p+2);
	printf("%#x\n", p-2);
}

#endif

/***********************************************************/
// [2-1-3] �迭 parameter
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int b[4])
{
	int i, sum = 0;

	for(i=0; i<(sizeof(b)/sizeof(b[0])); i++)
	{
		sum += b[i];
	}
	return sum;
}

int main(void)
{
	int a[4] = {1,2,3,4};

	printf("%d\n", sum(a));
}

#endif

#if 0

#include <stdio.h>

void func(int b[5])
{
	printf("%x\n", b);
	printf("%x\n", &b[0]);
	printf("%d\n", sizeof(b));
}

int main(void)
{
	int a[5] = {10,20,30,40, 50};

	printf("%x\n", a);
	printf("%x\n", &a[0]);
	printf("%d\n", sizeof(a));
	func(a);
}

#endif

/***********************************************************/
// [2-1-4] �迭 Ȱ�����? �̿��� �迭 ���? �׼���
/***********************************************************/

#if 0 

#include <stdio.h>

int a[4] = {1,2,3,4};
	
int main(void)
{
	printf("%d\n", a[0]);
	printf("%d\n", a[3]);
	printf("%d\n", a[4]);
	printf("%d\n", a[-1]);

	printf("%d\n", (a+1)[2]);
	printf("%d\n", a[3]);

	printf("%d\n", a[2]);
	printf("%d\n", *(a+2));
	printf("%d\n", *(2+a));
	printf("%d\n", 2[a]);
}

#endif

/**********************************************************/
// [2-2-1] : �迭�� ���? Ÿ��
/**********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	int *a;

	int *b1[4];
	int **b2[4];
	int b3[4];

	b1[0] = a;
	b2[0] = &a;
	b3[0] = *a;
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
	int (*p)[4];

	// ���� ����

		b1[4]
		b2[4]
		b3[4]

	b1[0] = p;
	b2[0] = &p;
	b3[0] = (*p)[1];
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
	int a[3];

	// ���� ����

		b1[4]
		b2[4]
		b3[4]

	b1[0] = a;
	b2[0] = &a;
	b3[0] = a[1];
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
	int *a[3];

	// ���� ����

		b1[4]
		b2[4]
		b3[4]

	b1[0] = a;
	b2[0] = &a;
	b3[0] = a[1];
}

#endif

/**********************************************************/
// [2-2-2] : �Լ��� ���� Ÿ��
/**********************************************************/

#if 0

#include <stdio.h>

int *a;

	f1(void)
{
	return a;
}

	f2(void)
{
	return &a;
}

	f3(void)
{
	return *a;
}

int main(void)
{
	f1();
	f2();
	f3();
}

#endif

#if 0

#include <stdio.h>

int (*p)[4];

	f1(void)
{
	return p;
}

	f2(void)
{
	return &p;
}

	f3(void)
{
	return (*p)[1];
}

int main(void)
{
	f1();
	f2();
	f3();
}

#endif

#if 0

#include <stdio.h>

int (*p)(int);

	f1(void)
{
	return p;
}

	f2(void)
{
	return &p;
}

	f3(void)
{
	return (*p)(3);
}

int main(void)
{
	f1();
	f2();
	f3();
}

#endif

/***********************************************************/
// [2-3-1] : ���ڿ��� %s �ɼ� ����
/***********************************************************/

#if 0

#include <stdio.h> 

int main(void)
{
	char a[ ] = "LEW";
	char *p = "%s\n";

	printf("%s\n", "LEW");
	printf("%s\n", a);
	printf("%s\n", *a);
	printf(p, a);
}

#endif

/**********************************************************/
// [2-3-2] : ������ �μ�?���??
/**********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	char a[4] = "LEW";
	char *p = a;

	printf("%X:%X \n", p, &p);
	printf("%X:%X \n", a, &a);
	printf("%X:%X \n", main, &main);
	printf("%X:%X \n", "LEW", &"LEW");
}

#endif

/**********************************************************/
// [2-3-3] : ������ �迭
/**********************************************************/

#if 0

#include <stdio.h> 

int x[4] = {1,2,3,4};

int main(void)
{
	int *a[4] = {x+3, x+2, x+1, x};
	
	printf("%d\n", x[2]);	

	// �迭 a�� �̿��Ͽ� x[2]�� 30����

	     = 30;   

	printf("%d\n", x[2]);
}

#endif

/**********************************************************/
// [2-3-4] : ��ġ�� Ȱ��
/**********************************************************/

#if 0

#include <stdio.h> 

int x[4] = {1,2,3,4};

int *f1(void)
{
	return x;
}

void f2(int *p)
{
	printf("%d == %d == %d == %d\n", x[2], *(x+2), p[0], *p);
}

int main(void)
{
	int *p;
	int *a[4] = {x+3, x+2, x+1, x};

	p=x;

	printf("%d == %d\n", x[2], p[2]);
	printf("%d == %d == %d == %d\n", x[2], *(x+2), a[3][2], *a[1]);
	printf("%d == %d == %d == %d\n", x[2], *(x+2), f1()[2], *(f1()+2));
	f2(x+2);
}

#endif

/**********************************************************/
// [2-3-5] : ������ �迭 Ȱ��
/**********************************************************/

#if 0

#include <stdio.h> 

char err[3][25] = {"Speed Error!", "Position Error!", "Unknown Command Error!"};

int main(void)
{
	printf("%s\n", 	err[1]);
}

#endif

#if 0

#include <stdio.h> 

char *err[3] = {"Speed Error!", "Position Error!", "Unknown Command Error!"};

int main(void)
{
	printf("%s\n", 	err[1]);
}

#endif

/**********************************************************/
// [2-3-6] : ���ڿ��� ����
/**********************************************************/

#if 0

#include <stdio.h> 

int main(void)
{
	char a[4] = "LEW";

	printf("%X	%X \n", a, &a);
	printf("%X	%X \n", "LEW", &"LEW");
	printf("%c	%c\n", a[0], a[1]);
	printf("%c	%c\n", "LEW"[0], "LEW"[1]);
	printf("%c	%X \n", *a, a+1);
	printf("%c	%X \n", *"LEW", "LEW"+1);
}

#endif

/**********************************************************/
// [2-3-7] : �Լ��� ����
/**********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a+b;
}

int main(void)
{
	int (*p)() = add;

	printf("%d\n", add(3,4));
	printf("%d\n", (&add)(3,4));
	printf("%d\n", (*add)(3,4));
	printf("%d\n", (**add)(3,4));

	printf("%d\n", p(3,4));
	printf("%d\n", (*p)(3,4));
	printf("%d\n", (**p)(3,4));
}

#endif

/**********************************************************/
// [2-3-8] : �迭�� ����Ű�� ������
/**********************************************************/

#if 0

#include <stdio.h> 

int main(void)
{
	int a[4] = {10,20,30,40}; 
	int (*p)[4] = &a;

	printf("%#x\n", p);
	printf("%#x\n", p+1);
	printf("%#x\n", *p);
}

#endif

/**********************************************************/
// [2-3-9] : �迭 ������ ����
/**********************************************************/

#if 0

#include <stdio.h> 

void func(           p          )
{
	// main�� a[2]�� 50����

        = 50;
}

int main(void)
{
	int a[4] = {10,20,30,40};
	
	printf("%d\n", a[2]);	
	func(&a);
	printf("%d\n", a[2]);
}

#endif

/***********************************************************/
// [2-3-10] : ����ü�� �⺻���̴�
/***********************************************************/

#if 0

#include <stdio.h>

int main(void) 
{
	int a, b = 10;

	a = b;
	printf("a=%d, b=%d\n", a, b);
}

#endif

#if 0

#include <stdio.h>

int main(void) 
{
	struct st
	{
		int a;
		char b;
	} y = {100, 'A'};

	struct st x = y;

	printf("x.a=%d, x.b=%c\n", x.a, x.b);
	printf("y.a=%d, y.b=%c\n", y.a, y.b);
}

#endif

/**********************************************************/
// [2-3-11] : ����ü�� �Լ� ����
/**********************************************************/

#if 0 

#include <stdio.h> 

struct math
{
	int id;
	char name[20];
	int score;
}mid, final={1, "Kim", 50};

int main(void)
{
	mid = final;
	
	printf("%d\n", mid.id);
	printf("%s\n", mid.name);
	printf("%d\n", mid.score);
}

#endif

#if 0

#include <stdio.h>

struct math
{
	int id;
	char name[20];
	int score;
};

void cheat(struct math test);

int main(void)
{
	struct math final={1, "Kim", 50};
	cheat(final);
	printf("%d\n", final.score);
}

void cheat(struct math test)
{
	test.score = 100;
}

#endif

/**********************************************************/
// [2-3-12] : ����ü �ּ��� �Լ� ����
/**********************************************************/

#if 0

#include <stdio.h> 
 
struct math
{
	int id;
	char name[20];
	int score;
};

void cheat(struct math * test);

int main(void)
{
	struct math final={1, "Kim", 50};
	cheat(&final);
	printf("%d\n", final.score);
}

void cheat(struct math * test)
{
			 = 100;
}

#endif

/***********************************************************/
// [2-4-1] : 2���� �迭�� Ȱ���?
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

int main(void)
{
	printf("%d\n", a[2][3]);
	printf("%d\n", *(*(a+2)+3));
	printf("%d\n", (a+1)[1][3]);
	printf("%d\n", ((a+1)[1]+2)[1]);
	printf("%d\n", 3[a[2]]);
	printf("%d\n", 3[2[a]]);
}

#endif

/**********************************************************/
// [2-4-2] : 2���� �迭�� ���� ����
/**********************************************************/

#if 0

#include <stdio.h>

char a[3][4] = {"kim","lew","seo"};

int main(void)
{
	printf("%d\n",a);
	printf("%d\n",*a);
	printf("%d\n",a[0]);
	printf("%c\n",*a[0]);
	printf("%d\n",a[1]);
	printf("%c\n",*a[1]);
	printf("%d\n",a[2]);
	printf("%c\n",*a[2]);
}

#endif

/**********************************************************/
// [2-4-3] : 2�����迭�� ����
/**********************************************************/

#if 0

#include <stdio.h>

void draw_pixel(int y, int x, int value,      p     )
{
	p[y][x] = value;
}

int main(void)
{
	int a[2][3] = {1,2,3,4,5,6};

	printf("%d\n", a[1][2]);
	draw_pixel(1, 2, 10, a);
	printf("%d\n", a[1][2]);
}

#endif

/**********************************************************/
// [2-4-4] : 2�����迭�� ����
/**********************************************************/

#if 0

#include <stdio.h>

       func(void)
{
	static int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	return a;
}

int main(void)
{
	printf("%d\n",     func()        );
}

#endif

/**********************************************************/
// [2-4-5] : �迭 ������� ����
/**********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	int a[2][3][4];
	int (*b[3])[4];
	int *(*c[2])(int *);
	int *d[3][4];
	int (*(*e[5])(void))[4];

	// pa ~ pe ������ ���� ����
	// �Ʒ��� pa ~ pe ���� �����͸� �����Ѵ�
	// �����Ͻ� �� �ϳ��� ���? �߻����� �ʾƾ� �Ѵ�







	pa = a;
	pb = b;
	pc = c;
	pd = d;
	pe = e;
}

#endif

/**********************************************************/
// [2-4-6] : ��������� Ȱ��
/**********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	char arr[5][10] = {"Kim", "Lew", "Kang", "Song", "Park"};
	char (*p)[10];

	p = arr;
	
	printf("%s\n", *p);
	printf("%s\n", *(p+1));
	printf("%c\n", *(*(p+2)+1));

	printf("%s\n", p[0]);
	printf("%s\n", p[1]);
	printf("%c\n", p[2][1]);
}

#endif

/**********************************************************/
// [2-4-7] : � �����ͷ� �ٶ󺸴� �޸�
/**********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

int func(void * p, int a, int x)
{
	int (*q)[4] = p;
	return (a+4)[q[x-1]];
}

int main(void)
{
	printf("%d\n", func(a, 1, 2));
}

#endif

/**********************************************************/
// [2-4-8] : �迭�� �׼���
/**********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int *b[3] = {a[2], a[1], a[0]};

int main(void)
{
	printf("%d\n", 	a[2][3]);
	
	//b�� �̿��Ͽ� �迭���� ���� 12�� �μ��Ͻÿ�
	printf("%d\n", 			);
}

#endif

/**********************************************************/
// [2-4-9] : ȯ�����? ����
/**********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int *p = a[0];

int main(void)
{
	printf("%d\n", 	a[2][3]);
	
	//p ������ �̿��Ͽ� �迭���� ���� 12�� �μ��Ͻÿ�
	printf("%d\n", 			);
}

#endif

/***********************************************************/
// [2-4-10] : �Լ� parameter�� ������ ����
/***********************************************************/

#if 0

#include <stdio.h>

int a[2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}},{{10,20,30,40},{50,60,70,80},{90,100,110,120}}};

void f1(               ) 
{
	printf("%d\n",                 );
}

void f2(               )  
{
	printf("%d\n",                 );
}

void f3(               ) 
{
	printf("%d\n",                 );
}

void f4(               ) 
{
	printf("%d\n",                 );
}

void f5(               ) 
{
	printf("%d\n",                 );
}

void f6(               ) 
{
	printf("%d\n",         );
}

int main(void)
{
	f1(*(a[0]+1));  
	f2(*(a+2));
	f3(a);
	f4(a+3);
	f5(&a);
	f6(&a-1);
}

#endif

/***********************************************************/
// [2-4-11] : �Լ� ������ ������ ����
/***********************************************************/

#if 0

#include <stdio.h>

int a[2][3] = {{1,2,3},{4,5,6}};
int b[2][3] = {{10,20,30},{40,50,60}};
int (*c[2])[3] = {b, a};
int (**p)[3] = c;

f1(void) 
{
	return c[1];	
}

f2(void)  
{
	return c+1;
}

f3(void) 
{
	return a[0]-1;
}

 f4(void) 
{
	return p;
}

f5(void) 
{
	return &c;
}

int main(void)
{
	printf("6=%d\n",       f1()         );
	printf("6=%d\n",       f2()         );
	printf("6=%d\n",       f3()         );
	printf("6=%d\n",       f4()         );
	printf("6=%d\n",       f5()         );
}

#endif

/**********************************************************/
// [2-4-12] : �ڵ��� ������ �ؼ�
/**********************************************************/

#if 0 

#include <stdio.h>

char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;

int main(void)
{
	printf("%s", **++cpp);
	printf("%s ", *--*++cpp+3);
	printf("%s", *cpp[-2]+3);
	printf("%s\n", cpp[-1][-1]+1);
}

#endif

/***********************************************************/
// [2-5-1] : �Լ� ��������� ����
/***********************************************************/

#if 0

#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}	

void f1(void)
{
	printf("func\n");
}

int * f2(void)
{
	static int a[4] = {1,2,3,4};

	return a;
}

int main(void)
{
	// p, q, r ����

	// p, q, r�� ���� �Լ� ����

	printf("%d\n", add(3,4));
	f1();
	printf("%d\n", f2()[2]);

	// ���� ������ �����? �������� p, q, r�� ����



}

#endif

/***********************************************************/
// [2-5-2] : �Լ��� �Լ��� ��������
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

void func(                  )
{
	printf("%d\n", p(3,4));
}

int main(void)
{
	func(add);
	func(sub);
}

#endif

/***********************************************************/
// [2-5-3] : Parameter ��������
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a+b;
}

int sqr(int a)
{
	return a*a;
}

int func(void)
{
	return 100;
}

// add, sqr, func�� �������� �Լ� ������� p ����


int main(void)
{
	p = add;
	printf("%d\n", p(3,4));

	p = sqr;
	printf("%d\n", p(3));

	p = func;
	printf("%d\n", p( ));
}

#endif

/***********************************************************/
// [2-5-4] : ���ǿ� ���� �Լ� ȣ�� ����
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

int op(int a, int b)
{
	switch(get_key())
	{
		case 0	: return add(a,b);
		case 1	: return sub(a,b);
		case 2	: return mul(a,b);
	}
}

int main(void)
{
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
}

#endif

/***********************************************************/
// [2-5-5] : �Լ� Lookup table
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

       fa[3]        = {add, sub, mul};

int op(int a, int b)
{
	return fa[get_key()](a,b);
}

int main(void)
{
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
}

#endif

/***********************************************************/
// [2-5-6] : �Լ��� �ް� �Լ��� �����ϴ� �Լ�
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

int (*fa[3])(int, int) = {add, sub, mul};
	
			op(     fp     )
{
	return fa[fp()];
}

int main(void)
{
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
}

#endif

/***********************************************************/
// [2-5-7] : qsort �Լ��� �̿��� �迭 ����
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h>

struct _st 
{ 
	int num; 
	char *name; 
};

struct _st book[10] =  {{7, "Kim"},	 {2, "Lew"}, 	 {10, "Kang"},
						{3, "Lee"},	 {6, "Seo"},	 {1, "Song"},
						{5, "Ki"},	 {8, "Moon"}, 	 {9, "Park"},
			            {4, "Jung"}};

int compare_num_up(const void * a1, const void * a2)
{
	register const struct _st * p = a1, *q = a2;
	
	if(p->num > q->num) return 1;
	if(p->num < q->num) return -1;
	return 0;
}

int main(void)
{
	int i; struct _st tmp; struct _st *p;

	for(i=0; i<10; i++) printf("%d:%s\n", book[i].num, book[i].name);
	printf("\n");
	qsort(book, sizeof(book)/sizeof(book[0]), sizeof(struct _st), compare_num_up);
	for(i=0; i<10; i++) printf("%d:%s\n", book[i].num, book[i].name);	

	tmp.num = 8;
	p = bsearch(&tmp, book, 10, sizeof(struct _st), compare_num_up);
	if(p)	printf("\nSearch Result => %d : %s\n", p->num, p->name);
	else	printf("\nSearch Failed\n");
}

#endif

/***********************************************************/
// [2-5-8] : typedef�� �̿��� �������� ����
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

typedef 
	
FPTR fa[3] = {add, sub, mul};
	
FPTR op(FPTR fp)
{
	return fa[fp()];
}

int main(void)
{
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
}

#endif

/***********************************************************/
// [2-5-9] : ������ �ڵ� ���� ���� 1
/***********************************************************/

// ���� ����

#if 0

#include <stdio.h> 

       f2(void)
{
	static int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

	return a;
}

        f1(void)
{
	return f2;
}

int main(void)
{
	printf("%d\n",           f1( )          );	
}

#endif

// typedef ���?

#if 0

#include <stdio.h> 

typedef FP2     
typedef FP1     

FP2 f2(void)               
{
	static int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

	return a;
}

FP1 f1(void)                     
{
	return &f2;
}

int main(void)
{
	printf("%d\n",        f1( )      );
}

#endif

/***********************************************************/
// [2-5-10] : ������ �ڵ� ���� ���� 2
/***********************************************************/

#if 0 

#include <stdio.h> 

       f2(void)
{
	static int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

	return a;
}

        f1(void)
{
	return f2()[2];
}

int main(void)
{
	printf("%d\n",           f1( )          );	
}

#endif

/***********************************************************/
// [2-5-11] : ������ �ڵ� ���� ���� 3
/***********************************************************/

#if 0 

#include <stdio.h> 

       f2(void)
{
	static int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

	return &a;
}

        f1(void)
{
	return f2()[0];
}

int main(void)
{
	printf("%d\n",           f1( )          );	
}

#endif

/***********************************************************/
// [2-5-12] : ������ �ڵ� ���� ���� 4
/***********************************************************/

#if 0

#include <stdio.h> 

struct _st
{
	int num;
	char * name;
};

                 f2(void)                     // [1]
{
	static struct _st a[2][3] = {{{1,"KIM"}, {2,"SONG"}, {3, "KI"}}, {{4, "KANG"}, {5, "PARK"}, {6, "LEW"}}};
	return a;
}

                f1(int num)                   // [2]
{
	return f2()[num];
}

int main(void)
{
	printf("%s\n",          f1(0)                 );   // [3]
}

#endif

/***********************************************************/
// [2-5-13] : ������ �ڵ� ���� ���� 5
/***********************************************************/

#if 0 
#include <stdio.h>
int *f1(void) {
	static int a[4] = {1,2,3,4};
	return a;
}

int *f2(void) {
	static int a[4] = {10,20,30,40};
	return a;	
}
int *(*fa[2])() = {f1, f2};
int f4(void) { return 1; }

int *(**func1(void))() {     // [1]
	return fa;
}

int *(*func2(int (*p)()))() { return func1()[p()]; }

int main(void)
{
	printf("%d\n",     func2(f4)()[3]      );   // [3]
}

#endif

/***********************************************************/
// [2-6-1] : ���� �迭
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, x;
	int **p;

	x = 3;

	p = malloc(x * sizeof(int *));

	for(i=0; i<x; i++)
	{
		p[i] = malloc(4 * sizeof (int));
	}

	for(i=0; i<x; i++)
	{
		for(j=0; j<4; j++)
		{
			p[i][j] = i*4+j;
		}
	}

	for(i=0; i<x; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	for(i=0; i<x; i++)
	{
		free(p[i]);
	}

	free(p);
}

#endif

/***********************************************************/
// [2-6-2] : ���� �޸𸮷� �Ҵ��� ���� �迭
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, x;
	int **p;

	x = 3;

	p = malloc(x * sizeof(int *));
	p[0] = malloc(x * 4 * sizeof(int));

	for(i=1; i<x; i++)
	{
		p[i] = p[0] + i*4;
	}

	for(i=0; i<x; i++)
	{
		for(j=0; j<4; j++)
		{
			p[i][j] = i*4+j;
		}
	}

	for(i=0; i<x; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	free(p[0]);
	free(p);
}

#endif

/***********************************************************/
// [2-6-3] : ������͸� �̿��� ���� �迭
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, x;
	int (*p)[4];

	x = 3;

	p = malloc(x * sizeof(int [4]));

	for(i=0; i<x; i++)
	{
		for(j=0; j<4; j++)
		{
			p[i][j] = i*4+j;
		}
	}

	for(i=0; i<x; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	free(p);
}

#endif

/***********************************************************/
// [2-6-4] : ���? ��Ҽ���? ������ �迭
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, m, n;
	int **p;

	m = 3, n = 4;

	p = malloc(m * sizeof(int *));
	p[0] = malloc(m * n * sizeof(int));

	for(i=1; i<m; i++)
	{
		p[i] = p[0] + i*n;
	}

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			p[i][j] = i*n+j;
		}
	}

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	free(p[0]);
	free(p);
}

#endif

/***********************************************************/
// [2-6-5] : 1���� �迭�� ���ķ��̼�
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int m = 3, n = 4;
	int *p;

	p = malloc(m * n * sizeof(int));

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			p[i*n+j] = i*n+j;
		}
	}

	for(i=0; i<(m*n); i++)
	{
		printf("%d\n", p[i]);
	}

	free(p);
}

#endif

/***********************************************************/
// [2-7-1] : ���� ���� ����
/***********************************************************/

#if 0

#include <stdio.h> 

int main(void)
{
	char a[ ] = "Motel";
	char *p   = "Motel";

	a[0] = 'H';
	p[0] = 'H';

	printf("%s\n", a);
	printf("%s\n", p);
}

#endif

/***********************************************************/
// [2-7-2] : Call by Address�� �ŷڼ�
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int *p)
{
	int i, s = 0;

	for(i=0; i<5; i++)
	{
		s += p[i];
		p[i] = 0;
	}

	return s;
}

int main(void)
{
	int r;
	int a[5] = {1,2,3,4,5};

	r = sum(a);
	printf("%d, %d\n", r, a[0]);
}

#endif

#if 0

#include <stdio.h>

int sum(const int *p)
{
	int i, s = 0;

	for(i=0; i<5; i++)
	{
		s += p[i];
		p[i] = 0;
	}

	return s;
}

int main(void)
{
	int r;
	int a[5] = {1,2,3,4,5};

	r = sum(a);
	printf("%d, %d\n", r, a[0]);
}

#endif

#if 0

#include <stdio.h>

int sum(const int *p)
{
	int i, s = 0;
	int *q = p;

	for(i=0; i<5; i++)
	{
		s += q[i];
		q[0] = 0;
	}

	return s;
}

int main(void)
{
	int r;
	int a[5] = {1,2,3,4,5};

	r = sum(a);
	printf("%d, %d\n", r, a[0]);
}

#endif

/***********************************************************/
// [2-7-3] : Read Only Lookup Table
/***********************************************************/

#if 0

#include <stdio.h>

int a[4] = {1,2,3,4};
const int b[4] = {10,20, 30, 40};

int main(void)
{
	a[0] = 100;
	b[0] = 100;

	printf("%d %d\n", a[0], b[0]);
}

#endif

/***********************************************************/
// [2-7-4] : typedef�� type qualifier
/***********************************************************/

#if 0

#include <stdio.h>

typedef int ** IPP;

int main(void)
{
	int a[4] = {1,2,3,4};
	int *p = a;
	
	int const ** p1 = &p;
	int * const * p2 = &p;
	int ** const p3 = &p;
	const int ** p4 = &p;

	const IPP p5 = &p;

	**p1 = 200;
	*p2 = a+1;
	p3 = &p+1;
	**p4 = 300;
	
	p5 = &p+1;
	*p5 = a+1;
	**p5 = 400;
	
	printf("%d, %d\n", a[0], a[1]);
}

#endif

/***********************************************************/
// [2-8-1] : Type casting ���� 1
/***********************************************************/

#if 0

#include <stdio.h>

void func(int x)
{
	printf("%f\n",                            );
	printf("%f\n",                            );
	printf("%f\n",                            );
}

int main(void)
{
	double d[3] = {3.14, 5.125, -7.42};

	func((int)d);
}

#endif

#if 0

#include <stdio.h>

void func(int x)
{
	int i;

	for(i=0; i<3; i++)
	{

	}
}

int main(void)
{
	double d[3] = {3.14, 5.125, -7.42};

	func((int)d);
}

#endif

/***********************************************************/
// [2-8-2] : Type casting ���� 2
/***********************************************************/

#if 0

#include <stdio.h>

void func(void * p)
{
	int i;

	for(i=0; i<3; i++)
	{
		printf("%f\n",              );
	}
}

int main(void)
{
	double d[3] = {3.14, 5.125, -7.42};
	void *p = d;

	func(&p);
}

#endif

/***********************************************************/
// [2-8-3] :  Type casting ���� 3
/***********************************************************/

#if 0

#include <stdio.h>

void func(void *p)
{
	printf("%s\n",          );
}

int main(void)
{
	char * p = "Willtek";
	func(&p);
}

#endif

/***********************************************************/
// [2-8-4] : Type casting ���� 4
/***********************************************************/

#if 0

#include <stdio.h>

struct st {
	int i;
	char c;
};
typedef struct st S;

void func(long long int a) {
	printf("%d\n",(*(S*)(&a)).i);
	printf("%c\n",(*(S*)(&a)).c);
	//printf("%c\n",(*(struct st**)&a)->c);
}

int main(void)
{
	struct st x = {100, 'A'};

	func(*(long long int *)&x);
}

#endif

/***********************************************************/
// [2-8-5] : int ������ �Լ� �����ϱ�
/***********************************************************/

#if 0 

#include <stdio.h>

int func(int a, int b) {
	return a+b;
}
	
int main(void) {
	int a = (int)func;
	printf("%d\n", func(3,4));
	//printf("%d\n",(*(int(*)())a)(3,4));
	printf("%d\n", (*(int(**)())&a)(3,4)                );
}

#endif

/***********************************************************/
// [2-8-6] : Type casting ���� 5
/***********************************************************/

#if 0 
#include <stdio.h>
void func(void * p) {
	printf("%d\n",  (*(int(**)(int,int))p)(3,4)           );
}

int add(int a, int b) {
	return a+b;
}
	
int main(void) {
	void *p = (void *)add;
	func(&p);
}

#endif

/***********************************************************/
// [2-8-7] : printf�� argument ���� 
/***********************************************************/

#if 0

#include <stdio.h>
  
int add(int a, int b)
{
	return a+b;
}

int main(void)
{
	printf("%d\n", add(3));
	printf("%d\n", add(3,4,5));
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
	int a = 1, b = 2, c = 3;

	printf("���� Argument : %d %d \n", a, b, c);
	printf("���� Argument : %d %d %d\n", a, b);
}

#endif

/***********************************************************/
// [2-8-8] : ������ �μ�����
/***********************************************************/

#if 0 

#include <stdio.h>

int my_add(int cnt, ...)
{
	int i, sum = 0;

	for(i = 1; i<= cnt; i++)
	{
		sum += *(int*)(&cnt+i);

	}
	return sum;
}

int main(void)
{
	printf("%d\n", my_add(3,7,5,4));
	printf("%d\n", my_add(5,1,2,6,9,10));
}

#endif

/***********************************************************/
// [2-8-9] : ���������� access
/***********************************************************/

#if 0

#include <stdio.h>

void my_ellipsis(int a, ...)
{
	printf("%d\n", a);
	printf("%u\n",                );
	printf("%c\n",                );
	printf("%f\n",                );
	printf("%f\n",                );
}

int main(void)
{
	int a = 10; 
	unsigned char b = 100; 
	unsigned char c = 'A';
	float d = 3.14f; 
	double e = 5.125;
	
	my_ellipsis(a,b,c,d,e);
}

#endif

/***********************************************************/
// [2-8-10] : �絵�� - �Ǽ��� �μ�
/***********************************************************/

#if 0 

#include <stdio.h>

int main(void)
{
	float f = 3.5f;

	printf("%#x\n", f);
}

#endif

#if 0 

#include <stdio.h>

int main(void)
{
	float f = 3.1f;

	printf("%#x\n", f);
}

#endif

/***********************************************************/
// [2-8-11] : �Ǽ��� �޸� ���� dump
/***********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	float a = 3.5f;
	double b = 3.5;

	printf("float : %#.8x\n",         );
	
	printf("double: %#.8x : %.8x\n\n",        ,        );
}

#endif


/***********************************************************/
// [2-8-12] : ���� format �������� �̿�
/***********************************************************/

#if 0

#include <stdio.h>

void my_printf(char * fmt, ...)
{
	int *ap = (int *)&fmt + 1;

	while(*fmt)
	{
		switch(*fmt++)
		{
			case 'u' : printf("%u\n",              	); break;
			case 'd' : printf("%d\n",              	); break;
			case 'c' : printf("%c\n",         		); break;
			case 'f' : printf("%f\n",  				); break;
			case 's' : printf("%s\n",  			    ); break;
		}
	}
}

int main(void)
{
	int a = 10; 
	unsigned char b = 100; 
	unsigned char b2 = 'A';
	float c = 3.14f; 
	double d = 5.125;
	
	my_printf("ducffsd",a,b,b2,c,d,"Keyseek",100);
	my_printf("fdsc", -10.75, 100, "Willtek", 'B');
}

#endif

/***********************************************************/
// [2-8-13] : �������� ���޿� macro�� Ȱ��
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdarg.h>

void my_printf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	while(*fmt)
	{
		switch(*fmt++)
		{
			case 'u' : printf("%X\n", va_arg(ap, unsigned int)); break;	
			case 'd' : printf("%d\n", va_arg(ap, int)); break;	
			case 'c' : printf("%c\n", va_arg(ap, char)); break;
			case 'f' : printf("%f\n", va_arg(ap, double)); break;	
			case 's' : printf("%s\n", va_arg(ap, char *)); break;	
		}
	}

	va_end(ap);
}

int main(void)
{
	int a = 10; unsigned char b = 100; unsigned char b2 = 'A';
	float c = 3.14f; double d = 5.125;

	my_printf("ducffsd",a,b,b2,c,d,"Keyseek",100);
	my_printf("fdsc", -10.75, 100, "Willtek", 'B');
}

#endif

/***********************************************************/
// [2-8-14] : my_add �Լ��� �缳��
/***********************************************************/

#if 0 

#include <stdio.h>
#include <stdarg.h>

int my_add(int cnt, ...) {
	int i, sum = 0;
	for(i = 1; i<= cnt; i++) {
		printf("%d\n",*(int*)(&cnt+i));
		sum+=(*(int*)(&cnt+i));
	}
	return sum;
}

int main(void) {
	printf("%d\n",my_add(3,7,5,4));
	//printf("%d\n", my_add(5,1,2,6,9,10));
}

#endif

/***********************************************************/
// [2-8-15] : ��¥ printf ó�� �����ϴ� �Լ�
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdarg.h>

int my_printf(char * fmt,...) {
	int n;
	va_list ap;
	char string[256];

	va_start(ap,fmt);
	n = vsprintf(string,fmt,ap);
	printf(string);
	va_end(ap);
	return n;
}

int main(void) {
	int a = 10;
	unsigned char b = 100;

	unsigned char b2 = 'A';
	float c = 3.14f;
	double d = 5.125;

	my_printf("ANSWER = %d %u %c %1.2f %1.3f %s %d\n",a,b,b2,c,d,"Keyseek",100);
}

#endif

/***********************************************************/
// [2-8-16] : Data Parsing ���� 1
/***********************************************************/

#if 0 
#include <stdio.h>
struct _st {
	int i;
	char c;
};

void my_test(char c,...) {
	printf("%c\n",c);
	printf("%d\n",(*(struct _st*)(&c+4)).i);
	printf("%c\n",((struct _st*)(&c+4))->c);
	printf("%s\n",*(char**)(&c+12));
	printf("%f\n",(*(double**)(&c+16))[0]);
	printf("%f\n",(*(double**)(&c+16))[1]);
	printf("%f\n",(*(double**)(&c+16))[2]);
	printf("%d\n",(*(int(**)())(&c+20))(3,4));
}

int add(int a,int b) {
	return a+b;
}

int main(void) {
	char a = 'A';
	struct _st x={100, 'B'};
	double d[3] ={3.14, 5.19, -7.42};

	my_test(a,x,"Song",d,add);
}

#endif

/***********************************************************/
// [2-8-17] : Data Parsing ���� 2
/***********************************************************/

#if 0 
#include <stdio.h>
void my_test(int a,...) {
	// [1] �Ѿ��? 3.14 �μ�
	printf("f => %.2f\n",*(double*)(*(double**)(&a+1)));
	// [2] �Ѿ��? �迭�� �̿��Ͽ� f1 �Լ��� ����ȣ���Ͽ� ���ڿ� BIN ���?
	printf("%s",(*(char*(***)())(&a+2))[0]()+2);
	// [3] �Ѿ��? �迭�� �̿��Ͽ� f2 �Լ��� ����ȣ���Ͽ� ���ڿ� GO ���?
	typedef char*(**FT)();
	printf("%s\n",(*(FT*)(&a+2))[1]()+2);
}

char * f1(void) { return "CABIN"; }
char * f2(void) { return "LOGO"; }
int main(void) {
	double d = 3.14;
	char * (*fa[2])() ={f1, f2};
	my_test(1,&d,fa);
	printf("%d",1);
}
#endif

/**********************************************************/
// 3��. ������ ������ ������ �𵨸�
/**********************************************************/

/***********************************************************/
// [3-1-1] : ����ü�� �޸� ����
/***********************************************************/

#if 0

#include <stdio.h>

struct _st {
	short a;
	int b;
	char c;
	int d;
}st ={0x1111, 0x22222222, 0x33, 0x44444444};

int main(void) {
	printf("%d\n",sizeof(st));
}

#endif

/***********************************************************/
// [3-1-2] : ����ü�� �޸� ����
/***********************************************************/

#if 0

struct _st {
	short a;
	char b;
	int c;
	int d;
}st ={0x1111, 0x33, 0x22222222, 0x44444444};

int main(void) {
	printf("%d\n",sizeof(st));
}

#endif

/***********************************************************/
// [3-1-3] : ����ü �������� parsing
/***********************************************************/

#if 0

#include <stdio.h>

//#define  BUF	 ((unsigned char *)0x100)

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  BUF	 (buf)

struct st {
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

int main(void) {
	struct st info;

	info.x = *BUF;
	info.y = *(BUF+1);
	info.length = *(unsigned short *)(BUF+2);

	printf("0x%x, 0x%x, 0x%x\n",info.x,info.y,info.length);
}

#endif

/***********************************************************/
// [3-1-4] : ����ü �����͸� �̿��� �׼���
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  BUF	 (buf)

struct st {
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

int main(void) {
	struct st *info;

	info = (struct st *)BUF;
	printf("0x%x, 0x%x, 0x%x\n",info->x,info->y,info->length);

	info++;
	printf("0x%x, 0x%x, 0x%x\n",info->x,info->y,info->length);
}
#endif

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  info	 ((struct st *)buf)

struct st {
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

int main(void) {
	printf("0x%x, 0x%x, 0x%x\n",info->x,info->y,info->length);
	printf("0x%x, 0x%x, 0x%x\n",(info+1)->x,(info+1)->y,(info+1)->length);
}

#endif

/***********************************************************/
// [3-1-5] : ������ ����ü ������
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  info	 ((struct st *)buf)

struct st {
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

int main(void) {
	int i;

	for(i=0; i<4; i++) {
		printf("0x%x, 0x%x, 0x%x\n",);
	}
}

#endif

/***********************************************************/
// [3-1-6] : ������ ����ü�� ����ü �迭�̴�
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  info	 ((struct st *)buf)

struct st {
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

int main(void) {
	int i;

	for(i=0; i<4; i++) {
		printf("0x%x, 0x%x, 0x%x\n",);
	}
}

#endif

/***********************************************************/
// [3-1-7] : ����ü Ȱ���� ������
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  info	 ((struct st *)buf)

struct st {
	unsigned char x;
	unsigned char y;
	unsigned int length;
};

int main(void) {
	printf("0x%x, 0x%x, 0x%x\n",info[0].x,info[0].y,info[0].length);
	printf("0x%x, 0x%x, 0x%x\n",info[1].x,info[1].y,info[1].length);
}

#endif

/***********************************************************/
// [3-1-8] : ����ü ���? alignment ����
/***********************************************************/

#if 0

#include <stdio.h>

struct _s1 {
	short a;
}s1={0x1234};

struct _s2 {
	short a;
	int b;
	char c;
	double d;
}s2={0x1234, 0x56789abc, 0xfe, 3.14};

struct _s3 {
	char a;
	short b;
	int c[2];
}s3={0x12, 0x3456, {0xfedcba98, 0x13579bdf}};

int main(void) {
	printf("%d, %p\n",sizeof(s1),&s1.a);
	printf("%d, %p, %p, %p, %p\n",sizeof(s2),&s2.a,&s2.b,&s2.c,&s2.d);
	printf("%d, %p, %p, %p, %p\n",sizeof(s3),&s3.a,&s3.b,&s3.c[0],&s3.c[1]);
}

#endif

/***********************************************************/
// [3-1-9] : pack�� �����? ����ü ���? alignment ����
/***********************************************************/

#if 0

#include <stdio.h>

#pragma pack(1)

struct _s1 {
	short a;
}s1={0x1234};

#pragma pack(4)

struct _s2 {
	short a;
	int b;
	char c;
	double d;
}s2={0x1234, 0x56789abc, 0xfe, 3.14};

#pragma pack(1)

struct _s3 {
	char a;
	short b;
	int c[2];
}s3={0x12, 0x3456, {0xfedcba98, 0x13579bdf}};

#pragma pack(8)

int main(void) {
	printf("%d, %p\n",sizeof(s1),&s1.a);
	printf("%d, %p, %p, %p, %p\n",sizeof(s2),&s2.a,&s2.b,&s2.c,&s2.d);
	printf("%d, %p, %p, %p, %p\n",sizeof(s3),&s3.a,&s3.b,&s3.c[0],&s3.c[1]);
}

#endif

/***********************************************************/
// [3-1-10] : pack �ɼ��� ���� ���� ����
/***********************************************************/

#if 0

#include <stdio.h>

#pragma pack(show)
#pragma pack(1)

struct _s1 {
	short a;
}s1={0x1234};

#pragma pack(push, 4)

struct _s2 {
	short a;
	int b;
	char c;
	double d;
}s2={0x1234, 0x56789abc, 0xfe, 3.14};

#pragma pack(pop)
#pragma pack(show)

struct _s3 {
	char a;
	short b;
	int c[2];
}s3={0x12, 0x3456, {0xfedcba98, 0x13579bdf}};

#pragma pack(8)

int main(void) {
	printf("%d, %p\n",sizeof(s1),&s1.a);
	printf("%d, %p, %p, %p, %p\n",sizeof(s2),&s2.a,&s2.b,&s2.c,&s2.d);
	printf("%d, %p, %p, %p, %p\n",sizeof(s3),&s3.a,&s3.b,&s3.c[0],&s3.c[1]);
}

#endif

/***********************************************************/
// [3-1-11] : pack���� ���ϴ� ����ü �����?
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] ={0x4d,0x4d,0x55,0x5f,0x45,0x6e,0x61,0x62,0x6c,0x65,0x44,0x43,0x61,0x63,0x68,0x65};

#define  info	 ((struct st *)buf)

#pragma pack(              )

struct st {
	unsigned char x;
	unsigned char y;
	unsigned int length;
};

#pragma pack(pop)

int main(void) {
	printf("0x%x, 0x%x, 0x%x\n",info[0].x,info[0].y,info[0].length);
	printf("0x%x, 0x%x, 0x%x\n",info[1].x,info[1].y,info[1].length);
}

#endif

/***********************************************************/
// [3-2-1] : ��Ʈ�ʵ� ����ü�� Ư¡
/***********************************************************/

#if 0

#include <stdio.h>

struct _st1 {
	unsigned char a:2;
	unsigned char b:3;
	unsigned char c:2;
}x;

struct _st2 {
	unsigned int a:2;
	unsigned int b:3;
	unsigned int c:2;
}y;

int main(void) {
	y.a = x.a = 0x2;
	y.b = x.b = 0x5;
	y.c = x.c = 0x1;

	printf("%d %d\n",sizeof(x),sizeof(y));
	printf("0x%X 0x%X 0x%X 0x%X\n",x.a,x.b,y.a,y.b);
	printf("0x%.2X 0x%.8X\n",*(unsigned char *)&x,*(unsigned int *)&y);
}

#endif

/***********************************************************/
// [3-2-2] : ���Ͻý����� ���� ���� �ð�
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] ={0x52,0x7a};

struct fat_time {
	unsigned char sec;
	unsigned char min;
	unsigned char hour;
};

int main(void) {
	struct fat_time time;
	unsigned short temp = *(unsigned short *)buf;

	time.hour = (temp>>11)&0x1f;
	time.min = (temp>>5)&0x3f;
	time.sec = (temp>>0)&0x1f;

	printf("Time=%d:%d:%d\n",time.hour,time.min,time.sec*2);
}

#endif

/***********************************************************/
// [3-2-3] : ��Ʈ�ʵ� ����ü�� Ȱ��
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] ={0x52,0x7a};

struct fat_time {



};

int main(void) {
	struct fat_time * time = (struct fat_time *)buf;

	printf("Time=%d:%d:%d\n",time->hour,time->min,time->sec*2);
	printf("Sizeof Time=%d\n",sizeof(struct fat_time));
}

#endif

/***********************************************************/
// [3-2-4] : ��Ʈ�ʵ� ����ü�� �����̳�
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] ={0x52,0x7a};

struct fat_time1 {
	unsigned int sec:5;
	unsigned int min:6;
	unsigned int hour:5;
};

struct fat_time2 {
	unsigned char sec:5;
	unsigned char min:6;
	unsigned char hour:5;
};

int main(void) {
	struct fat_time1 * time1 = (struct fat_time *)buf;
	struct fat_time2 * time2 = (struct fat_time *)buf;

	printf("Time=%d:%d:%d\n",time1->hour,time1->min,time1->sec*2);
	printf("Sizeof Time=%d\n",sizeof(struct fat_time1));
	printf("Time=%d:%d:%d\n",time2->hour,time2->min,time2->sec*2);
	printf("Sizeof Time=%d\n",sizeof(struct fat_time2));
}

#endif

/***********************************************************/
// [3-2-5] : ��Ʈ�ʵ��� �����? ������ Ÿ��
/***********************************************************/

#if 0

#include <stdio.h>

struct st {
	int a1:3;
	int a2:2;
	int a3:1;
}x;

int main(void) {
	x.a3 = -1;

	if(x.a3==-1) printf("TRUE\n");
	else printf("FALSE\n");

	x.a3 = 1;

	if(x.a3==1) printf("TRUE\n");
	else printf("FALSE\n");
}

#endif

/***********************************************************/
// [3-2-6] : Unnamed ��Ʈ�ʵ� ���?
/***********************************************************/

#if 0

#include <stdio.h>

volatile struct st {
	unsigned short LSEON:1;
	unsigned short LSERDY:1;
	unsigned short LSEBYP:1;
	unsigned short rsvd1:5;
	unsigned short RTCSEL:2;
	unsigned short rsvd2:5;
	unsigned short RTCEN:1;
}RTC_CR;

int main(void) {
	printf("%d\n",sizeof(RTC_CR));
}

#endif

#if 0

#include <stdio.h>

volatile struct st {
	unsigned short LSEON:1;
	unsigned short LSERDY:1;
	unsigned short LSEBYP:1;
	unsigned short:5;
	unsigned short RTCSEL:2;
	unsigned short:5;
	unsigned short RTCEN:1;
}RTC_CR;

int main(void) {
	printf("%d\n",sizeof(RTC_CR));
}

#endif

/***********************************************************/
// [3-2-7] : Zero Size Width ��Ʈ�ʵ�
/***********************************************************/

#if 0

#include <stdio.h>

volatile struct st {
	unsigned int a1:5;
	unsigned int a2:25;
	unsigned int a3:3;
	unsigned int a4:4;
}x ={0x1f, 0x0, 0x7, 0x0};

int main(void) {
	printf("%d\n",sizeof(x));
	printf("0x%.8x\n",((unsigned int *)&x)[0]);
	printf("0x%.8x\n",((unsigned int *)&x)[1]);
}

#endif

#if 0

#include <stdio.h>

volatile struct st {
	unsigned int a1:5;
	unsigned int:0;
	unsigned int a2:25;
	unsigned int:0;
	unsigned int a3:3;
	unsigned int:2;
	unsigned int a4:4;
}x ={0x1f, 0x1fffff, 0x7, 0xf};

int main(void) {
	printf("%d\n",sizeof(x));
	printf("0x%.8x\n",((unsigned int *)&x)[0]);
	printf("0x%.8x\n",((unsigned int *)&x)[1]);
	printf("0x%.8x\n",((unsigned int *)&x)[2]);
}

#endif

/***********************************************************/
// [3-2-8] : ����ü�� ����ü
/***********************************************************/

#if 0

#include <stdio.h>

union float_data {
	float f;

	struct {



	}bit;
}fdata;

int main(void) {
	fdata.f = 13.625;

	printf("%f\n",fdata.f);
	printf("sign(1bit):%x\n",fdata.bit.sign);
	printf("exponent(8bit):%x\n",fdata.bit.exp);
	printf("mantissa(23bit):%x\n",fdata.bit.mant);

	fdata.bit.sign = 1;
	printf("%f\n",fdata.f);
}

#endif

/***********************************************************/
// [3-2-9] : ���Ͻý����� ���� ���� �ν�
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] ={0x25, 0x0f};

struct fat_file {
	unsigned char r:1;
	unsigned char h:1;
	unsigned char s:1;
	unsigned char v:1;
	unsigned char d:1;
	unsigned char a:1;
};

#define fn	((struct fat_file *)buf)

int main(void) {
	int i;

	for(i=0; i<2; i++) {
		if() printf("Long File Name\n");
		else printf("A[%d]D[%d]V[%d]S[%d]H[%d]R[%d]\n",fn[i].a,fn[i].d,fn[i].v,fn[i].s,fn[i].h,fn[i].r);
	}
}

#endif

/***********************************************************/
// [3-2-10] : ȿ������ long file name�� �Ǵ�
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] ={0x25, 0x0f, 0x3f};

struct fat_file {
	unsigned char r:1;
	unsigned char h:1;
	unsigned char s:1;
	unsigned char v:1;
	unsigned char d:1;
	unsigned char a:1;
	unsigned char:0;
};

struct long_file {
	unsigned char ln:4;
	unsigned char:0;
};

union file {
	struct fat_file n;
	struct long_file l;
};

#define fn	((union file *)buf)

int main(void) {
	int i;

	for(i=0; i<3; i++) {
		if() printf("Long File Name\n");
		else printf("A[%d]D[%d]V[%d]S[%d]H[%d]R[%d]\n",fn[i].n.a,fn[i].n.d,fn[i].n.v,fn[i].n.s,fn[i].n.h,fn[i].n.r);
	}
}

#endif
