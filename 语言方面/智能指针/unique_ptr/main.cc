#include <iostream>
#include<memory>

using namespace std;

int main()
{
    // unique_ptr 拥有它所指向的对象，某一时刻稚只能有一个unique_ptr指向一个指定对象
    // 当unique_ptr被销毁时，所指向的对象也被销毁
    // 创建一个unique_ptr时，需要将其保定在一个new返回的指针上
     unique_ptr<int> p1; 
     unique_ptr<int> p2(new int(32));

     // unique_ptr  不支持普通的拷贝和赋值
     // unique_ptr<int> p3(p2) // 错误，不支持拷贝

    //  unique_ptr<int> p4;
    //  p4 = p3;          //  不支持赋值

    // unique_ptr 的操作
    // unique_ptr<int> u; // 空unique_ptr
    // auto q = new int(22);
    // u = nullptr;       // 释放u指向的对象，将u置为空
    // u.release();       // 放弃对指针的控制权，返回指针，并将u置为空
    // u.reset();         // 释放u指向的对象
    // u.reset(q);        // 如果提供了内置指针q，令u指向这个对象，否则将u置为空

    unique_ptr<int> p3(new int(22));
    unique_ptr<int> p4(p3.release()); // 将控制权从p3 转移给p4,将p3置为空

    


}