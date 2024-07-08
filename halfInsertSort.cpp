//
// Created by joey on 2024/6/6.
//

/* 折半插入排序
 * 思想：打牌的时候将新摸到的扑克牌插入到手牌里面
 * 即将一个待排序对象插入到已经排序的一组对象里面
 * 时间复杂度：查找的复杂度降低了，移动的时间复杂度还是一样的，所以
 * 空间复杂度：
 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void bInsertSort(vector<int>& nums)
{
    vector<int> temp(nums.size() + 1, 0); //temp的第一个位置用来放哨兵，即要排序的值
    copy(nums.begin(), nums.end(), temp.begin() + 1);
    for(int i = 2;i < temp.size();++i)
    {
        if(temp[i] < temp[i - 1]) //判断该值是否需要排序
        {
            temp[0] = temp[i];
            int low = 1, high = i - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(temp[mid] > temp[0])
                    high = mid - 1;
                else{
                    low = mid + 1;
                }
            } //二分搜索完以后，high + 1就是要插入的位置
            //移动high+1后面的元素
            for(int j = i - 1;j >= high + 1;j--)
                temp[j + 1] = temp[j];
            temp[high + 1] = temp[0];
        }
    }
    copy(temp.begin() + 1, temp.end(), nums.begin());
}

int main()
{
    vector<int> nums{5, 4, 3, 2, 1};
    bInsertSort(nums);
    for(int& i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}
