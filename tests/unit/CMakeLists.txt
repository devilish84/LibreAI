find_package(GTest REQUIRED)

# All credential backend source files — each is ifdef-guarded for its platform,
# so including all of them on every platform is safe.
set(CREDENTIAL_SOURCES
    ${CMAKE_SOURCE_DIR}/src/core/CredentialStore.cpp
    ${CMAKE_SOURCE_DIR}/src/core/CredentialBackendMemory.cpp
    ${CMAKE_SOURCE_DIR}/src/core/CredentialBackendKeychain.cpp
    ${CMAKE_SOURCE_DIR}/src/core/CredentialBackendMacOS.cpp
    ${CMAKE_SOURCE_DIR}/src/core/CredentialBackendDPAPI.cpp
)

# ---- helpers ----------------------------------------------------------------

macro(libreai_test TARGET)
    target_include_directories(${TARGET} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/ai
        ${CMAKE_SOURCE_DIR}/include
        /usr/include/libreoffice
    )
    target_compile_definitions(${TARGET} PRIVATE LINUX GCC CPPU_ENV=gcc3 UNX)

    find_library(QT6KEYCHAIN_LIB NAMES qt6keychain PATHS /usr/lib/x86_64-linux-gnu)
    if(QT6KEYCHAIN_LIB)
        target_link_libraries(${TARGET} PRIVATE ${QT6KEYCHAIN_LIB})
        target_include_directories(${TARGET} PRIVATE /usr/include/qt6keychain)
        target_compile_definitions(${TARGET} PRIVATE HAVE_KEYCHAIN)
    endif()

    target_link_libraries(${TARGET} PRIVATE GTest::GTest GTest::Main)
endmacro()

# ---- test_config ------------------------------------------------------------

add_executable(test_config
    test_config.cpp
    ${CMAKE_SOURCE_DIR}/src/core/Config.cpp
    ${CREDENTIAL_SOURCES}
)
libreai_test(test_config)
target_link_libraries(test_config PRIVATE Qt6::Core Qt6::Widgets)
add_test(NAME ConfigTests COMMAND test_config)

# ---- test_logger ------------------------------------------------------------

add_executable(test_logger
    test_logger.cpp
    ${CMAKE_SOURCE_DIR}/src/core/Logger.cpp
    ${CMAKE_SOURCE_DIR}/src/core/Config.cpp
    ${CREDENTIAL_SOURCES}
)
libreai_test(test_logger)
target_link_libraries(test_logger PRIVATE Qt6::Core Qt6::Widgets)
add_test(NAME LoggerTests COMMAND test_logger)

# ---- test_ai_parsing --------------------------------------------------------

add_executable(test_ai_parsing
    test_ai_parsing.cpp
    ${CMAKE_SOURCE_DIR}/src/ai/AIClient.cpp
    ${CMAKE_SOURCE_DIR}/src/ai/OllamaClient.cpp
    ${CMAKE_SOURCE_DIR}/src/ai/OpenAIClient.cpp
    ${CMAKE_SOURCE_DIR}/src/ai/AnthropicClient.cpp
    ${CMAKE_SOURCE_DIR}/src/core/Config.cpp
    ${CREDENTIAL_SOURCES}
)
libreai_test(test_ai_parsing)
target_link_libraries(test_ai_parsing PRIVATE Qt6::Core Qt6::Widgets Qt6::Network)
add_test(NAME AIParsingTests COMMAND test_ai_parsing)
