## 七、std::list

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

插入一个节点长度就加1，删除一个节点长度就减1，也就是说双向链表的长度和容量总是相等的，所以没有容量的概念。

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

传迭代器而非下标，但是双向链表的迭代器不能像动态数组的迭代器那样直接做算数运算，必须用advance(...)函数来算偏移。

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
  
    list<int>::iterator it = l.begin();
    advance(it, 1);
  
    l.insert(it, 4);
    
    return 0;
}
```

* 一次性增多个元素

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
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

传迭代器而非下标，但是双向链表的迭代器不能像动态数组的迭代器那样直接做算数运算，必须用advance(...)函数来算偏移。

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = { 1, 2, 3 };
  
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
#include <list>
using namespace std;

int main() {
    list<int> l = { 6, 1, 2, 3, 6 };
    // 在[begin, end)这个区间内，倒序查元素6的迭代器
    list<int>::reverse_iterator it = find(l.rbegin(), l.rend(), 6);
    if (it != l.rend()) {
        // 找到了该元素
        cout << "找到了该元素" << endl; // 找到了该元素
    } else {
        // 没找到该元素
        cout << "没找到该元素" << endl;
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

###### 1.10 双向链表的迭代器使用注意

* ~~增导致出错~~：list的增不会导致出错，因为list不存在增容问题

* 删导致出错：遍历过程中不要贸然删除元素，会出错。比如我们要删除{ 1, 3, 5, 2, 4, 6 }里所有的奇数，一开始it指向1的位置，会把1删除掉，it就空指针了，我们就不能再继续使用它了如下面的it++，除非重置一下it

  * 错误使用

  ```c++
  #include <iostream>
  #include <list>
  using namespace std;
  
  int main() {
      list<int> l = { 1, 3, 5, 2, 4, 6 };
      
      list<int>::iterator it = l.begin();
      while (it != l.end()) {
          if ((*it & 1) != 0) {
              l.erase(it);
          }
          it++;
      }
      
      for (int i : l) {
          cout << i << endl;
      }
       
      // 崩溃
  
      return 0;
  }
  ```
  
  * 正确使用
  
  ```c++
  #include <iostream>
  #include <list>
  using namespace std;
  
  int main() {
      list<int> l = { 1, 3, 5, 2, 4, 6 };
      
      list<int>::iterator it = l.begin();
      while (it != l.end()) {
          if ((*it & 1) != 0) { // 要删除的情况不自增
              it = l.erase(it); // 其实erase(...)会返回被删除元素后面的元素新位置的迭代器，比如这里删除1后，1后面的元素3就排到了下标为0 的位置，erase(...)会返回3的迭代器，这种情况下我们不让it自增，指向3就可以了
          } else { // 不删除的情况才自增
              it++;
          }
      }
      
      for (int i : l) {
          cout << i << endl;
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

#### 3、vector和list的区别

* 增的效率
  * **头部增：vector不如list，因为vector需要先把所有的元素后移一波，而list有first能直接在第一位创建一个元素**
  * 中间增：差不多，因为vector要移，而list要找
  * 尾部增：差不多，俩人都是一次性找到结束的位置
* 删的效率
  * **头部删：vector不如list，因为vector需要先把所有的元素前移一波，而list有first能直接在第一位删除一个元素**
  * 中间删：差不多，因为vector要移，而list要找
  * 尾部删：差不多，俩人都是一次性找到结束的位置
* 改、查的效率：
  * 头部改、查：差不多，vector可以直接定位，list可以front直接获取
  * 尾部改、查：差不多，vector可以直接定位，list可以back直接获取
  * **中间改查：list不如vector，因为vector可以直接通过index精准定位到元素，而list总是通过next或者prev指针一个元素一个元素地找**
* 其它性能
  * list频繁地删除和增加元素会导致频繁地申请和销毁堆内存，因为每一个节点都是一个对象，但它是用多少申请多少，不浪费内存，而vector虽然不会频繁申请和销毁堆内存，但可能会造成内存浪费

所以总体来讲，动态数组的改查效率更高，双向链表的增删效率更高，它俩是两个互补的数据结构。实际开发中，如果是改查操作比较多则优先选择动态数组，增删操作比较多则优先选择双向链表，两者互为补充。
