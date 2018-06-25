#include <stdio.h>

// Shift (>>)
//   Arithmetic Shift: signed - >>
//     ; MSB(부호 비트)
//      음수: 1
//     	양수: 0
//   Logical Shift: unsigned  - >>>
//      0

int main()
{
	unsigned char c = -1;
	printf("%d\n", c >> 3);
}
