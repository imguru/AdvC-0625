#include <stdio.h>
// 1. line buffering: '\n' 을 만나기 전까지 입력을 받거나 출력을 하지 않는다.
//   => stdin, stdout

// 2. full buffering: 버퍼의 크기가 가득 차기 전까지 입력을 받거나 출력을 하지 않는다.
//   => 일반 파일

// 3. no buffering: 그냥 출력하거나 입력 받는다.
//   => stderr

// 버퍼를 비우는 표준 라이브러리 함수
//  => fflush
// 주의할점: stdin에 대해서는 동작하지 않는다.

int main()
{
	// printf("Hello");
	// putchar('\n');
	fprintf(stderr, "Hello");

	while (1);
}
