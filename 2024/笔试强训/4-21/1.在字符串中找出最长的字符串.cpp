// #include <iostream>
// #include <string>
// using namespace std;

// string long_string(const string &str)
// {
//     string longString, currentString;
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] >= '0' && str[i] <= '9')
//             currentString.push_back(str[i]);
//         else
//         {
//             if (currentString.size() > longString.size())
//                 longString = currentString;
//             currentString.clear();
//         }
//     }
//     if (currentString.size() > longString.size())
//         longString = currentString;
//     currentString.clear();

//     return longString;
// }

// int main()
// {
//     string str;
//     cin >> str;
//     string sysout = long_string(str);
//     cout << sysout << endl;

//     return 0;
// }
