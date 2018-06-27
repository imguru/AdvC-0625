#include <stdio.h>

// memcpy  - 중첩된 영역에서 제대로 동작하지 않습니다.
// memmove 


// [ 1, 1, 3, 4, 5]
// memcpy(arr + 1, arr, 3);


// 얕은 복사
struct user
{
	char name[32];  // 멤버 변수 
	int age;
};

// Read only
void print_user(const struct user *user)
{
	// printf("name=%s, age=%d\n", (*user).name, (*user).age);
	printf("name=%s, age=%d\n", user->name, user->age);
}

#if 0
void print_user(struct user user)
{
	printf("name=%s, age=%d\n", user.name, user.age);
}
#endif


int main()
{
	// 구조체는 일반적인 타입(int, char, double)과 동일하게 동작한다.
	struct user user = { "Tom", 42 };
	print_user(&user);


#if 0
	struct user user1 = { "Tom", 42 };
	struct user user2 = user1;

	printf("name: %s\n", user1.name);
	printf("age: %d\n", user1.age);
#endif
}
