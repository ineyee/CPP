#include <iostream>
using namespace std;

// 1、extern "C"是什么？
// 我们知道C和C++的编译规则是不同的，比如同样的一个函数int add(int i1, int i2);
// 按照C的编译规则，该函数对应的符号为_add
// 按照C++的编译规则，该函数对应的符号为_addii
// 而被extern "C"修饰的函数则会被强制按照C的编译规则去编译
// 比如下面两个函数，因为当前源文件是个.cpp文件，所以是按照C++的编译规则去编译，因此就能编译通过，因为C++支持函数重载
//int add(int i1, int i2);
//int add(double d1, double d2);
// 而下面两个函数就无法编译通过了，因为虽然当前源文件是个.cpp文件，但是这俩函数被extern "C"修饰了，所以会被强制按照C的编译规则去编译，C不支持函数重载
//extern "C" int add(int i1, int i2);
//extern "C" int add(double d1, double d2);

// 2、怎么使用extern "C"？
// （1）我们可以用extern "C"修饰每一个函数，也可以用extern "C" { ... }修饰一堆函数
//extern "C" int add(int i1, int i2);
//extern "C" int sub(int i1, int i2) {
//    return i1 - i2;
//}
//extern "C" {
//    int mutl(int i1, int i2);
//    int divi(int i1, int i2) {
//        return i1 / i2;
//    }
//}
// （2）如果函数的声明和实现都存在，则用extern "C"修饰的操作只能在声明阶段，不能在实现阶段
//extern "C" int mod(int i1, int i2);
//int mod(int i1, int i2) {
//    return i1 % i2;
//}

// 3、为什么要使用extern "C"？
// 比方说我们用C编写了一个math库
// 然后需要在这里————即C++代码里————调用这个math库，于是我们导入了这个库：#include "math.h"，无非就是拷贝了一堆C函数的声明过来
//int add(int i1, int i2);
//int sub(int i1, int i2);
//int mult(int i1, int i2);
//int divi(int i1, int i2);
// 但是在这里————即C++代码里————使用这些C函数的时候却报错了，报的错是找不到C函数的实现
// 这就是因为这里————03_externC.cpp————是C++的代码，所以拷贝过来的C函数声明其实会按照C++的编译规则去编译，即符号为_addii、_subii、_mutlii、_divii
// 而那里————math.c————是C的代码，所以那些C函数的实现是按照C的编译规则去编译，即符号为_add、_sub、_mutl、_div
// 符号都对不上，当然找不到实现了
// 因此我们就需要在math.h里用extern "C"修饰一下那些C函数的声明，以便这里————即C++代码里————拷贝过来的C函数声明就包含extern "C"
// 这样就算这里————即C++代码里————是按照C++的编译规则去编译，那些拷贝过来的C函数也会被强制按照C的编译规则去编译，就能够找到实现了
// 具体的实现见math.h
// 总的来说，extern "C"主要使用在C和C++混编的场景，即我们编写了一个C库，如果想让它在C和C++的代码里能都能被正常调用，那就得用extern "C"修饰那些库函数

int main() {
    return 0;
}
