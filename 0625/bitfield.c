// Bit Field 구조체: 특정한 비트의 영역에 이름을 부여하고 싶을 때
// => 반드시 타입을 unsigned 지정한다.
// ~/.vimrc
// set tags+=/root/linux/tags

// tcphdr
//     이동: 저장하고 난 후, g + ]
//     복귀: Ctrl + t

typedef struct 
{
	signed char b1:2;
} AAA;

int main() {
	AAA a;
	a.b1 = 3; // 11
	printf("%d\n", a.b1 );
}

