## 八、std::stack

栈|_|先进后出，即只允许栈顶进栈顶出，所以只能访问栈顶元素而不能访问栈底和栈中间的元素，要想访问栈底和栈中间的元素就只能把栈顶元素pop出去让下面的元素成为新的栈顶元素，因此如需访问任意位置的元素请考虑使用vector、list等数据结构。

#### 1、基本使用

```c++
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // 声明且默认初始化为一个空栈
    stack<int> s;
    
  	// push入栈
    s.push(1);
    s.push(2);
    s.push(3);
    
  	// pop出栈
    s.pop();
    s.pop();
    
  	// top获取栈顶元素
    cout << s.top() << endl; // 1
    
  	// size获取栈的大小
    cout << s.size() << endl; // 1
    
  	// empty判断栈是不是空
    cout << s.empty() << endl; // 0
    
    return 0;
}
```

#### 2、底层原理

后续。
