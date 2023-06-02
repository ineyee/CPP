## std::list

#### 1、基本使用

###### 1.1 双向链表的声明及初始化

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {};
    list<int> l1 = { 1, 2, 3 };
    
    return 0;
}
```

###### 1.2 获取双向链表的长度

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    cout << l.size() << endl; // 3
    
    return 0;
}
```

###### ~~1.3 获取双向链表的容量~~

插入一个节点长度就加1，删除一个节点长度就减1，也就是说双向链表的长度和容量总是相等的，所以去掉了容量的概念。

###### 1.4 判断双向链表是不是空

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {};
    list<int> l1 = { 1, 2, 3 };
    cout << l.empty() << endl; // 1
    cout << l1.empty() << endl; // 0
    
    return 0;
}
```

###### 1.5 双向链表增

* 尾部增

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    l.push_back(4);
    
    return 0;
}
```

* 头部增

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    l.push_front(4);
    
    return 0;
}
```

* 中间增

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    // 传迭代器而非下标，但是双向链表不能直接像动态数组那样迭代器做算数运算，必须像下面这样偏移
    list<int>::iterator it = l.begin();
    advance(it, 1);
    l.insert(it, 4);
    
    return 0;
}
```

* 任意位置一次性增多个元素

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    // 传迭代器而非下标
    l.insert(l.end(), { 4, 5, 6 });
    
    return 0;
}
```

###### 1.6 双向链表删

* 尾部删

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    l.pop_back();
    
    return 0;
}
```

* 头部删

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    l.pop_front();

    return 0;
}
```

* 中间删

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    // 传迭代器而非下标，但是双向链表不能直接像动态数组那样迭代器做算数运算，必须像下面这样偏移
    list<int>::iterator it = l.begin();
    advance(it, 1);
    l.erase(it);
    
    return 0;
}
```

* 清空

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    l.clear();
    
    return 0;
}
```

###### 1.7 双向链表改

双向链表没有重载[]运算符，所以我们没法像动态数组那样通过下标来修改某个位置的值，只能通过迭代器来进行修改。

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };

    // 使用迭代器定位到要修改的位置
    auto it = l.begin();
    advance(it, 0);

    // 使用迭代器修改第一个节点的值
    *it = 4;

    return 0;
}
```

###### 1.8 双向链表查

* 尾部查

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    cout << l.back() << endl; // 3
    
    return 0;
}
```

* 头部查

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    cout << l.front() << endl; // 1
    
    return 0;
}
```

* 中间查

只能通过迭代器来进行查找。

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };

    // 使用迭代器定位到要查找的位置
    auto it = l.begin();
    advance(it, 0);

    // 使用迭代器获取第一个节点的值
    int value = *it;

    return 0;
}
```

* 查某个元素的迭代器

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 6, 1, 2, 3, 6 };
    // 在[begin, end)这个区间内，正序查元素6的迭代器
    list<int>::iterator it = find(l.begin(), l.end(), 6);
    if (it != l.end()) {
        // 找到了该元素
        cout << "找到了" << endl; // 找到了
    } else {
        // 没找到该元素
        cout << "没找到" << endl;
    }

    return 0;
}
```

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 6, 1, 2, 3, 6 };
    // 在[begin, end)这个区间内，倒序查元素6的迭代器
    list<int>::reverse_iterator it = find(l.rbegin(), l.rend(), 6);
    if (it != l.rend()) {
        // 找到了该元素
        cout << "找到了" << endl; // 找到了
    } else {
        // 没找到该元素
        cout << "没找到" << endl;
    }

    return 0;
}
```

###### 1.9 双向链表的遍历

* 迭代器遍历法

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    
    // 正序遍历
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
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
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    
    // 倒序遍历
    list<int>::reverse_iterator it = l.rbegin();
    while (it != l.rend()) {
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

* 便捷for循环遍历法（推荐）

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
    
    for (int i : l) {
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
