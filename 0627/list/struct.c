
#include <stdio.h>

// 구조체 - 정렬
//  => int(4byte)    : 메모리의 주소가 4의 배수인 곳에 들어가야 한다.
//     double(8byte) : 메모리의 주소가 8의 배수인 곳에 들어가야 한다.
//     char(1byte)   : 4 배수
struct AAA
{
	int a;     // 0
	double b;  // 8
	char c;    // 16
};

struct BBB
{
	double b;  // 0
	int a;     // 8
	char c;    // 12
};

int main()
{
	printf("sizeof:%ld\n", sizeof(struct AAA));
	printf("sizeof:%ld\n", sizeof(struct BBB));
}
