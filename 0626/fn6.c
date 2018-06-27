int (*(*(*(*q)[2])(void))(void))[2]

// typedef 을 통해서 간략화 해보세요.
typedef int (*FP1)[2];
typedef FP1 (*FP2)(void);
typedef FP2 (*FP3)(void);
typedef FP3 (*FP4)[2];

FP4 q;
