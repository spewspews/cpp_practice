#include <string>

#include <gtest/gtest.h>

#include <lru_cache3.h>

class LRUCacheTests : public testing::Test {
  protected:
    void SetUp() {
        queue = new LRUQueue<std::string>;
        cache = new LRUCache<int, std::string>(3);
    }
    void TearDown() {
        delete queue;
        delete cache;
    }
    LRUQueue<std::string> *queue;
    LRUCache<int, std::string> *cache;
};

TEST_F(LRUCacheTests, FirstExample) {
    queue->push("hi");
    ASSERT_EQ(queue->pop(), "hi");
}

TEST_F(LRUCacheTests, TwoPushTwoPop) {
    queue->push("hi");
    queue->push("there");
    ASSERT_EQ(queue->pop(), "hi");
    ASSERT_EQ(queue->pop(), "there");
}

TEST_F(LRUCacheTests, ToFront) {
    auto n = queue->push("hi");
    queue->push("there");
    queue->toFront(n);
    ASSERT_EQ(queue->pop(), "there");
    ASSERT_EQ(queue->pop(), "hi");
}

TEST_F(LRUCacheTests, NotFound) { ASSERT_FALSE(cache->find(5).has_value()); }

TEST_F(LRUCacheTests, Found) {
    cache->insert(5, "hi there");
    auto s = cache->find(5);
    ASSERT_TRUE(s.has_value());
    ASSERT_EQ(s.value(), "hi there");
}

TEST_F(LRUCacheTests, Ejects) {
    cache->insert(5, "hi there");
    cache->insert(6, "foobar");
    cache->insert(7, "baz");
    cache->insert(8, "hello");
    auto s = cache->find(5);
    ASSERT_FALSE(s.has_value());
    s = cache->find(6);
    ASSERT_TRUE(s.has_value());
    ASSERT_EQ(s.value(), "foobar");
}

TEST_F(LRUCacheTests, ToFrontCache) {
    cache->insert(5, "hi there");
    cache->insert(6, "foobar");
    cache->insert(7, "baz");
    cache->find(5);
    cache->insert(8, "hello");
    auto s = cache->find(5);
    ASSERT_TRUE(s.has_value());
    ASSERT_EQ(s.value(), "hi there");
    s = cache->find(6);
    ASSERT_FALSE(s.has_value());
}
