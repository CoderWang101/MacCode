// #include <iostream>
// #include <vector>
// #include <unordered_set> // 用于集合
// using namespace std;

// //检查数组中是否存在重复元素
// bool hasDuplicate(const vector<int> &nums)
// {
//     unordered_set<int> seen;
//     for (int num : nums)
//     {
//         if (seen.find(num) != seen.end())
//         {
//             return true; 
//         }
//         seen.insert(num);
//     }
//     return false; 
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
//         cin >> nums[i];

//     bool result = hasDuplicate(nums);
//     cout << (result ? "True" : "False") << endl;

//     return 0;
// }