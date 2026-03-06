/*
242. 유효한 아나그램

두 문자열 s와 t가 주어졌을 때, t가 s의 아나그램이면 true를, 그렇지 않으면 false를 반환합니다.

예시 1:
입력: s = "anagram", t = "nagaram"
출력: true

예시 2:
입력: s = "rat", t = "car"
출력: false

제약 조건:
1 <= s.length, t.length <= 5 * 10⁴
s와 t는 모두 소문자 영문자로 구성됩니다.

추가 질문: 입력에 유니코드 문자가 포함된 경우 어떻게 해결하시겠습니까?

승인됨 5,883,327/870만 승인율 67.8%
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
    /*
    bool isAnagram(string s, string t) {

        // check length
        if (s.length() != t.length())
            return false;

        // use sort func
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if (s == t)
            return true;

        return false;
    }
    */

    bool isAnagram(string s, string t) {

        // check length
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> un_map;

        // map 을 만들어서 s는 더하고, t는 빼기
        for (int i = 0; i < s.length(); ++i)
        {
            un_map[s[i]]++;
            un_map[t[i]]--;
        }

        // 맵의 모든 문자 개수 0일 경우 true
        for (auto um : un_map)
        {
            if (um.second != 0)
            {
                return false;
            }
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

    string s = "anagram";
    string t = "nagaram";
    
    auto result = sol.isAnagram(s, t);

    dbg(result);

    return 0;
}