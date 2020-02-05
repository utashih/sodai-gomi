#include "treap.h"

#include <algorithm>

using namespace treap;

bool Treap::insert(treap_node *&p, uint64_t key, uint64_t priority) {
  if (p == nullptr) {
    p = new treap_node{key, priority, nullptr, nullptr};
    return true;
  } else {
    if (p->key == key) {
      return false;
    } else if (p->key > key) {
      bool ok = insert(p->left, key, priority);
      if (!ok) return false;
      if (p->left->priority > p->priority) {
        left_rotate(p);
      }
    } else {
      bool ok = insert(p->right, key, priority);
      if (!ok) return false;
      if (p->right->priority > p->priority) {
        right_rotate(p);
      }
    }
    return true;
  }
}

uint64_t Treap::height(treap_node *const p) const {
  if (!p) return 0;
  return 1 + std::max(height(p->left), height(p->right));
}