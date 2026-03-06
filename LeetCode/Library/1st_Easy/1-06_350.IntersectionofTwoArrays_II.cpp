/*
350. 두 배열의 교집합 II

두 개의 정수 배열 nums1과 nums2가 주어졌을 때, 두 배열의 교집합을 나타내는 배열을 반환하세요. 결과 배열의 각 요소는 두 배열 모두에 동일한 횟수만큼 나타나야 하며, 순서는 상관없습니다.

예시 1:
입력: nums1 = [1,2,2,1], nums2 = [2,2]
출력: [2,2]

예시 2:
입력: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
출력: [4,9]
설명: [9,4]도 허용됩니다.

제약 조건:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

추가 질문:

주어진 배열이 이미 정렬되어 있다면 어떻게 알고리즘을 최적화할 수 있을까요?
nums1의 크기가 nums2의 크기에 비해 작다면 어떤 알고리즘이 더 효율적일까요?
nums2의 요소들이 디스크에 저장되어 있고, 메모리 용량이 제한되어 모든 요소를 ​​한 번에 메모리에 로드할 수 없다면 어떻게 해야 할까요?

채택됨
1,709,794/2.9M
채택률
59.7%
*/

// ============================================================
// Competitive Programming Template (MSVC / cl.exe 전용)
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <chrono>
#include <queue>
#include <stack>

using namespace std;

#define dbg(x) debug(x)

// 기본 타입
template<typename T>
void debug(const T& value) {
    cout << value << "\n";
}

// bool
void debug(const bool& value) {
    cout << (value ? "true" : "false") << "\n";
}

// pair
template<typename T, typename U>
void debug(const pair<T,U>& p) {
    cout << "{ " << p.first << ", " << p.second << " }\n";
}

// vector
template<typename T>
void debug(const vector<T>& v) {
    cout << "[ ";
    for (const auto& e : v)
        cout << e << " ";
    cout << "]\n";
}

// set
template<typename T>
void debug(const set<T>& s) {
    cout << "[ ";
    for (const auto& e : s)
        cout << e << " ";
    cout << "]\n";
}

// unordered_map
template<typename K, typename V>
void debug(const unordered_map<K,V>& m) {
    cout << "{ ";
    for (const auto& [k,v] : m)
        cout << k << ":" << v << " ";
    cout << "}\n";
}

// ============================================================
// 🧠 Solution 영역
// ============================================================

class Solution {
public:
    // duplicate number - use hash map
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        
        
        unordered_map<int, int> map1;

        for (int num : nums1)
            map1[num]++;

        vector<int> result;

        for (int num : nums2)
        {
            if (map1[num] > 0)
            {
                result.push_back(num);
                map1[num]--;
            }

        }
        
        return result;
    }
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums1 = { 4, 9, 5 } ;
    vector<int> nums2 = { 9, 4, 9, 8, 4 };
    
    auto result = sol.intersect(nums1, nums2);

    dbg(result);

    return 0;
}