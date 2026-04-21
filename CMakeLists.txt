cmake_minimum_required(VERSION 3.16)
project(libreai CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network
    HINTS /usr/lib/x86_64-linux-gnu/cmake)

set(LO_INCLUDE      /usr/include/libreoffice)
set(LO_CPPU_INCLUDE /usr/include/libreoffice)
set(LO_GEN_INCLUDE  ${CMAKE_SOURCE_DIR}/include)
set(LO_SDK_LIB      /usr/lib/libreoffice/sdk/lib)

add_compile_definitions(LINUX GCC CPPU_ENV=gcc3 UNX)

set(SOURCES
    src/component.cpp
    src/Config.cpp
    src/AIClient.cpp
    src/OllamaClient.cpp
    src/OpenAIClient.cpp
    src/AnthropicClient.cpp
    src/UnoHelper.cpp
    src/ChatWindow.cpp
    src/CMInterceptor.cpp
    src/LibreAIJob.cpp
    src/LibreAIStarter.cpp
)

add_library(libreai SHARED ${SOURCES})

target_include_directories(libreai PRIVATE
    ${LO_INCLUDE}
    ${LO_GEN_INCLUDE}
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(libreai PRIVATE
    Qt6::Core Qt6::Widgets Qt6::Network
    ${LO_SDK_LIB}/libuno_cppu.so
    ${LO_SDK_LIB}/libuno_cppuhelpergcc3.so
    ${LO_SDK_LIB}/libuno_sal.so
)

set_target_properties(libreai PROPERTIES PREFIX "" OUTPUT_NAME "libreai")
