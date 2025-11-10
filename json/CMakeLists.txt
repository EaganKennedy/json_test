add_library(json STATIC  
"json.hpp" 
"iData.cpp" 
"null.cpp" 
"boolean.cpp"
"number.cpp" 
"string.cpp" 
"array.cpp" 
"object.cpp")
target_include_directories(json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})