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

