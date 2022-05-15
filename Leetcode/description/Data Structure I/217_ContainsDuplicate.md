# 217. Contains Duplicate

## 분류
- Category : Data Structures 1
- Difficulty : Easy
- https://leetcode.com/problems/contains-duplicate/

---
## 설명

`nums` 라는 integer array 를 입력받아서 중복되는 값이 하나라도 존재하는 경우 `true` 를 return 하고 그렇지 않은 경우 `false` 를 return

> Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

## 예제
### Example 1:
```
Input: nums = [1,2,3,1]
Output: true
```
### Example 2:
```
Input: nums = [1,2,3,4]
Output: false
```
### Example 3:
```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```
---
## Answer
Answer >> [Link](../../src/Data_Structure_1/217_ContainsDuplicate.cc)

### 1. `unordered_set` 이용
```c++
// Time : O(N), Space : O(N)
bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> s;
    int len = nums.size();

    for (int i = 0; i < len; ++i) {
        auto it = s.find(nums[i]);
        if (it == s.end()) {
            s.insert(nums[i]);
        } else {
            return true;
        }
    }
    return false;
}
```
- `std::unordered_set` 에 원소를 하나씩 넣으면서 중복이 있는지 검사
  - 시간 복잡도 : O(N)
  - 공간 복잡도 : O(N)

### 2. `unordered_set` 의 size 이용
```c++
// Time : O(N), Space : O(N)
bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    return nums.size() != s.size();
}
```

- `std::unordered_set` 에 원소를 모두 넣은 뒤 배열과 크기를 비교. 크기가 다른 경우 중복되는 원소가 있음을 알 수 있음
  - 시간 복잡도 : O(N)
  - 공간 복잡도 : O(N)

### 3. `sort`을 이용
```c++
// Time : O(NlogN) , Space : O(1)
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();

    for (int i = 0; i < len - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}
```
- `sort()` 를 이용해서 배열의 원소를 모두 정렬한 뒤 중복이 있는지 하나하나 탐색
  - 시간 복잡도 : O(NlogN)
  - 공간 복잡도 : O(1)
- Hash set 을 이용하지 않기 때문에 적은 메모리를 사용할 수 있음
- 정렬을 수행해야 하므로 시간 복잡도는 O(NlogN) 으로 증가하게 됨
---
## 의문점
- 그런데 왜 코드를 실행해보면 정렬을 하는게 가장 짧게 나올까...??