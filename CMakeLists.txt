cmake_minimum_required(VERSION 3.24)
project(algorithms-abstract-data-structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_COLOR_DIAGNOSTICS ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

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

file(GLOB SRC_PYRAMID
    "src/tasks/4.pyramid/*.cpp"
    "src/ads/Array/*.cpp"
)

file(GLOB SRC_FORK
    "src/tasks/5.fork/*.cpp"
    "src/ads/BinarySearchTree/*.cpp"
)

add_executable(rpn ${SRC_RPN})
target_include_directories(rpn PRIVATE src)

add_executable(set ${SRC_SET})
target_include_directories(set PRIVATE src)

add_executable(mic ${SRC_MIC})
target_include_directories(mic PRIVATE src)

add_executable(pyramid ${SRC_PYRAMID})
target_include_directories(pyramid PRIVATE src)

add_executable(fork ${SRC_FORK})
target_include_directories(fork PRIVATE src)

# ====================== Formatting ======================
file(GLOB_RECURSE FORMAT_FILES
  "src/*.cpp" "src/*.hpp" "src/*.tpp"
)

add_custom_target(format
    COMMAND clang-format -i ${FORMAT_FILES}
    COMMENT "Formatting code"
)

# ====================== Tests ======================

find_package(GTest REQUIRED)

enable_testing()

add_executable(dhtTests
    tests/6.dht/dhtTest.cpp
)

target_include_directories(dhtTests PRIVATE src)

target_link_libraries(dhtTests
    GTest::gtest
    GTest::gtest_main
)


add_test(NAME dhtTests COMMAND dhtTests)

add_custom_target(tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS dhtTests
)

# ====================== Coverage ======================
function(enable_coverage target_name)
    if(ENABLE_COVERAGE)
        target_compile_options(${target_name} PRIVATE
            --coverage
            -O0
            -g
        )

        target_link_options(${target_name} PRIVATE
            --coverage
        )
    endif()
endfunction()

enable_coverage(dhtTests)

find_program(LCOV lcov)
find_program(GENHTML genhtml)

if(LCOV AND GENHTML)
    add_custom_target(coverage
        # 1. Запуск тестов
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure

        # 2. Сбор покрытия
        COMMAND ${LCOV}
                --capture
                --directory ${CMAKE_BINARY_DIR}
                --output-file ${CMAKE_BINARY_DIR}/coverage.info
                --ignore-errors mismatch,unused,source

        # 3. Фильтрация (паттерны БЕЗ кавычек!)
        COMMAND ${LCOV}
                --remove ${CMAKE_BINARY_DIR}/coverage.info
                /usr/*
                */gtest/*
                */gmock/*
                */test/*
                --output-file ${CMAKE_BINARY_DIR}/coverage.info
                --ignore-errors unused,mismatch,source

        # 4. Генерация HTML
        COMMAND ${GENHTML}
                ${CMAKE_BINARY_DIR}/coverage.info
                --output-directory ${CMAKE_BINARY_DIR}/coverage_report
                --ignore-errors source

        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating coverage report"
        VERBATIM
    )
endif()
