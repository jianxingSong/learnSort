/*  注意桶的思想，开发中可以运用
 *  注意桶排序的数据要是均匀分布的，否则效果不好
 *
 */

#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

const int BUCKET_NUM = 5;

void  bubbleSort(vector<int>& nums)
{


}

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

void bucketSort(vector<int>& nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());
    int minNum = *min_element(nums.begin(), nums.end());
    //计算桶的数量---将最大值和最小值之间划分为五个等份即五个桶
    vector<vector<int>> bucket(BUCKET_NUM); //分配五个桶
    //每个桶的区间大小
    float bucketCap = (maxNum - minNum) / BUCKET_NUM + 1;

    //将vector中的元素放入桶中
    for(int i : nums)
    {
        int idx = (i - minNum) / bucketCap;
        bucket[idx].emplace_back(i);
    }

    //对每个桶进行冒泡排序
    int k = 0;
    for(auto& vec : bucket)
    {
        insertSort(vec);
        for(int i : vec)
            nums[k++] = i;
    }
}

int main() {
    vector<int> nums{5, 2, 3, 1, 4, 6, 7, 8, 9, 10};
    for(int& i : nums){
        cout << i << ", ";
    }
    cout << endl;

    bucketSort(nums);

    for(int& i : nums){
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
