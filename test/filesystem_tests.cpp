#include <gtest/gtest.h>

#include <filesystem.h>

class FileSystemTest : public testing::Test {
  protected:
    FileSystem fs;
};

TEST_F(FileSystemTest, EmptyHasNothing) { ASSERT_EQ(fs.get("/a"), -1); }

TEST_F(FileSystemTest, FirstExample) {
    ASSERT_TRUE(fs.createPath("/a", 1));
    ASSERT_EQ(fs.get("/a"), 1);
}

TEST_F(FileSystemTest, Failing) {
    ASSERT_TRUE(fs.createPath("/leet", 1));
    ASSERT_TRUE(fs.createPath("/leet/code", 2));
    ASSERT_EQ(fs.get("/leet/code"), 2);
    ASSERT_FALSE(fs.createPath("/leet/code", 3));
    ASSERT_EQ(fs.get("/leet/code"), 2);
}
