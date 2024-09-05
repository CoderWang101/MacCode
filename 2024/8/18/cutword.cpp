#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // 定义存储词组映射关系的 map
    map<string, string> translations;
    ifstream inputFile("1.txt");

    // 检查文件是否成功打开
    if (!inputFile)
    {
        cerr << "无法打开文件 1.txt" << endl;
        return 1;
    }

    int startLine = 5; // 起始行（包括）
    int endLine = 10;  // 结束行（包括）
    int currentLine = 0;

    string line;
    while (getline(inputFile, line))
    {
        ++currentLine;

        // 如果当前行在指定范围内
        if (currentLine >= startLine && currentLine <= endLine)
        {
            // 查找第一个空白字符的位置
            size_t delimiterPos = line.find_first_of(" \t");
            if (delimiterPos != string::npos)
            {
                // 提取英文短语和中文翻译
                string english = line.substr(0, delimiterPos);
                string chinese = line.substr(delimiterPos + 1);
                // 去除英文和中文短语的前后空白字符
                english.erase(english.find_last_not_of(" \n\r\t") + 1);
                chinese.erase(0, chinese.find_first_not_of(" \n\r\t"));
                translations[chinese] = english; // 交换键值对
            }
        }
        // 如果当前行超过结束行，停止读取
        if (currentLine > endLine)
        {
            break;
        }
    }
    inputFile.close();

    // 遍历词组进行检测
    for (const auto &pair : translations)
    {
        string chinese = pair.first;
        string correctEnglish = pair.second;
        string userInput;

        while (true)
        {
            // 输出中文翻译
            cout << "输出：" << chinese << endl;

            // 获取用户输入
            cout << "请输入英文短语：";
            getline(cin, userInput);

            // 检查用户输入是否正确
            if (userInput == correctEnglish)
            {
                cout << "输入正确！" << endl;
                break; // 输入正确，跳出循环，处理下一个短语
            }
            else
            {
                cout << "输入错误，请重新输入。" << endl;
            }
        }
    }

    cout << "所有词组输入完毕。" << endl;

    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// #define VS vector<string>

// using namespace std;

// int main()
// {
//     ifstream inputFile("1.txt");

//     if (!inputFile)
//     {
//         cerr << "无法打开文件" << endl;
//         return 1;
//     }

//     vector<string> lines;
//     string line;

//     // 将文件的每一行读取到 vector 中
//     while (getline(inputFile, line))
//     {
//         lines.push_back(line);
//     }
//     inputFile.close();

//     cout << "请输入范围" << endl;
//     int n=3, m=100;
//     //cin >> n >> m;
//     if (n >= 533 || m >= 533)
//     {
//         cout << "Overrun" << endl;
//         return 0;
//     }

//     // 指定要开始和结束的行号（从 0 开始）
//     size_t startLine = n; // 从第 n 行开始（0 基础索引）
//     size_t endLine = m;   // 到第 m 行结束

//     // 确保行号在有效范围内
//     if (startLine >= lines.size())
//     {
//         cerr << "起始行号超出范围" << endl;
//         return 1;
//     }
//     if (endLine >= lines.size())
//     {
//         endLine = lines.size() - 1; // 将结束行号调整为文件的最后一行
//     }

//     int flag=0;
//     while (flag<=m-n+1)
//     {
//         int tmp=0;
//         if(lines[n][tmp]!=' ')
//             ++tmp;
//         cout<<lines[n][tmp]<<endl;
//         string words=;

//     }

//     // 从指定行开始读取到指定行结束
//     for (size_t i = startLine; i <= endLine; ++i)
//     {
//         cout << lines[i] << endl;
//     }

//     return 0;
// }