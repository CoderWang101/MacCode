// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> twoSum(const vector<int> &nums, int target) {
//     for (int i = 0; i < nums.size(); ++i) {
//         for (int j = i + 1; j < nums.size(); ++j) {
//             if (nums[i] + nums[j] == target) { // 检查两个数的和是否等于目标
//                 vector<int> result;  // 创建结果向量
//                 result.push_back(i); // 添加第一个下标
//                 result.push_back(j); // 添加第二个下标
//                 return result;       // 返回结果向量
//             }
//         }
//     }
//     return vector<int>(); // 如果没有找到满足条件的两个数，返回空向量
// }

// int main() {
//     int n=4;
//     cout << "请输入数组的长度: ";
//     cin >> n;                   // 输入数组的大小
//     vector<int> nums(n);       

//     //2,7,11,15
//     cout << "请输入数组元素: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];        // 输入数组元素
//     }

//     int target=9;
//     cout << "请输入目标值: ";
//     cin >> target;            // 输入目标值

//     vector<int> result = twoSum(nums, target); 

//     if (!result.empty())
//         cout << "[" << result[0] << ", " << result[1] << "]" << endl; 
//     else
//         cout << "找不到满足条件的两个数" << endl; 

//     return 0;
// }
