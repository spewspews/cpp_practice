#pragma once

#include <list>
#include <map>

class LRUCache {
    using queue_t = std::list<int>;
    using qiter_t = queue_t::iterator;
    queue_t::size_type cap;
    queue_t queue;
    std::map<int, std::pair<int, qiter_t>> cache;

  public:
    LRUCache(int capacity) : cap(capacity) {}

    int *find(int key) {
        auto f = cache.find(key);
        if (f == cache.end()) return nullptr;
        auto &[val, iter] = f->second;
        queue.erase(iter);
        queue.push_front(key);
        iter = queue.begin();
        return &val;
    }

    int get(int key) {
        auto f = find(key);
        return f == nullptr ? -1 : *f;
    }

    void put(int key, int value) {
        auto f = find(key);
        if (f != nullptr) {
            *f = value;
            return;
        }
        if (queue.size() == cap) {
            auto k = queue.back();
            queue.pop_back();
            cache.erase(k);
        }
        queue.push_front(key);
        auto iter = queue.begin();
        cache.emplace(key, std::pair(value, iter));
    }
};
