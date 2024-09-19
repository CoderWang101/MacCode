// #include <iostream>
// #include <vector>

// using namespace std;
// int sum=0;
// void printPartitions(int n, int maxPart, vector<int> &currentPartition)
// {
//     // 基本情况
//     if (n == 0)
//     {
//         // 打印当前的分解式
//         for (size_t i = 0; i < currentPartition.size(); ++i)
//         {
//             if (i != 0)
//                 cout << " + ";
//             cout << currentPartition[i];
//         }
//             sum++;
//         cout << endl;
//         return;
//     }
//     if (n < 0)
//         return;

//     // 递归情况
//     for (int i = 1; i <= maxPart; ++i)
//     {
//         currentPartition.push_back(i);
//         printPartitions(n - i, i, currentPartition);
//         currentPartition.pop_back();
//     }
// }

// int main()
// {
    
//     int n = 5;
//     cout<<"请输入n的值:";
//     cin>>n;
//     vector<int> currentPartition;
//     cout << "整数" << n << "分解式:" << endl;
//     printPartitions(n, n, currentPartition);
//     cout<<"一共有"<<sum<<"个分解式"<<endl;

//     return 0;
// }