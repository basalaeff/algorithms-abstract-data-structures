// Проверка на простоту
template<typename Key, typename Value>
bool DoubleHashTable<Key, Value>::is_prime(size_t n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (size_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Поиск наибольшего простого числа, строго меньшего n
template<typename Key, typename Value>
size_t DoubleHashTable<Key, Value>::get_previous_prime(size_t n)
{
    while (n > 1 && !is_prime(n)) {
        --n;
    }
    return n > 1 ? n : 2;
}

// Поиск наименьшего простого числа, большего или равного n
template<typename Key, typename Value>
size_t DoubleHashTable<Key, Value>::get_next_prime(size_t n)
{
    while (!is_prime(n)) {
        ++n;
    }
    return n;
}

// Первая хеш-функция
template<typename Key, typename Value>
size_t DoubleHashTable<Key, Value>::h1(const Key& key) const
{
    return std::hash<Key>{}(key) % capacity_;
}

// Вторая хеш-функция
template<typename Key, typename Value>
size_t DoubleHashTable<Key, Value>::h2(const Key& key) const
{
    // Гарантирует, что шаг никогда не равен 0 и взаимно прост с capacity_
    return primeR_ - (std::hash<Key>{}(key) % primeR_);
}

// Перехеширование
template<typename Key, typename Value>
void DoubleHashTable<Key, Value>::rehash()
{
    size_t new_capacity = get_next_prime(capacity_ * 2);
    DoubleHashTable new_table(new_capacity);

    for (const auto& node : table_) {
        if (node.state_ == State::OCCUPIED) {
            new_table.insert(node.key_, node.value_);
        }
    }

    // Безопасный обмен внутренними состояниями
    std::swap(capacity_, new_table.capacity_);
    std::swap(size_, new_table.size_);
    std::swap(primeR_, new_table.primeR_);
    std::swap(table_, new_table.table_);
}