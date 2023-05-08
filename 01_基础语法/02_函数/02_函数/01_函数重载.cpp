#include <iostream>
using namespace std;

// 1、函数重载是什么？
// 函数重载是指两个函数的函数名相同、但是参数列表不同（可以是参数的个数不同，也可以是参数的类型的不同）
// 返回值和执行体不做要求
int add(int i1, int i2) {
    return i1 + i2;
}

int add(int i1, int i2, int i3) {
    return i1 + i2 + i3;
}

double add(double d1, double d2) {
    return d1 + d2;
}

// 2、函数重载的本质是什么？
// 其实编译器在编译期间会为每个函数生成一个唯一符号，这个唯一符号就唯一对应着该函数的内存地址
// 在C里，每个函数的唯一符号是：_函数名，比如_main、_add
// 在C++里，每个函数的唯一符号是：_函数名第一个参数的类型缩写第二个参数的类型缩写，比如_main、_addii、_addiii、_adddd
// 这可以通过汇编来验证
// 可见C里函数的唯一符号只跟函数名有关，而C++里函数的唯一符号则跟函数名和函数参数都有关，这也是为什么C不支持函数重载而C++支持函数重载的原因

int main() {
    cout << add(10, 20) << endl;
    cout << add(10, 20, 30) << endl;
    cout << add(10.10, 20.20) << endl;
    
    return 0;
}
