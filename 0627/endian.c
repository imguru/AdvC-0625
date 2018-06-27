// Little Endian / Big Endian
// Endian:
//    CPU가 메모리에 저장하고 읽는 방식

// CPU
//  x86/x64(ia64) - Little Endian
//  ARM           - Little? Big?

// tcphdr


// 엔디안 방식을 통일
//   => 빅 엔디안(네트워크 엔디안)

// 현재의 시스템의 엔디안을 확인하는 방법?
#include <stdio.h>

// 시스템에 매크로가 이미 정의되어 있습니다.
int main()
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	printf("Little Endian\n");
#elif 
	printf("Big Endian\n");
#endif
}

