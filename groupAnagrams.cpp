#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> m;

    for (string &s : strs) {
      string sorted = s;
      sort(sorted.begin(), sorted.end());
      m[sorted].push_back(s);
    }

    for (auto &[key, words] : m)
      ans.push_back(words);

    return ans;
  }
};

int main() {}
