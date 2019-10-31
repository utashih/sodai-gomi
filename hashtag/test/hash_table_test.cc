

#include "hash_table.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

namespace hashtag {

GTEST_TEST(HashTableTest, FunctionalityTest) {
  HashTable hash_table;

  for (uint64_t i = 0; i < 100; ++i) {
    auto s = hash_table.Put(i, i);
    ASSERT_EQ(s, kOk);
  }

  for (uint64_t i = 0; i < 100; ++i) {
    uint64_t value = -1;
    auto s = hash_table.Get(i, &value);
    ASSERT_EQ(s, kOk);
    ASSERT_EQ(value, i);
  }

  for (uint64_t i = 100; i < 120; ++i) {
    uint64_t value = -1;
    auto s = hash_table.Get(i, &value);
    ASSERT_EQ(s, kErrorKeyNotFound);
    ASSERT_EQ(value, -1);
  }

  for (uint64_t i = 80; i < 100; ++i) {
    auto s = hash_table.Delete(i);
    ASSERT_EQ(s, kOk);
  }

  for (uint64_t i = 100; i < 120; ++i) {
    auto s = hash_table.Delete(i);
    ASSERT_EQ(s, kErrorKeyNotFound);
  }

  for (uint64_t i = 80; i < 100; ++i) {
    uint64_t value = -1;
    auto s = hash_table.Get(i, &value);
    ASSERT_EQ(s, kErrorKeyNotFound);
    ASSERT_EQ(value, -1);
  }
}

}  // namespace hashtag

int main(int argc, char **argv) {
  ::google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
