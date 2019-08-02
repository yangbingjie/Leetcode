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

