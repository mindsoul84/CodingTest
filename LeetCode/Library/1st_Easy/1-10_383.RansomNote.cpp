/*
383. 랜섬 노트

두 문자열 ransomNote와 magazine이 주어졌을 때, magazine의 문자를 사용하여 ransomNote를 만들 수 있으면 true를, 그렇지 않으면 false를 반환합니다.

magazine의 각 문자는 ransomNote에서 한 번만 사용할 수 있습니다.

예시 1:
입력: ransomNote = "a", magazine = "b"
출력: false

예시 2:
입력: ransomNote = "aa", magazine = "ab"
출력: false

예시 3:
입력: ransomNote = "aa", magazine = "aab"
출력: true

제약 조건:
1 <= ransomNote.length, magazine.length <= 105
ransomNote와 magazine은 모두 소문자 영문자로 구성됩니다.

허용된 요청 수: 1,900,012/2.9M
허용률: 65.7%
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

    bool canConstruct(string ransomNote, string magazine) {
    
        unordered_map<char, int> char_map;

        for (auto a : magazine)
        {
            char_map[a]++;
        }

        for (auto b : ransomNote)
        {
            if (char_map[b] == 0)
                return false;

            char_map[b]--;
        }
        
        return true;
    }
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    string ransomNote = "aa";

    string magazine = "aab";
    
    auto result = sol.canConstruct(ransomNote, magazine);

    dbg(result);

    return 0;
}