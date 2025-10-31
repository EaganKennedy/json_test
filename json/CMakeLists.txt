add_library(json STATIC  
"json.hpp" 
"ivalue.cpp" 
"null.hpp""null.cpp" 
"boolean.hpp" "boolean.cpp"
"number.hpp" "number.cpp" 
"string.hpp" "string.cpp")
target_include_directories(json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})