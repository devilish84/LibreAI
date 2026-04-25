find_package(GTest REQUIRED)

# Config unit tests — link only Qt6::Core, no UNO needed
add_executable(test_config
    test_config.cpp
    ${CMAKE_SOURCE_DIR}/src/core/Config.cpp
)

target_include_directories(test_config PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/include
    /usr/include/libreoffice          # header-only, no link
)

target_compile_definitions(test_config PRIVATE LINUX GCC CPPU_ENV=gcc3 UNX)

target_link_libraries(test_config PRIVATE
    Qt6::Core
    Qt6::Widgets
    GTest::GTest
    GTest::Main
)

add_test(NAME ConfigTests COMMAND test_config)
