#include <iostream>
using namespace std;

int main() {
    // cout和cin一般用来进行控制台的输出和输入，这两个函数都存在于iostream库里
    // cout用的是左移运算符：<<
    // cin用的是右移运算符：>>
    // endl是换行的意思
    int i = 0;
    do {
        cin >> i;
        cout << "输入为：" << i << endl;
    } while (i != 0);
    
    return 0;
}
