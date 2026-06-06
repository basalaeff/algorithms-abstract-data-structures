#include <gtest/gtest.h>
#include "../../src/ads/DoubleHashTable/DoubleHashTable.hpp"

// Базовая вставка и поиск
TEST(DoubleHashTableTest, InsertAndSearch) {
    DoubleHashTable<int, std::string> table(11);

    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");

    EXPECT_EQ(table.search(1).value(), "one");
    EXPECT_EQ(table.search(2).value(), "two");
    EXPECT_EQ(table.search(3).value(), "three");
    EXPECT_EQ(table.size(), 3);
}

// Обновление значения существующего ключа
TEST(DoubleHashTableTest, UpdateExistingKey) {
    DoubleHashTable<int, int> table(11);

    table.insert(10, 100);
    EXPECT_EQ(table.search(10).value(), 100);

    table.insert(10, 200); // Обновляем
    EXPECT_EQ(table.search(10).value(), 200);
    EXPECT_EQ(table.size(), 1); // Размер не изменился
}

// Поиск несуществующего элемента
TEST(DoubleHashTableTest, SearchNonExistent) {
    DoubleHashTable<int, int> table(11);

    table.insert(1, 100);

    EXPECT_FALSE(table.search(999).has_value());
    EXPECT_FALSE(table.search(0).has_value());
}

// Коллизии по h1 (проверка работы h2)
// Для capacity=11 и std::hash<int>, ключи 1, 12, 23 дадут h1 = 1
TEST(DoubleHashTableTest, CollisionsResolvedByH2) {
    DoubleHashTable<int, std::string> table(11);

    table.insert(1, "first");
    table.insert(12, "second");
    table.insert(23, "third");

    // Все три элемента должны быть найдены, несмотря на коллизию по h1
    EXPECT_EQ(table.search(1).value(), "first");
    EXPECT_EQ(table.search(12).value(), "second");
    EXPECT_EQ(table.search(23).value(), "third");
    EXPECT_EQ(table.size(), 3);
}

// Удаление и целостность цепочки пробирования (Tombstone)
// если удалить элемент из середины цепочки,
// поиск последующих элементов не должен сломаться.
TEST(DoubleHashTableTest, RemoveAndSearchIntegrity) {
    DoubleHashTable<int, int> table(11);

    // Вставляем элементы с коллизией по h1
    table.insert(1, 100);
    table.insert(12, 200);
    table.insert(23, 300);

    // Удаляем средний элемент (создаем tombstone)
    EXPECT_TRUE(table.remove(12));
    EXPECT_EQ(table.size(), 2);

    // Поиск удаленного элемента должен вернуть nullopt
    EXPECT_FALSE(table.search(12).has_value());

    // Поиск остальных элементов должен успешно перешагнуть через tombstone
    EXPECT_EQ(table.search(1).value(), 100);
    EXPECT_EQ(table.search(23).value(), 300);
}

// Удаление несуществующего элемента
TEST(DoubleHashTableTest, RemoveNonExistent) {
    DoubleHashTable<int, int> table(11);

    table.insert(1, 100);

    EXPECT_FALSE(table.remove(999));
    EXPECT_EQ(table.size(), 1);
}

// Автоматический Rehash
// Для capacity=11, load factor 0.7 означает, что после 8 вставок (8/11)
// должен сработать rehash и capacity увеличится до следующего простого (23)
TEST(DoubleHashTableTest, AutoRehash) {
    DoubleHashTable<int, int> table(11);

    // Вставляем 10 элементов (превышаем порог 0.7)
    for (int i = 1; i <= 10; ++i) {
        table.insert(i, i * 100);
    }

    // После rehash все элементы должны быть найдены
    for (int i = 1; i <= 10; ++i) {
        EXPECT_EQ(table.search(i).value(), i * 100);
    }

    EXPECT_EQ(table.size(), 10);
}

// Пустая таблица
TEST(DoubleHashTableTest, EmptyTable) {
    DoubleHashTable<int, int> table;

    EXPECT_TRUE(table.empty());
    EXPECT_EQ(table.size(), 0);
    EXPECT_FALSE(table.search(1).has_value());
    EXPECT_FALSE(table.remove(1));
}

// Работа со строковыми ключами
TEST(DoubleHashTableTest, StringKeys) {
    DoubleHashTable<std::string, int> table(11);

    table.insert("apple", 1);
    table.insert("banana", 2);
    table.insert("cherry", 3);

    EXPECT_EQ(table.search("apple").value(), 1);
    EXPECT_EQ(table.search("banana").value(), 2);
    EXPECT_EQ(table.search("cherry").value(), 3);

    EXPECT_TRUE(table.remove("banana"));
    EXPECT_FALSE(table.search("banana").has_value());
}