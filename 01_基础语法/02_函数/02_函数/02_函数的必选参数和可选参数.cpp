#include <iostream>
using namespace std;

// 1、函数的必选参数和可选参数是什么？
// 当我们不给函数的参数赋默认值时，这个参数就是个必选参数，函数调用时就必须得传这个参数
// 当我们给函数的参数赋默认值时，这个参数就是个可选参数，函数调用时就可以选择性地传这个参数
int sub(int i1, int i2) {
    return i1 - i2;
}

int sub1(int i1 = 0, int i2 = 0) {
    return i1 - i2;
}

int sub2(int i1, int i2 = 0) {
    return i1 - i2;
}

// 2、函数的必选参数和可选参数注意事项
// （1）可选参数只能存在于参数列表的右边，必须参数只能存在于参数列表的左边
// 也就是说可选参数的右边不能存在必选参数，必选参数的左边不能存在可选参数
//int sub3(int i1 = 0, int i2) {
//    return i1 - i2;
//} // 编译报错
// （2）如果函数的声明和实现都存在，则给参数赋默认值的操作只能在声明阶段，不能在实现阶段
int sub4(int i1 = 0, int i2 = 0);
int sub4(int i1, int i2) {
    return i1 - i2;
}

int main() {
    cout << sub(10, 20) << endl; // -10
    cout << sub1() << endl; // 0
    cout << sub2(10) << endl; // 10
    
    cout << sub4(10) << endl; // 10
    
    return 0;
}
