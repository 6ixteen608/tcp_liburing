file(GLOB_RECURSE LIB_SOURCES "*.h" "*.cpp")

add_library(server SHARED ${LIB_SOURCES})
target_link_libraries(server uring)
