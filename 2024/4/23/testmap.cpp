#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string arr[] = {"苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜"};

    std::map<std::string, int> countMap;

    for (auto &str : arr)
    {
        auto ret = countMap.find(str);
        if (ret == countMap.end())
        {
            // 第一次出现，插入
            countMap.insert(std::make_pair(str, 1));
        }
        else
        {
            // 已存在，次数++
            ret->second++;
        }
        countMap[str]++;
    }

    for (auto &kv : countMap)
    {
        std::cout << kv.first << ":" << kv.second << std::endl;
    }

    return 0;
}