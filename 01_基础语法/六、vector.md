## 六、std::vector

#### 1、基本使用

###### 1.1 动态数组的声明及初始化

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {};
    vector<int> v1 = { 1, 2, 3 };
    
    return 0;
}
```

###### 1.2 获取动态数组的长度

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    cout << v.size() << endl; // 3
    
    return 0;
}
```

###### 1.3 获取动态数组的容量

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    cout << v.capacity() << endl; // 3
    
    return 0;
}
```

###### 1.4 判断动态数组是不是空

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {};
    vector<int> v1 = { 1, 2, 3 };
    cout << v.empty() << endl; // 1
    cout << v1.empty() << endl; // 0
    
    return 0;
}
```

###### 1.5 动态数组增

* 尾部增

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    v.push_back(4);
    
    return 0;
}
```

* 头部增、中间增

传迭代器、迭代器 + 偏移量而非下标。

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    
    v.insert(v.begin(), 4);
    v.insert(v.begin() + 1, 4);
    
    return 0;
}
```

* 一次性增多个元素

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    v.insert(v.end(), { 4, 5, 6 });

    return 0;
}
```

###### 1.6 动态数组删

* 尾部删

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    v.pop_back();
    
    return 0;
}
```

* 头部删、中间删

传迭代器、迭代器 + 偏移量而非下标。

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    
    v.erase(v.begin());
    v.erase(v.begin() + 1);
    
    return 0;
}
```

* 清空

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    v.clear();

    return 0;
}
```

###### 1.7 动态数组改

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    v[0] = 4;
    
    return 0;
}
```

###### 1.8 动态数组查

* 查某个下标处的元素

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
    cout << v[0] << endl; // 1
    
    return 0;
}
```

* 查某个元素的迭代器（查某个元素的迭代器比查某个元素的下标更有意义，因为vector的很多操作都是基于迭代器而非下标）

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 6, 1, 2, 3, 6 };
    // 在[begin, end)这个区间内，正序查元素6的迭代器
    vector<int>::iterator it = find(v.begin(), v.end(), 6);
    if (it != v.end()) {
        // 找到了该元素
        cout << "找到了该元素" << endl; // 找到了该元素
    } else {
        // 没找到该元素
        cout << "没找到该元素" << endl;
    }

    return 0;
}
```

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 6, 1, 2, 3, 6 };
    // 在[begin, end)这个区间内，倒序查元素6的迭代器
    vector<int>::reverse_iterator it = find(v.rbegin(), v.rend(), 6);
    if (it != v.rend()) {
        // 找到了该元素
        cout << "找到了该元素" << endl; // 找到了该元素
    } else {
        // 没找到该元素
        cout << "没找到该元素" << endl;
    }

    return 0;
}
```

###### 1.9 动态数组的遍历

* for循环遍历法（推荐）

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
  
    // 正序遍历
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    // 控制台打印：
    // 1
    // 2
    // 3
    
    return 0;
}
```

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
  
    // 倒序遍历
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << endl;
    }
    
    // 控制台打印：
    // 3
    // 2
    // 1
    
    return 0;
}
```

* 迭代器遍历法

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
  
    // 正序遍历
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }
    
    // 控制台打印：
    // 1
    // 2
    // 3
    
    return 0;
}
```

```c++

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
  
    // 倒序遍历
    vector<int>::reverse_iterator it = v.rbegin();
    while (it != v.rend()) {
        cout << *it << endl;
        it++;
    }
    
    // 控制台打印：
    // 3
    // 2
    // 1
    
    return 0;
}
```

* 便捷for循环遍历法

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3 };
  
    for (int i : v) {
        cout << i << endl;
    }
    
    // 控制台打印：
    // 1
    // 2
    // 3
    
    return 0;
}
```

###### 1.10 动态数组的迭代器使用注意

* 增导致出错：调用vec.begin()后不要再调用push_back(...)、insert(...)等增加元素可能导致动态数组扩容的API，会出错。因为动态数组扩容后对应内存的首地址很可能跟原来不一样了，此时如果我们继续使用it使用的就是扩容前的某个地址了

  * 错误使用

  ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  
  int main() {
      vector<int> vec = { 1, 2, 3 };
      cout << vec.capacity() << endl; // 3
      
      vector<int>::iterator it = vec.begin();
      
      vec.push_back(4);
      cout << vec.capacity() << endl; // 6
      
      while (it != vec.end()) {
          cout << *it << endl;
          it++;
      }
      
      // 控制台打印垃圾数据，且死循环
  
      return 0;
  }
  ```

  * 正确使用

  ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  
  int main() {
      vector<int> vec = { 1, 2, 3 };
      cout << vec.capacity() << endl; // 3
      vec.push_back(4); // 增加完再调用vec.begin()
      cout << vec.capacity() << endl; // 6
      
      vector<int>::iterator it = vec.begin();
      while (it != vec.end()) {
          cout << *it << endl;
          it++;
      }
       
      // 控制台打印：
      // 1
      // 2
      // 3
      // 4
  
      return 0;
  }
  ```

* 删导致出错：遍历过程中不要贸然删除元素，会出错。比如我们要删除{ 1, 3, 5, 2, 4, 6 }里所有的奇数，一开始it指向1的位置，会把1删除掉，删除掉1就意味着动态数组变成了{ 3, 5, 2, 4, 6 }，it此时指向3的位置，然后执行it++，it就直接指向5了，就漏掉3了，这还只是数据出错，有的编译器会直接崩溃

  * 错误使用

  ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  
  int main() {
      vector<int> vec = { 1, 3, 5, 2, 4, 6 };
      
      vector<int>::iterator it = vec.begin();
      while (it != vec.end()) {
          if ((*it & 1) != 0) {
              vec.erase(it);
          }
          it++;
      }
      
      for (int i = 0; i < vec.size(); i++) {
          cout << vec[i] << endl;
      }
       
      // 控制台打印：
      // 3
      // 2
      // 4
      // 6
  
      return 0;
  }
  ```

  * 正确使用

  ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  
  int main() {
      vector<int> vec = { 1, 3, 5, 2, 4, 6 };
      
      vector<int>::iterator it = vec.begin();
      while (it != vec.end()) {
          if ((*it & 1) != 0) { // 要删除的情况不自增
              it = vec.erase(it); // 其实erase(...)会返回被删除元素后面的元素新位置的迭代器，比如这里删除1后，1后面的元素3就排到了下标为0 的位置，erase(...)会返回3的迭代器，这种情况下我们不让it自增，指向3就可以了
          } else { // 不删除的情况才自增
              it++;
          }
      }
      
      for (int i = 0; i < vec.size(); i++) {
          cout << vec[i] << endl;
      }
       
      // 控制台打印：
      // 2
      // 4
      // 6
  
      return 0;
  }
  ```

#### 2、底层原理

后续。
