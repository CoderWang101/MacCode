#include <iostream>
using namespace std;
 
int getValue() {
    int value = 10;
    return value; // 返回一个临时拷贝
}

int main() {
    int result = getValue(); // 接收临时拷贝
    result = 20; // 修改接收到的临时拷贝
    // 此时临时拷贝已经无效，对原始的value没有影响

    cout << "value is " << result << endl; // 输出value的原始值
}