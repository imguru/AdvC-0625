#include <stdio.h>
#include <stdlib.h>

void init(int* score, int* n)
{
	scanf("%d", n);
	score = (int*)malloc(sizeof(int) * *n);
}

int main()
{
	int* score;
	int n;
	int i = 0;

	init(score, &n);
	
	for (i = 0 ; i < n ; ++i)
		score[i] = i * 10;

	for (i = 0 ; i < n ; ++i)
		printf("%d\n", score[i]);
}
