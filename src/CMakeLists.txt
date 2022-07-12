find_package(fmt REQUIRED)


add_executable(app main.cpp vec.hpp)
target_link_libraries(app PRIVATE fmt::fmt)