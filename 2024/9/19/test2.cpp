// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {

//     int n=4;
//     cin>> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>nums[i];
//     }
    
//     // 使用双指针法
//     int left = 0, right = 0;

//     while (right < n) {
//         if (nums[right] % 2 == 0) { // 如果是偶数
//             swap(nums[left], nums[right]);
//             left++;
//         }
//         right++;
//     }

//     // 输出结果
//     for (int i = 0; i < n; i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }