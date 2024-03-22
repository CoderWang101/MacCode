#include <iostream>  
#include <unordered_map>  
#include <string>  

int main()  
{  
    std::unordered_map<int, std::string> myMap;
    myMap.insert(std::make_pair(5, "张大"));
    myMap.insert(std::make_pair(6, "李五"));
    myMap[2] = "李四";  
    myMap.insert(std::make_pair(3, "陈二"));
    //myMap.insert(std::make_pair(3,"老八"));
  
    // 遍历输出+迭代器的使用
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        std::cout << iter->first << "," << iter->second << std::endl;  
    }

    // 查找元素并输出+迭代器的使用
    auto iterator = myMap.find(2);
    if (iterator != myMap.end()) {
        std::cout << iterator->first << "," << iterator->second << std::endl;  
    }

    // 等待用户输入
    //std::cin.get();
    return 0;  
}