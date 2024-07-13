#pragma once

#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <string_view>

class Dir {
  public:
    int value;
    std::map<std::string, Dir *, std::less<>> child;

    Dir(int value) : value(value), child() {}
    ~Dir() {
        for (auto c : child) delete c.second;
    }

    bool addChild(std::string_view s, int v) {
        if (child.find(s) != child.end()) return false;
        child.emplace(s, new Dir(v));
        return true;
    }
};

class FileSystem {
    Dir root;

  public:
    FileSystem() : root(-1) {}

    Dir *find(std::string_view path) {
        if (path.empty() || path[0] != '/') return nullptr;
        auto *dir = &root;
        auto i = path.begin() + 1;
        for (;;) {
            auto f = std::find(i, path.end(), '/');
            auto ci = dir->child.find(std::string_view(i, f));
            if (ci == dir->child.end()) return nullptr;
            if (f == path.end() || f + 1 == path.end()) return ci->second;
            dir = ci->second;
            i = f + 1;
        }
    }

    bool createPath(std::string path, int value) {
        auto idx = path.rfind('/');
        auto dir =
            idx == 0 ? &root
                     : find(std::string_view(path.begin(), path.begin() + idx));
        if (dir == nullptr) return false;
        return dir->addChild(
            std::string_view(path.begin() + idx + 1, path.end()), value);
    }

    int get(std::string path) {
        auto d = find(path);
        if (d == nullptr) return -1;
        return d->value;
    }
};
