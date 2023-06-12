#include <iostream>

// noexcept  运算符有两种方式
// noexcept 
// noexcept(expression)

/***
 * 
 * 第一种形式等同于noexcept(true), 表示被修饰的函数不抛出异常。noexcept(false),表示被修饰的函数会抛出异常
 * 
 * 
 * **/

// noexcept 操作符的作用是阻止异常的传播，当使用noexcept修饰的函数内部抛出异常时，会立即调用std::terminate退出进程
// 程序的执行并没有进入main函数中的catch块中，这样就阻止了异常向上层传播 
void block_throw() noexcept
{
    throw 1;
}

int main()
{
    try
    {
        block_throw();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}