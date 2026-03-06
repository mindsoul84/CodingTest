/*
349. 두 배열의 교집합

두 개의 정수 배열 nums1과 nums2가 주어졌을 때, 두 배열의 교집합을 나타내는 배열을 반환합니다. 결과 배열의 각 요소는 고유해야 하며, 순서는 상관없습니다.

예시 1:
입력: nums1 = [1,2,2,1], nums2 = [2,2]
출력: [2]

예시 2:
입력: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
출력: [9,4]
설명: [4,9]도 허용됩니다.

제약 조건:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

합격 1,800,931/2.3M 합격률 77.5%
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
    
    // unordered_set sol (4ms) - use hash set, hash map
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result_set;

        for (int num : nums2)
        {
            if (set1.find(num) != set1.end())
            {
                result_set.insert(num);
            }
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
    
    /*
    // intersection (1ms) - runtime faster
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // 0부터 1000까지의 숫자가 등장했는지 표시할 1001칸짜리 체크리스트를 만듭니다.
        // 처음에는 모두 false(안 나옴)로 채워둡니다.
        bool isExist[1001] = {false};
        vector<int> result;

        // 1. nums1에 있는 숫자들을 체크리스트에 표시합니다.
        for (int i = 0; i < nums1.size(); i++) {
            isExist[nums1[i]] = true; // "이 숫자 나왔음!" 하고 도장을 찍는 것과 같습니다.
        }

        // 2. nums2에 있는 숫자들을 보면서, 체크리스트에 도장이 찍혀있는지 확인합니다.
        for (int i = 0; i < nums2.size(); i++) {
            // 만약 nums2의 숫자가 nums1에서도 나온 적이 있다면 (true라면)
            if (isExist[nums2[i]] == true) {
                result.push_back(nums2[i]); // 정답 바구니에 담습니다.
                
                // ★ 핵심: 중복해서 정답에 들어가는 것을 막기 위해 도장을 지워버립니다.
                isExist[nums2[i]] = false; 
            }
        }

        return result;
    }
    */
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums1 = { 1, 2, 2, 1} ;
    vector<int> nums2 = { 2, 2 };
    
    auto result = sol.intersection(nums1, nums2);

    dbg(result);

    return 0;
}