# 1_twoSum

Using multimap

```c++
// Header
#include <map>

// Defination
multimap<int, int>nums_map;

// Insert
// The map is already sorted by key during insert
for (int i = 0; i < nums.size(); ++i) {
		nums_map.insert(pair<int, int>(nums[i], i));
}        

// Iterator
multimap<int, int>::iterator i = nums_map.begin();
multimap<int, int>::iterator j = nums_map.end();
j--;

// first: key
// second: value
int sum = i->first + j->first;
result.push_back(i->second);
```



## 7_reverse

stringstream的用法

```c++
// 头文件
#include <sstream>

// int转string
stringstream s;
string str;
s << x;
s >> str;
string result_str;

// 清空
s.clear();

// string转long
long result_num;
s << result_str;
s >> result_num;
```



## 28_strStr

字符串匹配，主串"BBCMABCDABMABCDABCDABDE"里面是否包含子串"ABCDABD"

### KMP

> **B**BCMABCDABMABCDABCDABDE
>
> **A**BCDABD

首先，主串和子串的第一个字符对齐，不匹配，子串向后移一位

> B**B**CMABCDABMABCDABCDABDE
>
>   **A**BCDABD

依然不匹配，继续移动，直到主串和子串的第一个字符匹配

> BBCM**A**BCDABMABCDABCDABDE
>
> ​           **A**BCDABD

然后比较主串和子串的第二个字符

> BBCMA**B**CDABMABCDABCDABDE
>
> ​           A**B**CDABD

一直到主串和子串不匹配为止

> BBCMABCDAB**M**ABCDABCDABDE
>
> ​           ABCDAB**D**

按照蛮力法，这时候子串应该后移一位，但是效率很差。其实当M与D不匹配时，你其实知道前面六个字符是"ABCDAB"。KMP算法的想法是，设法利用这个已知信息，将子串多后移几个位置，这样就提高了效率。

那么，应该将子串后移几个位置呢？我们可以构造一个**部分匹配表**

#### 部分匹配表

next 数组相当于“最大长度值” 整体向右移动一位，然后初始值赋为-1

| 部分匹配词     | A    | B    | C    | D    | A    | B    | D（必要时） |
| ---------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 部分匹配值 | 0    | 0    | 0    | 0    | 1    | 2    |     |
| next数组 | -1 | 0 | 0 | 0 | 0 | 1 | 2 |

> BBCMABCDAB**M**ABCDABCDABDE
>
> ​           ABCDAB**D**

当M与D不匹配时，子串的上一个匹配的字符B对应的“部分匹配值”是2，移动位数为4：
$$
移动位数=已匹配的字符数-对应的部分匹配值=6-2=4
$$

> BBCMABCDAB**M**ABCDABCDABDE
>
> ​                     AB**C**DABD

M与C不匹配，子串的上一个匹配的字符B对应的“部分匹配值”是0，移动位数是2

> BBCMABCDAB**M**ABCDABCDABDE
>
> ​                          **A**BCDABD

M与A不匹配，后移一位

> BBCMABCDABM**A**BCDABCDABDE
>
> ​                             **A**BCDABD

继续比较，直到

> BBCMABCDABMABCDAB**C**DABDE
>
> ​                             ABCDAB**D**

C与D不匹配，子串的上一个匹配的字符B对应的“部分匹配值”是2，移动位数为4：

> BBCMABCDABMABCDAB**C**DABDE
>
> ​                                       AB**C**DABD

继续比较，直到子串完全匹配，搜索完成。如果还要继续搜索，需要移动7位

#### 前后缀

“部分匹配值"就是"前缀"和"后缀"的最长的共有元素的长度

- "A"的前缀和后缀都为空集，共有元素的长度为0
- "AB"的前缀为[A]，后缀为[B]，共有元素的长度为0
- "ABC"的前缀为[A, AB]，后缀为[BC, C]，共有元素的长度0
- "ABCD"的前缀为[A, AB, ABC]，后缀为[BCD, CD, D]，共有元素的长度为0
- "ABCDA"的前缀为[A, AB, ABC, ABCD]，后缀为[BCDA, CDA, DA, A]，共有元素为"A"，长度为1
- "ABCDAB"的前缀为[A, AB, ABC, ABCD, ABCDA]，后缀为[BCDAB, CDAB, DAB, AB, B]，共有元素为"AB"，长度为2
- "ABCDABD"的前缀为[A, AB, ABC, ABCD, ABCDA, ABCDAB]，后缀为[BCDABD, CDABD, DABD, ABD, BD, D]，共有元素的长度为0

"部分匹配"的实质是，有时候，字符串头部和尾部会有重复。比如，"ABCDAB"之中有两个"AB"，那么它的"部分匹配值"就是2（"AB"的长度）。搜索词移动的时候，第一个"AB"向后移动4位（字符串长度-部分匹配值），就可以来到第二个"AB"的位置。

#### next数组

计算next 数组的方法可以采用递推

https://www.cnblogs.com/yjiyjige/p/3263858.html

```c++
vector<int> buildNextVector(string needle){
        vector<int>next(needle.length());
        next[0] = -1;
        int k = -1;
        int j = 0; // 当前部分子串的索引
        while (j < needle.length() - 1) {
            if (k == -1 || needle[k] == needle[j]) {
                next[++j] = ++k;
            }else{
                k = next[k];
            }
        }
        return next;
    }
```

### Boyer-Moore算法

http://igm.univ-mlv.fr/~lecroq/string/node14.html

##  290_wordPattern

Find something in map by value

```c++
class finder
{
public:
    finder(const string &cmp_string) :s_(cmp_string){}
    bool operator ()(const map<int, string>::value_type &item)
    {
        return item.second == s_;
    }
private:
    const string &s_;
};

map<char, string> m;
string current = "2";
map<char, string>::iterator iter_2;
m['b'] = "2";
iter_2 = find_if(m.begin(), m.end(), finder(current));
```

