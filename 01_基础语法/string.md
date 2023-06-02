## std:string

#### 1、基本使用

###### 1.1 字符串的声明及初始化

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "";
    string str1 = "123";
    cout << str1 << endl; // 123
    
    return 0;
}
```

###### 1.2 获取字符串的长度

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    cout << str.size() << endl; // 3
    
    return 0;
}
```

###### 1.3 获取字符串的容量

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    cout << str.capacity() << endl; // 22
    
    return 0;
}
```

###### 1.4 判断字符串是不是空

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "";
    string str1 = "123";
    cout << str.empty() << endl; // 1
    cout << str1.empty() << endl; // 0
    
    return 0;
}
```

###### 1.5 字符串尾部追加

* +=运算符法（推荐）

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    str += "456";
    cout << str << endl; // 123456
    
    return 0;
}
```

* append函数法

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    str.append("456");
    cout << str << endl; // 123456
    
    return 0;
}
```

###### 1.6 字符串头部或中间插入

在下标为index处（包含）插入字符或字符串。

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    str.insert(0, "0");
    cout << str << endl; // 0123
    str.insert(4, "456");
    cout << str << endl; // 0123456
    
    return 0;
}
```

###### 1.7 字符串删除

从下标为index处（包含）开始删除length个字符。

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    str.erase(1, 2);
    cout << str << endl; // 1
    
    return 0;
}
```

###### 1.8 截取子字符串

从下标为index处（包含）开始截取length个字符作为子字符串。

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    string sub_str = str.substr(1, 2);
    cout << sub_str << endl; // 23
    
    return 0;
}
```

###### 1.9 查找index

从下标为index处（包含，默认为0）开始查找某个字符或子字符串在字符串中第一次出现时的下标。

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    
    // 正序查找
    int index = str.find("1", 1);
    if (index == string::npos) {
        cout << "no position" << endl; // no position
    } else {
        cout << index << endl;
    }
    
    int index1 = str.find("23");
    if (index1 == string::npos) {
        cout << "no position" << endl;
    } else {
        cout << index1 << endl; // 1
    }
    
    return 0;
}
```

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
    
    // 倒序查找
    int index = str.rfind("1");
    if (index == string::npos) {
        cout << "no position" << endl;
    } else {
        cout << index << endl; // 0
    }
    
    int index1 = str.rfind("233");
    if (index1 == string::npos) {
        cout << "no position" << endl;
    } else {
        cout << index1 << endl; // no position
    }
    
    return 0;
}
```

###### 1.10 字符串的遍历

* for循环遍历法（推荐）

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "123";
  
  	// 正序遍历
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
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
#include <string>
using namespace std;

int main() {
    string str = "123";
  
    // 倒序遍历
    for (int i = str.size() - 1; i >= 0; i--) {
        cout << str[i] << endl;
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
#include <string>
using namespace std;

int main() {
    string str = "123";
    
    // 正序遍历
    string::iterator it = str.begin();
    while (it != str.end()) {
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
#include <string>
using namespace std;

int main() {
    string str = "123";
    
    // 倒序遍历
    string::reverse_iterator r_it = str.rbegin();
    while (r_it != str.rend()) {
        cout << *r_it << endl;
        r_it++;
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
#include <string>
using namespace std;

int main() {
    string str = "123";
    
    for (char c : str) {
        cout << c << endl;
    }
    
    // 控制台打印：
    // 1
    // 2
    // 3
    
    return 0;
}
```

#### 2、底层原理
