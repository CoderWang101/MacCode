#include <iostream>
#include <vector>
using namespace std;

//按照颜色进行分类
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    // 进行分类
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums;
    int n;

    cout << "请输入数组的大小: ";
    cin >> n;

    cout << "请输入数组元素 (0 代表红色, 1 代表白色, 2 代表蓝色): ";
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sortColors(nums);

    cout << "排序后的数组: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}