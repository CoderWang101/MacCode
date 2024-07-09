#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define VS vector<string>

using namespace std;

int main()
{
    ifstream inputFile("yian174734001--174735000.txt");

    if (!inputFile)
    {
        cerr << "无法打开文件" << endl;
        return 1;
    }

    int flag = 0;
    string line_tmp;

    int n = 0;
    // 计算要分割的内容数量
    while (getline(inputFile, line_tmp))
    {
        if (line_tmp == "---------")
            ++n;
    }
    inputFile.clear();  // 清除 EOF 标志
    inputFile.seekg(0); // 将文件指针重置到开头

    vector<VS> lines(n);

    int line = 0;
    // 进行分割并插入
    while (getline(inputFile, line_tmp) && line < n)
    {
        if (line_tmp == "---------")
            ++line;
        else
        {
            if (flag == 0)
            {
                ++flag;
                continue;
            }
            lines[line].push_back(line_tmp);
        }
    }
    inputFile.close();

    // 保存分割后的内容到不同的文件
    for (int i = 0; i < n; ++i)
    {
        string filename = "file" + to_string(i + 1) + ".txt";
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "无法打开文件：" << filename << endl;
            continue; // 如果打开失败，跳过当前文件
        }

        // 将 lines[i] 中的每个字符串写入文件
        for (const auto &word : lines[i])
        {
            outFile << word << endl;
        }

        // 关闭文件
        outFile.close();
    }

    return 0;
}