// #include <iostream>
// using namespace std;
// #include <vector>
// int main()
// {
//     int a[] = {1, 2, 3, 4};
//     vector<int> v(a, a + sizeof(a) / sizeof(int));
//     // 使用find查找3所在位置的iterator
//     vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//     // 删除pos位置的数据，导致pos迭代器失效。 v.erase(pos);
//     cout << *pos << endl; // 此处会导致非法访问
//     return 0;
// }
// int main()
// {
//     wzf::vector<wzf::string> v;
//     v.push_back("1111");
//     v.push_back("2222");
//     v.push_back("3333");
//     return 0;
// }