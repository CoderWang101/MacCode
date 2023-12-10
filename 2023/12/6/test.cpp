#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 定义一个字符串s1
    string s1("12345");
    // 输出s1
    cout<<s1<<endl;
    // 删除s1中的第二个字符
    s1.erase(1);        
    // 输出s1
    cout<<s1<<endl;

    return 0;
}