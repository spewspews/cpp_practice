#pragma once

#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::string rankTeams(std::vector<std::string> &votes) {
        auto nteams = votes.front().size();
        std::vector<std::vector<int>> votes_table(26,
                                                  std::vector<int>(nteams + 1));
        for (auto i = votes_table.begin(); i < votes_table.end(); ++i)
            i->back() = i - votes_table.begin();
        for (const auto &v : votes) {
            for (auto i = v.begin(); i < v.end(); ++i)
                --votes_table[*i - 'A'][i - v.begin()];
        }
        std::sort(votes_table.begin(), votes_table.end());
        std::string ret;
        for (auto i = votes_table.begin(); i < votes_table.begin() + nteams;
             ++i) {
            ret.push_back(i->back() + 'A');
        }
        return ret;
    }
};
