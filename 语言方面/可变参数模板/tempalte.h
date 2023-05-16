#include <iostream>
using namespace std;

// 可变参数模板介绍
void print()
{
  cout <<"empty" <<endl;
}

template<typename T, typename... Args>
void print(const T& t, const Args&... args)
{
  cout <<"t = " << t <<endl;
  cout <<"size = " << sizeof...(args) <<endl;
  print(args...);
}

// 可变模板参数实现printf
void printf_(const char *s)
{
  while(*s)
  {
    if(*s == '%' && *(s++) != '%')
    {
      cout <<"sss" <<endl;
      throw std::runtime_error("invalid format string");
    }
    
    //std::cout <<*
    s++;
  }
}

// printf_("  %d %s %p %f %s", 15, "This is Ace", pi, 3.1415);
template<typename T, typename... Args> // printf("%d %d %f %d\n", 1, 2, 3, 4);
void printf_(const char * p, T value, Args... args)
{
  while(*p)
  {
    if(*p == '%' && *(++p) != '%')
    {
      cout <<value;
      printf_(++p, args...);
      return;
    }
    //std::cout <<*
    p++;
  }
}

