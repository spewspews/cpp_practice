#pragma once

#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (auto i = strs.begin(); i < strs.end(); ++i) {
            auto s = *i;
            std::sort(s.begin(), s.end());
            map[s].push_back(*i);
        }
        std::vector<std::vector<std::string>> anagrams;
        for (auto &v : map) anagrams.emplace_back(std::move(v.second));
        return anagrams;
    }
};
