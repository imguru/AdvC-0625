
// 구조체: 캡슐화
//    => 연관되는 다양한 타입을 묶어서 하나의 사용자 정의 타입을 설계한다.

// type: 구조체 태그
typedef struct type
{
	// 자기 참조 포인터를 만들 때는 반드시 태그가 존재해야 한다o.
	struct type *p;

	int a;
	int b;
	int c;
} Type;

// struct type i;
// struct type j;

Type a;
Type b;

int main()
{
	// i = j;
	a = b;
}




// i라는 구조체 변수를 만든 것이다.
#if 0
struct 
{
	int a;
	int b;
	int c;
} i;

struct 
{
	int a;
	int b;
	int c;
} j;

int main()
{
	i = j;
}
#endif



