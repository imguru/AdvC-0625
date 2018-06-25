#include <stdio.h>
#include <stdlib.h>

// 이중 포인터의 개념과 활용
void init(int **score, int *n)
{
	printf("명수 입력: ");
	scanf("%d", n);

	*score = (int*)malloc(sizeof(int) * (*n));
}

void input(int* score, int n)
{
	int i;
	for (i = 0 ; i < n ; ++i)
	{
		printf("점수 입력: ");
		// scanf("%d", &score[i]);
		// scanf("%d", &*(score + i));
		scanf("%d", score + i);
	}
}

void output(int* score, int n)
{
	int i = 0;
	for (i = 0 ; i < n ; ++i)
		printf("%d\n", score[i]);
}

int main()
{
	int n;
	int *score;

	init(&score, &n);
	input(score, n);
	output(score, n);

	free(score);
	return 0;
}





