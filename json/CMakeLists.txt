add_library(json STATIC  "json.hpp" "json.cpp" "json_null.cpp")
target_include_directories(json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})