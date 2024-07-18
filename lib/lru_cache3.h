#pragma once

#include <ankerl/unordered_dense.h>
#include <cstdint>
#include <optional>
#include <stdexcept>

template <class K>
class LRUNode {
  public:
    LRUNode() : next(nullptr), prev(nullptr) {}
    LRUNode(K val) : next(nullptr), prev(nullptr), val(val) {}
    LRUNode<K> *next, *prev;
    K val;
};

template <class K>
class LRUQueue {
  public:
    using size_type = std::size_t;

    LRUQueue() : front(&end) {};

    ~LRUQueue() {
        LRUNode<K> *next;
        for (auto i = front; i != &end; i = next) {
            next = i->next;
            delete i;
        }
    }

    void push(LRUNode<K> *node) {
        front->prev = node;
        node->next = front;
        front = node;
    }

    LRUNode<K> *push(K key) {
        auto node = new LRUNode<K>(key);
        push(node);
        return node;
    }

    K pop() {
        if (end.prev == nullptr) throw std::runtime_error("Queue is empty");
        auto d = end.prev;
        auto r = d->val;
        if (d == front) {
            front = &end;
        } else {
            d->prev->next = &end;
        }
        end.prev = d->prev;
        delete d;
        return r;
    }

    void toFront(LRUNode<K> *n) {
        if (n == front) return;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        n->prev = nullptr;
        push(n);
    }

  private:
    LRUNode<K> end;
    LRUNode<K> *front;
};

template <class K, class V>
class LRUCache {
  public:
    using map = ankerl::unordered_dense::map<K, std::pair<V, LRUNode<K> *>>;
    using size_type = map::size_type;

    LRUCache(size_type cap) : cap(cap) {}

    void insert(K key, V val) {
        auto [i, inserted] = cache.emplace(key, std::pair(val, nullptr));
        if (!inserted) {
            auto &[v, n] = i->second;
            queue.toFront(n);
            v = val;
            return;
        }
        i->second.second = queue.push(key);
        if (cache.size() > cap) {
            auto k = queue.pop();
            cache.erase(k);
        }
    }

    std::optional<V> find(K key) {
        auto i = cache.find(key);
        if (i == cache.end()) return {};
        const auto &[v, n] = i->second;
        queue.toFront(n);
        return v;
    }

  private:
    size_type cap;
    map cache;
    LRUQueue<K> queue;
};
