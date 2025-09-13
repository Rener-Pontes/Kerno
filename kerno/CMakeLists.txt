file(
    GLOB_RECURSE files
    CONFIGURE_DEPENDS

    "${CMAKE_CURRENT_LIST_DIR}/src/*.[c,h]pp"
)

add_library(Kerno SHARED ${files})

target_include_directories(Kerno PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/)

target_precompile_headers(Kerno PRIVATE ${CMAKE_CURRENT_LIST_DIR}/pch.hpp)

set_target_build_settings(Kerno)
target_compile_definitions(Kerno PRIVATE $<$<PLATFORM_ID:Windows>:KRN_BUILD_DLL>)

