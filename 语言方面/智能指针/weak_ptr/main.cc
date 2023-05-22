#include <iostream>
#include <memory>
using namespace std;

int main()
{
    //weak_ptr 不控制对象的生命周期，指向shared_ptr指向的对象
    // 但不会改变shared_ptr的引用计数

    // weak_ptr的操作
    weak_ptr<int> p1; // 空的指针

    shared_ptr<int> p2(new int(2)); 
    cout <<"ptr.use_count() = " << p2.use_count() <<endl;
    weak_ptr<int> p3(p2) ;

    // p1 = p;  //  p可以是shared_pre 或者weak_ptr
    // p1.reset(); // 将p1设置为空
    // p1.use_count(); // 返回引用计数
    // p1.expired(); // 若use_count 为0,返回true，否则返回false
    // p1.lock();   // 如果expired 为true， 返回一个空的shared_ptr,否则返回一个指向对象的shared_ptr

    shared_ptr<int> p4(new int(3));
    weak_ptr<int> p5(p4);
    cout <<"p4.use_count() = " << p4.use_count() <<endl;

    auto p6 = p5.lock();
    if(p6)
    {
        cout <<"p4.use_count() = " << p4.use_count() <<endl;
    }

 
    return 0;
}
