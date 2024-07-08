//
// Created by joey on 2024/6/5.
//

/* 直接插入排序
 * 思想：打牌的时候将新摸到的扑克牌插入到手牌里面
 * 即将一个待排序对象插入到已经排序的一组对象里面
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void insertSort(vector<int>& nums)
{
    vector<int> temp(nums.size() + 1, 0); //temp的第一个位置用来放哨兵，即要排序的值
    copy(nums.begin(), nums.end(), temp.begin() + 1);
    for(int i = 2;i < temp.size();++i)
    {
        if(temp[i] < temp[i - 1]) //判断该值是否需要排序
        {
            temp[0] = temp[i];
            int j;
            for(j = i - 1;temp[j] > temp[0];--j) //哨兵的作用就在这里，如果没有哨兵，判断条件就是temp[j]>temp[i] && j>=0
            {
                temp[j + 1] = temp[j];
            }
            temp[j + 1] = temp[0];
        }
    }
    copy(temp.begin() + 1, temp.end(), nums.begin());
}

int main()
{
    vector<int> nums{5, 4, 3, 2, 1};
    insertSort(nums);
    for(int& i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}
