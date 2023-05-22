#include <iostream>
#include <memory>
using namespace std;

shared_ptr<int> factory(int a)
{
    shared_ptr<int> p =  make_shared<int>(a);
    cout <<"count = " << p.use_count() <<endl;
    return p;
}

int main()
{
    /**
     *  shared_ptr
     *  智能指针也是类模板，需要把类型传进来
     *  
     * **/

    //shared_ptr<string> ps; // 默认的智能指针是个空指针
    shared_ptr<string> ps(new string);  // 非空指针
   
    if(ps && ps->empty())
    {
        *ps = "Hello, Smart Pointer" ;
        ps.get(); // 返回p中保存的指针。
    }
    cout <<(*ps) <<endl;

    // share_ptr 独有的操作
    shared_ptr<int> p1 = make_shared<int>(42); // make_shared 为标准库里的函数，
                                               // 在动态内存中创建对象，并返回指向该对象的智能指针

    auto p2 = make_shared<string>();           // 可以使用auto
    if(p2)
        cout <<"pointer to string" <<endl;
    
    p2.unique(); // 若use_count的值为1,返回true,否则返回false
    p2.use_count(); // 返回只能指针的引用计数

    // 测试引用计数
    auto p3 = factory(1);
    cout <<"count = " << p3.use_count() <<endl;

    // shared_ptr和new的结合
    // 如果我们不初始化一个智能指针，那么该指针就会被初始化为一个空指针
    //shared_ptr<int> p4(new int(32)); // 直接初始化法

    //shared_ptr<int> p4 = new int(32); //  错误，必须使用直接初始化法
                                        // 解释: p4的初始化隐式要求编译器用一个new返回的int* 来创建一个shared_ptr.
                                        // 我们不能将内置指针转隐式转换为智能指针。
                                        // 构造函数：explicit shared_ptr( Y* ptr ); 禁止隐式转换

    shared_ptr<int> p5(new int(3));
    if(p5.get())
        cout <<"not nullptr" <<endl;
    
    p5.reset(); // 如果p5是唯一指向该对象的智能指针，那么reset会施放该对象
    // p5.reset(p); //会让p5指向p 

    if(p5.get())
        cout <<"p5 not nullptr" <<endl;
    else
        cout <<"p5 nullptr" <<endl;

    // 使用我们自己的释放动作
    // 当shared_ptr 引用计数为1,被销毁时，shared_ptr默认对管理的指针进行delete操作。
    // 我们可以定一个函数来代替delete,这个函数必须能够释放shared_ptr管理的的指针
    
    return 0;
}
