// // #include <iostream>
// // #include <cwchar>
// // using namespace std;
// // int main()
// // {
// //     const wchar_t *wideStr = L"s";

// //     cout << *wideStr << endl;

// //     return 0;
// // }

// // #include <iostream>
// // #include <cwchar>

// // int main() {
// //     const wchar_t* wideStr = L"哈哈哈哈"; // 使用 L 前缀定义宽字符字符串常量

// //     // 输出宽字符字符串
// //     std::wcout << L"宽字符字符串为：" << wideStr << std::endl;

// //     // 获取宽字符字符串长度
// //     std::size_t wideStrLen = std::wcslen(wideStr);
// //     std::wcout << L"宽字符字符串长度为：" << wideStrLen << std::endl;

// //     return 0;
// // }

// #include <iostream>

// int main() {
//     wchar_t wideChar = L'宽'; // 使用 L 前缀定义宽字符常量

//     // 输出宽字符
//     std::wcout << L"宽字符为：" << wideChar << std::endl;

//     // 输入宽字符
//     wchar_t inputWideChar;
//     std::wcout << L"请输入一个宽字符：";
//     std::wcin >> inputWideChar;
//     std::wcout << L"你输入的宽字符是：" << inputWideChar << std::endl;

//     return 0;
// }