file(
    GLOB_RECURSE files
    CONFIGURE_DEPENDS

    "${CMAKE_CURRENT_LIST_DIR}/src/*.[c,h]pp"
)

add_executable(Sandbox ${files})

target_include_directories(Sandbox PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/)
target_link_libraries(Sandbox PRIVATE Kerno)

set_target_build_settings(Sandbox)

