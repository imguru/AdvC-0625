#include <stdio.h>
#include <stdlib.h>

void init(int** score, int *n)
{
	printf("명수  입력:");
	scanf("%d", n );
	*score = (int*)malloc( sizeof(int) * (*n) );
}

int main()
{
	int* score;
	int n;

	init(&score, &n);
}
