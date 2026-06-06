#pragma once

#include <vector>
#include <functional>
#include <optional>
#include <stdexcept>
#include <algorithm>

template <typename Key, typename Value>
class DoubleHashTable {
private:
    enum class State { EMPTY, OCCUPIED, DELETED };

    struct Node {
        Key key_;
        Value value_;
        State state_;
    };

    size_t capacity_; // размер хеш-таблицы
    size_t size_; // количество элементов
    size_t primeR_; // простое число для второго хеша
    std::vector<Node> table_; // таблица

    // Проверка на простое число
    static bool is_prime(size_t n);

    // Получение предыдущего простого числа
    static size_t get_previous_prime(size_t n);

    // Получение следующего простого числа
    static size_t get_next_prime(size_t n);

    // Первая хеш-функция
    size_t h1(const Key& key) const;

    // Вторая хеш-функция
    size_t h2(const Key& key) const;

    // Перехеширование
    void rehash();

public:
    explicit DoubleHashTable(size_t initial_capacity = 11)
        : capacity_(get_next_prime(initial_capacity)),
          size_(0),
          primeR_(get_previous_prime(capacity_ > 2 ? capacity_ - 1 : 2)),
          table_(capacity_, {Key{}, Value{}, State::EMPTY}) {}

};
#include "dht.private.tpp"
