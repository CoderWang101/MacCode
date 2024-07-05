#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

void may_test1()
{
    map<string, string> dict;
    pair<string, string> kv1("sort", "排序");
    // 四种写法
    dict.insert(kv1);
    dict.insert(pair<string, string>("left", "左边"));
    dict.insert(make_pair("right", "右边"));
    // C++17
    // pair<string,string> kv2={"string","字符串"}; //隐式类型转换
    //  dict.insert({"string","字符串"});

    // map<string,string> dic2 = {{"sort","排序"},{"left","左边"},{"right","右边"}};

    auto it = dict.begin();
    while (it != dict.end())
    {
        cout << (*it).first << ':' << (*it).second << " "; // pair不支持<<
        it->second+="x";//first不能进行更改,second可以
        cout << it->first << ':' << it->second << " ";     // it->first == it.operator()->->first
        //first不能进行更改,second可以
        //it->second+="x";
        ++it;
    }
    cout << endl;
}


// map内用的是pair<>
int main()
{
    may_test1();

    return 0;
}