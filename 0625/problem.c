
int main()
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;

	// && ||
	// 1. 우선순위가 다르다.
	// 2. 우선순위는 먼저 계산하는 순서가 아니다.
	// 3. 결합을 결정한다.

	d = ++a || b++ && ++c;
	printf("%d %d %d %d\n", a, b, c, d);
	// 1 0 0 1

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	d = (++a && ++b) || ++c;
	printf("%d %d %d %d\n", a, b, c, d);
	// 1 1 0 1
}

