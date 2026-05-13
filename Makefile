
# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -pthread -I.
1_TARGET = rpn

# Исходные файлы
1_SRCS += $(wildcard src/ads/d.Stack/*.cpp)
1_SRCS += $(wildcard src/tasks/1.rpn/*.cpp)



# Объектные файлы
1_OBJS = $(1_SRCS:.cpp=.o)

# Сборка
all: $(1_TARGET)

$(1_TARGET): $(1_OBJS)
	@echo "🔗 Линковка..."
	$(CXX) $(CXXFLAGS) -o $(1_TARGET) $(1_OBJS)
	@echo "🧹 Очистка объектных файлов..."
	rm -f $(1_OBJS)
	@echo "✅ Сборка завершена! Запустите: ./$(1_TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	@echo "🗑️ Удаление старых файлов..."
	rm -f $(1_TARGET) $(1_OBJS) *.db
	@echo "✅ Очистка завершена!"

# Запуск
run: $(1_TARGET)
	./$(1_TARGET)

.PHONY: all clean run