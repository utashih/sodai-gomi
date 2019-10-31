#ifndef HASHTAG_HASH_TABLE_
#define HASHTAG_HASH_TABLE_

#include <mutex>
#include <unordered_map>

namespace hashtag {

enum Status { kOk = 0, kErrorKeyNotFound };

class HashTable {
  using Key = uint64_t;
  using Value = uint64_t;

 public:
  Status Put(const Key &key, const Value &value);
  Status Get(const Key &key, Value *value);
  Status Delete(const Key &key);

 private:
  std::unordered_map<Key, Value> base_table_;
  mutable std::mutex latch;
};

}  // namespace hashtag
#endif  // HASHTAG_HASH_TABLE_