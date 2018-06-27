// 빅 엔디안: 시작 주소에 상위 바이트부터 기록한다.
// 리틀 엔디안: 시작 주소에 하위 바이트부터 기록한다.

// 0x12345678
// BigEndian: [12][34][56][78]
// LittleEndian: [78][56][34][12]


// 엔디안 방식: 2바이트 이상을 저장할 때 의미가 있다.
// tcphdr

#include <stdio.h>

void printByteOrder(void *value, int size)
{
	int i;
	char* p = (char*)value;
	for (i = 0 ; i < size ; ++i)
		printf("%x ", p[i]);
	putchar('\n');
}

int main()
{
	int value = 0x12345678;
	printByteOrder(&value, sizeof value);
}
