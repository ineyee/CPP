## 十、std::unordered_map

unordered_map最大的两个特点就是：

* 无序，因此不可以通过下标访问key-value
* key不可以重复

#### 1、基本使用

```c++
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> um = {};
    um["Jack"] = 20;
    um["Rose"] = 18;
    
    unordered_map<string, int>::iterator it = um.begin();
    while (it != um.end()) {
        cout << it->first << " " << it->second <<endl;
        it++;
    }
    
    // 控制台打印：
    // Rose 18
    // Jack 20
    
    return 0;
}
```

#### 2、底层原理

后续。
