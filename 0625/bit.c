#include <stdio.h>

// task_struct
//      files_struct
//      fd_array
//      fd_set
//      FD_ZERO
//      sigset_t


#define BIT_ZERO(x) do {int i;         \
	for (i = 0 ; i < 32 ; i++)     \
		x.data[i] = 0;} while(0)

// >> 5
// 0000 1000
//       100

// index % x  ==  index & (x - 1)
#define BIT_SET(x, index) (x.data[index>>5] |= 1 << (index & 31))
#define BIT_ISSET(x, index) (x.data[index>>5] & (1 << (index & 31)))
#define BIT_CLR(x, index) (x.data[index>>5] &= ~(1 << (index & 31)))

// typedef int bit_set[32];   // bit_set: int[32]
typedef struct {
	int data[32];
	// ...
} bit_set;

int main()
{
	int i;
	bit_set flag;
	BIT_ZERO(flag);
	
	// |: Set
	BIT_SET(flag, 100);
	BIT_SET(flag, 1000);

	// &: Check
	for (i = 0 ; i < 1024 ; ++i)
		if (BIT_ISSET(flag, i))
			printf("%d\n", i);

	BIT_CLR(flag, 1000);
}

#if 0
// 매크로 함수
//  => 성능이 중요한 연산은 매크로 함수로 만드는 것이 좋다.
//  주의할점
//   => 치환되는 연산입니다.
//      우선순위가 잘못 결합되는 문제를 방지해야 합니다.

#define BIT_ZERO(x) do {int i;         \
	for (i = 0 ; i < 32 ; i++)     \
		x[i] = 0;} while(0)

#define BIT_SET(x, index) (x[index/32] |= 1 << (index % 32))
#define BIT_ISSET(x, index) (x[index/32] & (1 << (index % 32)))
#define BIT_CLR(x, index) (x[index/32] &= ~(1 << (index % 32)))

typedef int bit_set[32];   // bit_set: int[32]

int main()
{
	int i;
	bit_set flag;

	// BIT_ZERO(flag);
	
	// |: Set
	BIT_SET(flag, 100);
	BIT_SET(flag, 1000);

	// &: Check
	for (i = 0 ; i < 1024 ; ++i)
		if (BIT_ISSET(flag, i))
			printf("%d\n", i);

	BIT_CLR(flag, 1000);
}
#endif

#if 0
// 아래의 코드는 이해하기 어렵다.
//  => 이해하기 쉽도록 추상화가 필요하다.
int main()
{
	int flag[4] = 0;  // 128 bit  -> 100 bit
	int i;

	// 100/32: index
	// 100%32: shift
	flag[100/32] |= 1<<(100%32);
	flag[8/32] |= 1<<(8%32);

	for (i = 0 ; i < 4 ; ++i)
		if (flag[i/32] & (1<<(i%32)))
			printf("%d\n", i);

	flag[8/32] &= ~(1<<(8%32));
}
#endif

// 비트필드를 이용한 flag 처리
#if 0
int main()
{
	int flag = 0;   // 32bit 
	int i;

	// |: Set
	flag |= 1<<0;
	flag |= 1<<3;

	// &: Check
	for (i = 0 ; i < 4 ; ++i)
		if (flag & (1<<i))
			printf("%d\n", i);

	// flag[3] = 0;
	// & ~: Clear
	flag &= ~(1<<3);
	// 0000 1001
	// 1111 0111 &
	// ---------
	// 0000 0001
}
#endif

#if 0
// flag 처리
//  => 있다, 없다

// 문제점
//  => 메모리 낭비가 심하다.
int main()
{
	int flag[4] = {0, };
	int i;

	flag[0] = 1;
	flag[3] = 1;

	for (i = 0 ; i < 4 ; ++i)
	{
		if (flag[i])
			printf("%d\n", i);
	}
	
	flag[3] = 0;
}
#endif
