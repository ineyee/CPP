#include <iostream>
using namespace std;

// 1、引用类型是什么？
// “引用类型的变量其实就是其它数据类型变量的一个别名，这两个变量对应着同一块内存”————在高级语言使用层面给人的感觉是这样
// 基本数据类型、派生数据类型的变量都可以有别名————即引用
void test() {
    // i是一个int类型的变量
    int i = 10;
    // ir是i的别名，所以ir前面的数据类型要和i的数据类型int一致，而&必须跟引用变量紧挨着才表明是个引用变量
    int &ir = i;
    cout << i << endl; // 10
    cout << ir << endl; // 10
    
    // ip是一个int*类型的变量
    int *ip = &i;
    // ipr是ip的别名，所以ipr前面的数据类型要和ip的数据类型int*一致，而&必须跟引用变量紧挨着才表明是个引用变量
    int *&ipr = ip;
    cout << ip << endl; // 0x30410724c
    cout << ipr << endl; // 0x30410724c
}

// 2、引用类型的本质是什么？
// 引用的本质其实就是指针，所以它对应的其实是两块内存，只不过在高级语言使用层面给人的感觉是一块内存而已
// 因此一个引用类型的变量也是占用8个字节的内存
// 这可以通过汇编来验证
void test1() {
    int i = 10;
    
    // 这两句代码对应的汇编指令是一样的
    int &ir = i;
    int *ip = &i;
}

// 3、怎么使用引用类型？

// 4、为什么要是使用引用类型？

int main() {
//    test();
    test1();
    
    return 0;
}
