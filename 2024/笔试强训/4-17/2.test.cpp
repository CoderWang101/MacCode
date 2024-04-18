// #include "2.单词搜索.h"

// int main() 
// {
//     Solution solution;

//     // 测试用例1：单词存在于字符网格中的情况
//     // vector<string> board1;
//     // board1.push_back("ABCE");
//     // board1.push_back("SFCS");
//     // board1.push_back("ADEE");
//     // string word1 = "ABCCED";
//     // assert(solution.exist(board1, word1) == true);

//     // 测试用例2：单词不存在于字符网格中的情况
//     //["XYZE","SFZS","XDEE"],"XYZZED"
//     vector<string> board2;
//     board2.push_back("XYZE");
//     board2.push_back("SFZS");
//     board2.push_back("XDEE");
//     string word2 = "XYZZED";
//     solution.exist(board2, word2);

//     // 测试用例3：单词超出字符网格大小的情况
//     vector<string> board3;
//     board3.push_back("ABCE");
//     board3.push_back("SFCS");
//     board3.push_back("ADEE");
//     string word3 = "ABCEDEE";
//     assert(solution.exist(board3, word3) == false);

//     // 测试用例4：空字符网格和空单词的情况
//     vector<string> board4;
//     string word4 = "";
//     assert(solution.exist(board4, word4) == false);

//     cout << "所有测试用例通过！" << endl;

//     return 0;
// }