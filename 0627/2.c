
// tcphdr
// 비트 필드 구조체
#include <stdio.h>
#include <stdlib.h>

// 메모리를 효율적으로 사용할 수 있다
struct info
{
	unsigned short year:2, score:7, sex:1;
	// 2bit: 0 ~ 3
	// 7   : 0 ~ 127
	// 1   : 0 ~ 1
};

int main()
{
	struct info i;
	i.year = 3;
	i.score = 88;
	i.sex = 0;

	printf("sizeof(struct info): %ld\n", sizeof(struct info));
	printf("year=%d score=%d sex=%d\n", i.year, i.score, i.sex);
}
