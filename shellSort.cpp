//
// Created by joey on 2024/6/6.
//

/* 希尔排序是不稳定的排序算法
 *
 *
 */
#include "iostream"
#include "vector"

using namespace std;

void shellInsert(vector<int>& nums, int delta)
{
    for(int i = delta;i < nums.size();i++){
        if(nums[i] < nums[i - delta]){
            int temp = nums[i];
            int j;
            for(j = i - delta;j >= 0 && nums[j] > temp;j -= delta)
                nums[j + delta] = nums[j]; //后移
            nums[j + delta] = temp;
        }
    }
}

void shellSort(vector<int>& nums, const vector<int>& delta)
{
    for(int i = 0;i < delta.size();i++){
        shellInsert(nums, delta[i]);
    }
}

int main()
{
    vector<int> nums{5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    vector<int> delta{15, 7, 5, 1};
    shellSort(nums, delta);
    for(int& i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}
