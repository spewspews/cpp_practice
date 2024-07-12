#pragma once

#include <map>
#include <utility>

class LRUCache {
    class LRUNode;
    using LRUMap = std::map<int, std::pair<int, LRUNode *>>;

    class LRUNode {
      public:
        LRUNode *prev;
        LRUNode *next;
        LRUMap::iterator val;

        LRUNode() : prev(nullptr), next(nullptr) {}
    };

    class LRUQueue {
      public:
        LRUNode *front;
        LRUNode *back;
        LRUNode *avail;

        LRUQueue() : front(nullptr), back(nullptr), avail(nullptr) {}
        ~LRUQueue() {
            LRUNode *next;
            for (auto n = front; n != nullptr; n = next) {
                next = n->next;
                delete n;
            }
            for (auto n = avail; n != nullptr; n = next) {
                next = n->next;
                delete n;
            }
        }

        void push(LRUNode *n) {
            if (front == nullptr) {
                front = back = n;
                return;
            }
            n->next = front;
            front->prev = n;
            front = n;
        }

        LRUNode *push() {
            LRUNode *n;
            if (avail == nullptr) n = new LRUNode();
            else {
                n = avail;
                avail = avail->next;
                n->next = nullptr;
            }
            push(n);
            return n;
        }

        LRUMap::iterator pop() {
            auto n = back;
            auto val = n->val;
            if (front == back) {
                front = back = nullptr;
            } else {
                back = back->prev;
                back->next = nullptr;
            }
            n->prev = nullptr;
            n->next = avail;
            avail = n;
            return val;
        }

        void updateNode(LRUNode *n) {
            if (n == front) return;
            if (n == back) back = n->prev;
            if (n->prev != nullptr) n->prev->next = n->next;
            if (n->next != nullptr) n->next->prev = n->prev;
            n->prev = nullptr;
            push(n);
        }
    };

    LRUMap::size_type cap;
    LRUQueue lru_queue;
    LRUMap lru_map;

  public:
    LRUCache(int cap) : cap(cap), lru_queue(), lru_map() {}
    int get(int key) {
        auto i = lru_map.find(key);
        if (i == lru_map.end()) return -1;
        auto [val, n] = i->second;
        lru_queue.updateNode(n);
        return val;
    }

    void put(int key, int value) {
        auto [i, inserted] = lru_map.emplace(key, std::pair(value, nullptr));
        if (lru_map.size() > cap) {
            auto i = lru_queue.pop();
            lru_map.erase(i);
        }
        auto &[v, n] = i->second;
        if (inserted) {
            n = lru_queue.push();
            n->val = i;
        } else {
            v = value;
            lru_queue.updateNode(n);
        }
    }
};
