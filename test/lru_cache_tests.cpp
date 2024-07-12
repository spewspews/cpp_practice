#include <gtest/gtest.h>

#include <lru_cache.h>

class LRUCacheTest : public testing::Test {
protected:
  LRUCache *cache;
  virtual void SetUp() { cache = new LRUCache(3); }
  virtual void TearDown() { delete cache; }
  void setCache(int cap) {
    delete cache;
    cache = new LRUCache(cap);
  }
};

TEST_F(LRUCacheTest, EmptyGetReturnsNegative) { EXPECT_EQ(cache->get(5), -1); }
TEST_F(LRUCacheTest, PutsGetsValue) {
  cache->put(10, 25);
  EXPECT_EQ(cache->get(10), 25);
}

TEST_F(LRUCacheTest, CapOneEjectsValue) {
  setCache(1);
  cache->put(10, 25);
  cache->put(5, 23);
  EXPECT_EQ(cache->get(10), -1);
  EXPECT_EQ(cache->get(5), 23);
}

TEST_F(LRUCacheTest, CapTwoNoEject) {
  setCache(2);
  cache->put(10, 25);
  cache->put(5, 23);
  EXPECT_EQ(cache->get(10), 25);
  EXPECT_EQ(cache->get(5), 23);
}

TEST_F(LRUCacheTest, CapTwoEjectsValue) {
  setCache(2);
  cache->put(5, 23);
  cache->put(10, 25);
  cache->put(7, 45);
  EXPECT_EQ(cache->get(5), -1);
  EXPECT_EQ(cache->get(10), 25);
  EXPECT_EQ(cache->get(7), 45);
}

TEST_F(LRUCacheTest, CapTwoEjectsUnusedValue) {
  setCache(2);
  cache->put(5, 23);
  cache->put(10, 25);
  cache->get(5);
  cache->put(7, 45);
  EXPECT_EQ(cache->get(10), -1);
  EXPECT_EQ(cache->get(5), 23);
  EXPECT_EQ(cache->get(7), 45);
}

TEST_F(LRUCacheTest, UpdatesValue) {
  setCache(5);
  cache->put(5, 23);
  EXPECT_EQ(cache->get(5), 23);
  cache->put(5, 45);
  EXPECT_EQ(cache->get(5), 45);
}
