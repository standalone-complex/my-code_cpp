#include <iostream>

/**
 * 1. 当类声明了一个友元时，该友元声明并没有使友元本身可见
 * 2. 一个另外的未声明的类或函数如果第一次出现在友元声明中，则我们认为它是最近的外层命名空间的成员
 */

namespace A {
        class C {
            
            friend void f2();
            friend void f(const C&);
        };
}

int main(void) {
    A::C cobj;
    
    // f函数因为传递了一个类类型对象，所以会查找C类所属的命名空间A
    f(cobj);
    //f2因为没有参数传递所以不行
    //f2();

    return 0;
}