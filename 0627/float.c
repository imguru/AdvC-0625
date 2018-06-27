#include <stdio.h>
// 부동 소수점의 내부 구조 파싱 코드

typedef struct 
{
	unsigned int b1:4, b2:4, b3:4, b4:4, b5:4, b6:4, b7:4, b8:4;
} BIT;

typedef union 
{
	float f;
	BIT   b;
} U;

int main()
{
	U u;
	u.f = 10.25f;
	
	printf("%4x %4x %4x %4x %4x %4x %4x %4x\n",
		u.b.b1,
		u.b.b2,
		u.b.b3,
		u.b.b4,
		u.b.b5,
		u.b.b6,
		u.b.b7,
		u.b.b8);
}
