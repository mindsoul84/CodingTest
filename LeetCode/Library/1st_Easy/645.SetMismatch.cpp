/*
645. 집합 불일치

1부터 n까지의 모든 숫자가 포함된 정수 집합 s가 있습니다. 어떤 오류로 인해 s에 있는 숫자 중 하나가 다른 숫자와 중복되어, 한 숫자는 중복되고 다른 숫자는 누락되었습니다.

오류 발생 후의 데이터 상태를 나타내는 정수 배열 nums가 주어집니다.

중복된 숫자와 누락된 숫자를 찾아 배열 형태로 반환하세요.

예시 1:
입력: nums = [1,2,2,4]
출력: [2,3]

예시 2:
입력: nums = [1,1]
출력: [1,2]

제약 조건:
2 <= nums.length <= 104
1 <= nums[i] <= 104

승인됨 700,104/1.6M  승인율 44.2%
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

    vector<int> findErrorNums(vector<int>& nums) {
        
        int size = nums.size();

        vector<int> count(size+1, 0);

        int duplicated = 0;
        int missing = 0;

        for (int i = 0; i < size; ++i)
        {
            count[nums[i]]++;
        }

        for (auto a : count)
        {
            cout << "a: " << a << endl;
        }

        for (int i = 1; i <= size; ++i)
        {
            if (count[i] == 2)
            {
                duplicated = i;
            }
            else if (count[i] == 0)
            {
                missing = i;
            }
        }
        
        return { duplicated, missing };
    }
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums = {  1, 2, 2, 4 } ;
    
    auto result = sol.findErrorNums(nums);

    dbg(result);

    return 0;
}