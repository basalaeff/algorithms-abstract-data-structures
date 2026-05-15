# ============================================================================
# КОМПИЛЯТОР И ФЛАГИ
# ============================================================================

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -pthread -I.

# ============================================================================
# TARGETS
# ============================================================================

RPN_TARGET = rpn
SET_TARGET = set
MIC_TARGET = mic
PYRAMID_TARGET = pyramid

# ============================================================================
# ИСХОДНЫЕ ФАЙЛЫ
# ============================================================================

RPN_SRCS = $(wildcard src/ads/d.Stack/*.cpp)
RPN_SRCS += $(wildcard src/tasks/1.rpn/*.cpp)

SET_SRCS = $(wildcard src/ads/g.Set/*.cpp)
SET_SRCS += $(wildcard src/tasks/2.set/*.cpp)

MIC_SRCS = $(wildcard src/ads/g.Set/*.cpp)
MIC_SRCS += $(wildcard src/tasks/3.mic/*.cpp)

PYRAMID_SRCS = $(wildcard src/ads/a.Array/*.cpp)
PYRAMID_SRCS += $(wildcard src/tasks/4.pyramid/*.cpp)

# ============================================================================
# OBJECT FILES
# ============================================================================

RPN_OBJS = $(RPN_SRCS:.cpp=.o)
SET_OBJS = $(SET_SRCS:.cpp=.o)
MIC_OBJS = $(MIC_SRCS:.cpp=.o)
PYRAMID_OBJS = $(PYRAMID_SRCS:.cpp=.o)

# ============================================================================
# DEFAULT
# ============================================================================

all: rpn set mic pyramid

# ============================================================================
# BUILD RPN
# ============================================================================

rpn: $(RPN_OBJS)
	@echo "🔗 Linking $(RPN_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(RPN_TARGET) $(RPN_OBJS)
	@echo "🧹 Очистка объектных файлов..."
	rm -f $(RPN_OBJS)
	@echo "✅ $(RPN_TARGET) build complete! run: ./$(RPN_TARGET)"

# ============================================================================
# BUILD SET
# ============================================================================

set: $(SET_OBJS)
	@echo "🔗 Linking $(SET_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(SET_TARGET) $(SET_OBJS)
	@echo "🗑️ Removing old files..."
	rm -f $(SET_OBJS)
	@echo "✅ $(SET_TARGET) build complete! run: ./$(SET_TARGET)"

# ============================================================================
# BUILD MIC
# ============================================================================

mic: $(MIC_OBJS)
	@echo "🔗 Linking $(MIC_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(MIC_TARGET) $(MIC_OBJS)
	@echo "🗑️ Removing old files..."
	rm -f $(MIC_OBJS)
	@echo "✅ $(MIC_TARGET) build complete! run: ./$(MIC_TARGET)"

# ============================================================================
# BUILD PYRAMID
# ============================================================================

pyramid: $(PYRAMID_OBJS)
	@echo "🔗 Linking $(PYRAMID_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(PYRAMID_TARGET) $(PYRAMID_OBJS)
	@echo "🗑️ Removing old files..."
	rm -f $(PYRAMID_OBJS)
	@echo "✅ $(PYRAMID_TARGET) build complete! run: ./$(PYRAMID_TARGET)"

# ============================================================================
# COMPILE
# ============================================================================

%.o: %.cpp
	@echo "⚙️ Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================================
# CLEAN
# ============================================================================

clean:
	@echo "🗑️ Removing old files..."
	rm -f $(RPN_TARGET) $(SET_TARGET) $(MIC_TARGET) $(PYRAMID_TARGET)
	find src -name "*.o" -delete
	rm -f *.db
	@echo "✅ Clean complete!"

# ============================================================================
# RUN
# ============================================================================

run-rpn: rpn
	./$(RPN_TARGET)

run-set: set
	./$(SET_TARGET)

run-mic: mic
	./$(MIC_TARGET)

run-pyramid: pyramid
	./$(PYRAMID_TARGET)

# ============================================================================
# PHONY
# ============================================================================

.PHONY: all rpn set mic pyramid clean run-rpn run-set run-mic run-pyramid