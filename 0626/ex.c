
// 삼중 포인터의 개념과 활용 방법
// => 이중 포인터에 대해서 Call by reference
#include <stdio.h>
#include <stdlib.h>
// malloc / free

// 표준 라이브러리 기본 Stream 3가지
// stdin 
// stdout
// stderr

int main()
{
	char name;

	name = fgetc(stdin);
	printf("%c\n", name);

	return 0;
	// getchar(), getc(), fgetc()
	


	// Keyboard Stream: FILE* 
	// 저수준 IO / 고수준 IO
	// => 버퍼링을 하는가?
}
