find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests 
test.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain vec)

include(CTest)
include(Catch)

catch_discover_tests(tests)