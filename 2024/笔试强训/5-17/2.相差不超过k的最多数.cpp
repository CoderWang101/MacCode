#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 235 + 10;
int nums[N];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums, nums + n);

    int left = 0, right = 0, ret = 1;

    while (right < n)
    {
        while (right < n && nums[right] - nums[left] > k)
            ++left;
        ret = max(ret, right - left + 1);
        ++right;
    }
    cout << ret << endl;

    return 0;
}