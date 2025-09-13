cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Looking for ccache")
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    message(STATUS "Looking for ccache - FOUND")
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
else()
    message(STATUS "Looking for ccache - NOT FOUND")
endif()

project(KernoEngine LANGUAGES CXX)

function(set_target_build_settings target)
    target_compile_definitions(
        ${target} PRIVATE

        # Platforms
        $<$<PLATFORM_ID:Windows>:KRN_PLATFORM_WINDOWS>
        $<$<PLATFORM_ID:Linux>:KRN_PLATFORM_LINUX>

        # Build Configs
        $<$<CONFIG:Debug,RelWithDebInfo>:KRN_DEBUG>
        $<$<CONFIG:Release,RelWithDebInfo>:KRN_RELEASE>
    )

    target_compile_options(
        ${target} PRIVATE
        $<$<PLATFORM_ID:Windows>:/utf-8;/W4>
        $<$<PLATFORM_ID:Linux>:-Wall;-Wextra>
    )

endfunction()

add_subdirectory(kerno)
add_subdirectory(sandbox)
