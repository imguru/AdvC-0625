
#include <stdio.h>
#include <stdint.h>

int main()
{
	int i;
	for (i = 0 ; i < 10000 ; ++i)
	{
		// ...
	}
}

#if 0
int main()
{
	printf("long: %ld\n", sizeof(long));
	printf("%ld\n", sizeof(int8_t));
	printf("%ld\n", sizeof(int16_t));
	printf("%ld\n", sizeof(int32_t));
	printf("%ld\n", sizeof(int64_t));
	printf("%ld\n", sizeof(uint8_t));
	printf("%ld\n", sizeof(uint16_t));
	printf("%ld\n", sizeof(uint32_t));
	printf("%ld\n", sizeof(uint64_t));
}
#endif
