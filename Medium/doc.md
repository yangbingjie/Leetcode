# 2_addTwoNumbers

List structure

```c++
// List node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Build list
ListNode* buildTree(vector<int>vec){
    ListNode* list = NULL;
    for (int i = int(vec.size()) - 1; i >= 0; i--) {
        ListNode* tmp = new ListNode(vec[i]);
        tmp->next = list;
        list = tmp;
    }
    return list;
}
```



## 11_maxArea

[剪枝正确性证明](https://leetcode-cn.com/problems/container-with-most-water/solution/zhi-guan-de-shuang-zhi-zhen-fa-jie-shi-by-na-kong/)

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int temp_area = 0;
        int start = 0;
        int end = int(height.size() - 1);
        
        while (start < end) {
            temp_area = (end - start) * min(height[start], height[end]);
            if (temp_area > max_area) {
                max_area = temp_area;
            }
            if (height[start] < height[end]) {
                start++;
            }else{
                end--;
            }
        }
        
        return max_area;
    }
};
```



## 34_searchRange



排序算法归纳

| 排序算法 | 平均时间复杂度 | 最佳情况        | 最坏情况        | 空间复杂度    | 排序方式  | 稳定性 |
| -------- | -------------- | --------------- | --------------- | ------------- | --------- | ------ |
| 冒泡     | $o(n^2)$       | $O(n)$          | $o(n^2)$        | $O(1)$        | In-place  | 稳定   |
| 选择     | $o(n^2)$       | $o(n^2)$        | $o(n^2)$        | $O(1)$        | In-place  | 不稳定 |
| 插入     | $o(n^2)$       | $O(n)$          | $o(n^2)$        | $O(1)$        | In-place  | 稳定   |
| 希尔     | $O(n\log{n})$  | $O(n\log^2{n})$ | $O(n\log^2{n})$ | $O(1)$        | In-place  | 不稳定 |
| 归并     | $O(n\log{n})$  | $O(n\log{n})$   | $O(n\log{n})$   | $O(n)$        | Out-place | 稳定   |
| 快速     | $O(n\log{n})$  | $O(n\log{n})$   | $o(n^2)$        | $O(n\log{n})$ | In-place  | 不稳定 |
| 堆       | $O(n\log{n})$  | $O(n\log{n})$   | $O(n\log{n})$   | $O(1)$        | In-place  | 不稳定 |



## 62_uniquePaths

```c++
// m*n的二维vector
vector<vector<int>> nums(m, vector<int>(n));
```



## 73_setZeroes

NaN ：阶码的每个二进制位全为1  并且  尾数不为0；

无穷：阶码的每个二进制位全为1  并且  尾数为0；符号位为0，是正无穷，符号位为1是负无穷。

```c++
//float
int __NaN=0xFFC00000,__Infinity=0x7F800000,__Neg_Infinity=0xFF800000;
const float NaN=*((float *)&__NaN),Infinity=*((float *)&__Infinity),Neg_Infinity=*((float *)&__Neg_Infinity); 


//double
__int64 __NaN=0xFFF8000000000000,__Infinity=0x7FF0000000000000,__Neg_Infinity=0xFFF0000000000000;
const double NaN=*((double *)&__NaN),Infinity=*((double *)&__Infinity),Neg_Infinity=*((double *)&__Neg_Infinity); 
```



## 89_grayCode

bitset的使用

```c++
#include <bitset>
// 初始化中size的设置必须是常量
const int size = sizeof(int);
bitset<size> bitvec0;
// 常量初始化
bitset<16> bitvec1(0xffff);
// string初始化
string str("1111111000000011001101");
bitset<32> bitvec2(str);
bitset<32> bitvec3(str, 5, 4); // 4 bits starting at str[5], 1100
bitset<32> bitvec4(str, str.size() - 4);     // use last 4 characters

// 每一位被存储为false或true，
bitvec0[0] = bitvec0[0] == false ? true : false;
cout<< bitvec0<<endl;
// bitset可以转换为ulong,ullong,string
result.push_back(int(bitvec0.to_ulong()));
```

| Function     | Info                                       |
| ------------ | ------------------------------------------ |
| b.any()      | b中是否存在置为1的二进制位？               |
| b.none()     | b中不存在置为1的二进制位吗？               |
| b.count()    | b中置为1的二进制位的个数                   |
| b.size()     | b中二进制位的个数                          |
| b[pos]       | 访问b中在pos处的二进制位                   |
| b.test(pos)  | b中在pos处的二进制位是否为1？              |
| b.set()      | 把b中所有二进制位都置为1                   |
| b.set(pos)   | 把b中在pos处的二进制位置为1                |
| b.reset()    | 把b中所有二进制位都置为0                   |
| b.reset(pos) | 把b中在pos处的二进制位置为0                |
| b.flip()     | 把b中所有二进制位逐位取反                  |
| b.flip(pos)  | 把b中在pos处的二进制位取反                 |
| b.to_ulong() | 用b中同样的二进制位返回一个unsigned long值 |
| os << b      | 把b中的位集输出到os流                      |



## Reference

[STL bitset用法总结](http://www.cppblog.com/ylfeng/archive/2010/03/26/110592.aspx)

