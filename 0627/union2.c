
#include <stdio.h>

// IPv4(32bit)
//  192.168.0.170
//  0xc0a800aa

// 동일한 데이터를 다른 형식으로 표현하고 싶을 때 - 메모리 파싱
union ip
{
	unsigned int addr;
	unsigned char a[4];
};


int main()
{
	union ip addr;
	addr.addr = 0xc0a800aa;
	printf("%u.%u.%u.%u\n", addr.a[3], addr.a[2], addr.a[1], addr.a[0]);
}



#if 0
union
{
	int i;
	float f;
} a;

// 가장 최근에 대입한 값만 유효하다.
int main()
{
	a.i = 65535;

	printf("%d\n", a.i);

}
#endif
