## 九、std::queue

队列| |先进先出，即只允许队尾进队头出，所以只能访问队尾元素和队头元素而不能访问队列中间的元素，要想访问队列中间的元素就只能把队头元素pop出去让上面的元素成为新的队头元素，因此如需访问任意位置的元素请考虑使用vector、list等数据结构。

#### 1、基本使用

```c++
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 声明且默认初始化为一个空队列
    queue<int> q;
    
    // push入队
    q.push(1);
    q.push(2);
    q.push(3);
    
    // pop出队
    q.pop();

    // front获取队头元素
    cout << q.front() << endl; // 2
    // back获取队尾元素
    cout << q.back() << endl; // 3

    // size获取队列的大小
    cout << q.size() << endl; // 2

    // empty判断队列是不是空
    cout << q.empty() << endl; // 0
    
    return 0;
}
```

#### 2、底层原理

后续。
