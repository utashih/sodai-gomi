

#include "treap.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <random>

using hashtag::Treap;

GTEST_TEST(TreapTest, BasicTest) {
  Treap treap;

  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<uint64_t> dis;

  uint64_t const N = 100000;

  for (uint64_t i = 0; i < N; ++i) {
    bool ok = treap.Insert(i, dis(gen));
    ASSERT_TRUE(ok);
  }

  static uint64_t buffer[1000010];
  uint64_t cnt = 0;
  treap.TraverseKey(buffer, cnt);

  ASSERT_EQ(cnt, N);
  for (uint64_t i = 0; i < N; ++i) {
    ASSERT_EQ(buffer[i], i);
  }

  cnt = 0;
  auto in = [&](hashtag::treap_node *p) {
    cnt++;
    if (p->left) {
      ASSERT_GE(p->priority, p->left->priority);
    }
    if (p->right) {
      ASSERT_GE(p->priority, p->right->priority);
    }
  };
  auto pass = [](hashtag::treap_node *p) {};
  treap.Traverse(pass, in, pass);

  ASSERT_EQ(cnt, N);

  std::cout << "Height: " << treap.Height() << std::endl;
}

int main(int argc, char **argv) {
  ::google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
