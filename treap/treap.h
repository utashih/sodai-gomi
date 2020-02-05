#ifndef HASHTAG_TREAP_
#define HASHTAG_TREAP_

#include <cstdint>
#include <cstdlib>

namespace hashtag {

struct treap_node {
  uint64_t key;
  uint64_t priority;
  treap_node *left;
  treap_node *right;
};

class Treap {
 public:
  inline bool Insert(uint64_t key, uint64_t priority) {
    return insert(root, key, priority);
  }

  template <typename Pre, typename In, typename Post>
  void Traverse(Pre &pre, In &in, Post &post) {
    traverse(root, pre, in, post); 
  }

  inline void TraverseKey(uint64_t *const buf, uint64_t &cnt) {
    auto in = [&](treap_node *p) {
      buf[cnt++] = p->key;
    };
    auto pass = [](treap_node *p) {};
    traverse(root, pass, in, pass);
  }

  uint64_t Height() const { return height(root); }

 private:
  bool insert(treap_node *&p, uint64_t key, uint64_t priority);

  inline void left_rotate(treap_node *&p) {
    treap_node *l = p->left;
    p->left = l->right;
    l->right = p;
    p = l;
  }

  inline void right_rotate(treap_node *&p) {
    treap_node *r = p->right;
    p->right = r->left;
    r->left = p;
    p = r;
  }

  template <typename Pre, typename In, typename Post>
  void traverse(treap_node *p, Pre &pre, In &in, Post &post) {
    if (!p) return; 
    pre(p); 
    traverse(p->left, pre, in, post); 
    in(p);
    traverse(p->right, pre, in, post); 
    post(p);
  }

  uint64_t height(treap_node *const p) const;

  treap_node *root;
};

}  // namespace hashtag

#endif