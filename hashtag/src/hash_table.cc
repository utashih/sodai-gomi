#include "hash_table.h"

namespace hashtag {

Status HashTable::Put(const Key &key, const Value &value) {
  std::lock_guard<std::mutex> guard(latch);
  base_table_.insert_or_assign(key, value);
  return kOk;
}

Status HashTable::Get(const Key &key, Value *value) {
  std::lock_guard<std::mutex> guard(latch);
  auto iter = base_table_.find(key);
  if (iter == base_table_.end()) {
    return kErrorKeyNotFound;
  }
  *value = iter->second;
  return kOk;
}

Status HashTable::Delete(const Key &key) {
  std::lock_guard<std::mutex> guard(latch);
  int cnt = base_table_.erase(key);
  if (cnt == 0) {
    return kErrorKeyNotFound;
  }
  return kOk;
}

}  // namespace hashtag