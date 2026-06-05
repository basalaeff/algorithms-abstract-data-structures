cmake_minimum_required(VERSION 3.24)
project(algorithms-abstract-data-structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_COLOR_DIAGNOSTICS ON)

# ====================== Main ======================
file(GLOB SRC_RPN
    "src/tasks/1.rpn/*.cpp"
    "src/ads/Stack/*.cpp"
)

file(GLOB SRC_SET
    "src/tasks/2.set/*.cpp"
    "src/ads/Set/*.cpp"
)

file(GLOB SRC_MIC
    "src/tasks/3.mic/*.cpp"
    "src/ads/Set/*.cpp"
)

add_executable(rpn ${SRC_RPN})
target_include_directories(rpn PRIVATE src)

add_executable(set ${SRC_SET})
target_include_directories(set PRIVATE src)

add_executable(mic ${SRC_MIC})
target_include_directories(mic PRIVATE src)

# ====================== Formatting ======================
file(GLOB_RECURSE FORMAT_FILES
  "src/*.cpp" "src/*.hpp" "src/*.tpp"
)

add_custom_target(format
    COMMAND clang-format -i ${FORMAT_FILES}
    COMMENT "Formatting code"
)