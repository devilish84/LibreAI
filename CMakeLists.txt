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
    if(NOT LO_INCLUDE)
        set(LO_INCLUDE "$ENV{PROGRAMFILES}/LibreOffice_25.8_SDK/sdk/include")
    endif()
    if(NOT LO_SDK_LIB)
        set(LO_SDK_LIB "$ENV{PROGRAMFILES}/LibreOffice_25.8_SDK/sdk/lib")
    endif()
    add_compile_definitions(WNT _WIN32 CPPU_ENV=msvc)
    set(UNO_LIBS
        ${LO_SDK_LIB}/icppu.lib
        ${LO_SDK_LIB}/icppuhelper.lib
        ${LO_SDK_LIB}/isal.lib)
elseif(APPLE)
    if(NOT LO_INCLUDE)
        set(LO_INCLUDE /usr/local/include/libreoffice)
    endif()
    if(NOT LO_SDK_LIB)
        set(LO_SDK_LIB /Applications/LibreOffice.app/Contents/MacOS)
    endif()
    add_compile_definitions(MACOSX GCC CPPU_ENV=gcc3 UNX)
    set(UNO_LIBS
        ${LO_SDK_LIB}/libuno_cppu.dylib
        ${LO_SDK_LIB}/libuno_cppuhelpergcc3.dylib
        ${LO_SDK_LIB}/libuno_sal.dylib)
else()
    if(NOT LO_INCLUDE)
        set(LO_INCLUDE /usr/include/libreoffice)
    endif()
    if(NOT LO_SDK_LIB)
        set(LO_SDK_LIB /usr/lib/libreoffice/sdk/lib)
    endif()
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
    src/uno/component.cpp
    src/core/Config.cpp
    src/core/CredentialStore.cpp
    src/core/CredentialBackendMemory.cpp
    src/core/CredentialBackendKeychain.cpp
    src/core/CredentialBackendMacOS.cpp
    src/core/CredentialBackendDPAPI.cpp
    src/core/Logger.cpp
    src/ai/AIClient.cpp
    src/ai/OllamaClient.cpp
    src/ai/OpenAIClient.cpp
    src/ai/AnthropicClient.cpp
    src/ai/GrokClient.cpp
    src/ai/GeminiClient.cpp
    src/uno/UnoHelper.cpp
    src/ui/ChatWindow.cpp
    src/ui/ConfigDialog.cpp
    src/uno/CMInterceptor.cpp
    src/uno/LibreAIJob.cpp
    src/uno/LibreAIStarter.cpp
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
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/src/ai
    ${CMAKE_SOURCE_DIR}/src/ui
    ${CMAKE_SOURCE_DIR}/src/uno
)

target_link_libraries(libreai PRIVATE
    Qt6::Core Qt6::Widgets Qt6::Network
    ${UNO_LIBS}
)

if(NOT WIN32)
    find_package(Qt6Keychain QUIET)
    if(Qt6Keychain_FOUND)
        target_link_libraries(libreai PRIVATE Qt6Keychain::Qt6Keychain)
        target_compile_definitions(libreai PRIVATE HAVE_KEYCHAIN)
    else()
        # Fallback: detect manually when find_package fails due to missing DBus dev headers
        find_library(QT6KEYCHAIN_LIB NAMES qt6keychain PATHS /usr/lib/x86_64-linux-gnu)
        if(QT6KEYCHAIN_LIB)
            target_link_libraries(libreai PRIVATE ${QT6KEYCHAIN_LIB})
            target_include_directories(libreai PRIVATE /usr/include/qt6keychain)
            target_compile_definitions(libreai PRIVATE HAVE_KEYCHAIN)
            message(STATUS "Qt6Keychain found manually: ${QT6KEYCHAIN_LIB}")
        endif()
    endif()
endif()

if(WIN32)
    target_link_libraries(libreai PRIVATE Crypt32)
    target_compile_definitions(libreai PRIVATE HAVE_DPAPI)
endif()

if(APPLE)
    target_link_libraries(libreai PRIVATE "-framework Security")
    target_compile_definitions(libreai PRIVATE HAVE_MACOS_KEYCHAIN)
endif()

if(WIN32)
    set_target_properties(libreai PROPERTIES PREFIX "" OUTPUT_NAME "libreai" SUFFIX ".dll")
elseif(APPLE)
    set_target_properties(libreai PROPERTIES
        PREFIX ""
        OUTPUT_NAME "libreai"
        SUFFIX ".dylib"
        INSTALL_RPATH "@loader_path"
        BUILD_WITH_INSTALL_RPATH ON
    )
else()
    set_target_properties(libreai PROPERTIES
        PREFIX ""
        OUTPUT_NAME "libreai"
        SUFFIX ".so"
        INSTALL_RPATH "$ORIGIN"
        BUILD_WITH_INSTALL_RPATH ON
    )
endif()

option(BUILD_TESTS "Build unit tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests/unit)
endif()
