// #include <iostream>
// #include <vector>
// using namespace std;

// // 函数：找到多数元素
// int majorityElement(const vector<int> &nums)
// {
//     int candidate = nums[0];
//     int count = 1;

//     // 第一步：找到候选元素
//     for (size_t i = 1; i < nums.size(); ++i)
//     {
//         if (count == 0)
//         {
//             candidate = nums[i];
//             count = 1;
//         }
//         else if (nums[i] == candidate)
//         {
//             ++count;
//         }
//         else
//         {
//             --count;
//         }
//     }

//     // 第二步：返回候选元素
//     return candidate;
// }

// int main()
// {
//     vector<int> nums;
//     int n;

//     cout << "请输入数组的大小: ";
//     cin >> n;

//     cout << "请输入数组元素: ";
//     nums.resize(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> nums[i];
//     }

//     int result = majorityElement(nums);
//     cout << "多数元素是: " << result << endl;

//     return 0;
// }