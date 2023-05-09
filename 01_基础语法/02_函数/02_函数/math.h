#ifndef math_h
#define math_h

// 最初的实现
//int add(int i1, int i2);
//int sub(int i1, int i2);
//int mult(int i1, int i2);
//int divi(int i1, int i2);

// 用extern "C"修饰函数的声明
// 但是这个文件是按照C的编译规则去编译的，而C的编译器是不认识extern "C"的，只有C++的编译器才认识extern "C"，所以直接写的话会报错
//extern "C" {
//    int add(int i1, int i2);
//    int sub(int i1, int i2);
//    int mult(int i1, int i2);
//    int divi(int i1, int i2);
//}
// 因此我们得判断一下是不是C++环境，如果是C++环境————即外界是C++在导入这个头文件————再用extern "C"修饰，这里会用到系统提供的一个宏
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int add(int i1, int i2);
int sub(int i1, int i2);
int mult(int i1, int i2);
int divi(int i1, int i2);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* math_h */
