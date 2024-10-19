
set(SRC vm.cpp ${CMAKE_SOURCE_DIR}/src/lib/loader.cpp)
add_executable(vm ${SRC})
target_include_directories(vm PRIVATE ${CMAKE_SOURCE_DIR}/src/include)