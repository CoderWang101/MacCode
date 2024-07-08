// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// int main()
// {
//     std::ifstream inputFile("test.txt");
//     std::vector<std::string> lines;
//     std::string line;

//     // 逐行读取文件内容
//     while (std::getline(inputFile, line))
//     {
//         lines.push_back(line);
//     }

//     inputFile.close();

//     std::vector<std::string> part1(lines.begin(), lines.end());

//     // 保存分割后的内容到两个不同的文件
//     std::ofstream part1File("part1.txt");

//     // 写入 part1.txt
//     for (const auto &l : part1)
//     {
//         part1File << l << std::endl;
//     }
//     part1File.close();

//     return 0;
// }