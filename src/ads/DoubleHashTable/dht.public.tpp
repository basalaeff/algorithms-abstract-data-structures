template <typename Key, typename Value>
void DoubleHashTable<Key, Value>::insert(const Key& key, const Value& value) {
  if (static_cast<double>(size_ + 1) / capacity_ > 0.7) {
    rehash();
  }

  size_t index = h1(key);
  size_t step = h2(key);
  size_t first_deleted_index = capacity_;  // Sentinel value

  for (size_t i = 0; i < capacity_; ++i) {
    size_t current_index = (index + i * step) % capacity_;

    if (table_[current_index].state_ == State::OCCUPIED) {
      if (table_[current_index].key_ == key) {
        table_[current_index].value_ = value;  // Обновление значения
        return;
      }
    } else if (table_[current_index].state_ == State::DELETED) {
      if (first_deleted_index == capacity_) {
        first_deleted_index = current_index;
      }
    } else {  // State::EMPTY
      size_t insert_idx = (first_deleted_index != capacity_)
                              ? first_deleted_index
                              : current_index;
      table_[insert_idx].key_ = key;
      table_[insert_idx].value_ = value;
      table_[insert_idx].state_ = State::OCCUPIED;
      ++size_;
      return;
    }
  }
  throw std::runtime_error(
      "Hash table is full (should be prevented by rehash)");
}

template <typename Key, typename Value>
std::optional<Value> DoubleHashTable<Key, Value>::search(const Key& key) const {
  size_t index = h1(key);
  size_t step = h2(key);

  for (size_t i = 0; i < capacity_; ++i) {
    size_t current_index = (index + i * step) % capacity_;

    if (table_[current_index].state_ == State::EMPTY) {
      return std::nullopt;  // Элемента нет, и дальше его быть не может
    }
    if (table_[current_index].state_ == State::OCCUPIED &&
        table_[current_index].key_ == key) {
      return table_[current_index].value_;
    }
    // Если DELETED, продолжаем поиск по цепочке
  }
  return std::nullopt;
}

template <typename Key, typename Value>
bool DoubleHashTable<Key, Value>::remove(const Key& key) {
  size_t index = h1(key);
  size_t step = h2(key);

  for (size_t i = 0; i < capacity_; ++i) {
    size_t current_index = (index + i * step) % capacity_;

    if (table_[current_index].state_ == State::EMPTY) {
      return false;
    }
    if (table_[current_index].state_ == State::OCCUPIED &&
        table_[current_index].key_ == key) {
      table_[current_index].state_ = State::DELETED;
      --size_;
      return true;
    }
  }
  return false;
}