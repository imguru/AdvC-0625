#include <math.h>
#include <stdio.h>

int main()
{
	double a = 0.7;
	double b = 0.1 * 7;
	// 핵심: 부동 소수점 타입은 오차가 있기 때문에
	//     절대 ==, != 으로 비교하면 안됩니다. 
	//  비교하는 방법
	//    fabs(a-b) < 0.0000001
	// if (a == b)
	// vi: manpage
	//  -> K
	if (fabs(a-b) < 0.000001)
	{
		printf("same\n");
	}
	else
	{
		printf("diff\n");
	}
}
