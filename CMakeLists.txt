cmake_minimum_required(VERSION 3.16)
project(libreai CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network
    HINTS /usr/lib/x86_64-linux-gnu/cmake)

set(LO_GEN_INCLUDE ${CMAKE_SOURCE_DIR}/include)

if(WIN32)
    set(LO_INCLUDE  "$ENV{PROGRAMFILES}/LibreOffice_25.8_SDK/sdk/include")
    set(LO_SDK_LIB  "$ENV{PROGRAMFILES}/LibreOffice_25.8_SDK/sdk/lib")
    add_compile_definitions(WNT _WIN32 CPPU_ENV=msvc)
    set(UNO_LIBS
        ${LO_SDK_LIB}/icppu.lib
        ${LO_SDK_LIB}/icppuhelper.lib
        ${LO_SDK_LIB}/isal.lib)
else()
    set(LO_INCLUDE  /usr/include/libreoffice)
    set(LO_SDK_LIB  /usr/lib/libreoffice/sdk/lib)
    add_compile_definitions(LINUX GCC CPPU_ENV=gcc3 UNX)
    set(UNO_LIBS
        ${LO_SDK_LIB}/libuno_cppu.so
        ${LO_SDK_LIB}/libuno_cppuhelpergcc3.so
        ${LO_SDK_LIB}/libuno_sal.so)
endif()

# Compile .ts → .qm before the build (requires lrelease on PATH)
find_program(LRELEASE_EXECUTABLE NAMES lrelease lrelease-qt6)
if(LRELEASE_EXECUTABLE)
    file(GLOB TS_FILES "${CMAKE_SOURCE_DIR}/translations/*.ts")
    foreach(TS ${TS_FILES})
        string(REPLACE ".ts" ".qm" QM ${TS})
        add_custom_command(
            OUTPUT  ${QM}
            COMMAND ${LRELEASE_EXECUTABLE} ${TS} -qm ${QM}
            DEPENDS ${TS}
            COMMENT "Compiling ${TS}"
        )
        list(APPEND QM_FILES ${QM})
    endforeach()
    add_custom_target(translations ALL DEPENDS ${QM_FILES})
endif()

set(SOURCES
    src/component.cpp
    src/Config.cpp
    src/AIClient.cpp
    src/OllamaClient.cpp
    src/OpenAIClient.cpp
    src/AnthropicClient.cpp
    src/UnoHelper.cpp
    src/ChatWindow.cpp
    src/ConfigDialog.cpp
    src/CMInterceptor.cpp
    src/Logger.cpp
    src/LibreAIJob.cpp
    src/LibreAIStarter.cpp
    translations/libreai_translations.qrc
)

add_library(libreai SHARED ${SOURCES})
if(LRELEASE_EXECUTABLE)
    add_dependencies(libreai translations)
endif()

target_include_directories(libreai PRIVATE
    ${LO_INCLUDE}
    ${LO_GEN_INCLUDE}
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(libreai PRIVATE
    Qt6::Core Qt6::Widgets Qt6::Network
    ${UNO_LIBS}
)

if(WIN32)
    set_target_properties(libreai PROPERTIES PREFIX "" OUTPUT_NAME "libreai" SUFFIX ".dll")
else()
    set_target_properties(libreai PROPERTIES PREFIX "" OUTPUT_NAME "libreai" SUFFIX ".so")
endif()

option(BUILD_TESTS "Build unit tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests/unit)
endif()
