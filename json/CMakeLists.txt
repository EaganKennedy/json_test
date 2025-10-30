add_library(json STATIC  
"json.hpp"  
"null.hpp""null.cpp" 
"boolean.hpp" "boolean.cpp" 
"ivalue.cpp" 
"number.hpp" "number.cpp")
target_include_directories(json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})