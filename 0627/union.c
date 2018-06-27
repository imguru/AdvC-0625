// union - 공용체 

// C 언어에서 사용자 정의 타입을 만드는 방법
//  1. struct
//  2. union
//  3. enum

struct
{
	int i;
	float f;
} sa;


// 활용 예
// - 상호 베타적인 정보를 관리할 때.

// union 크기는 내부 멤버 중 가장 큰 크기를 가지는
// 멤버에 의해서 결정된다.
// variant
union 
{
	int i;
	float f;
} ua;

struct ext4 {};
struct ntfs {};
struct ext2 {};

union filesystem
{
	struct ext4 ext4;
	struct ntfs ntfs;
	// ...
}


int main()
{
	printf("sa: %ld\n", sizeof(sa));
	printf("ua: %ld\n", sizeof(ua));
}










