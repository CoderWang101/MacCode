// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      *
//      * @param nums1 int整型vector
//      * @param nums2 int整型vector
//      * @return int整型vector
//      */
//     vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> ans;
//         //利用哈希排序,在哈希表中找相同值
//         int hash[128]={0};
//         int hash2[128]={0};

//         for (int num : nums1)
//             hash[num]++;

//         for (int num : nums2)
//             hash2[num]++;
        
//         for (int i = 0; i < nums2.size(); i++)
//         {
//             if (hash[i]!=0&&hash2[i]!=0)
//             {
//                 ans.push_back(i);
//             }
            
//         }
//         return ans;
//     }
// };