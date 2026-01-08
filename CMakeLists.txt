cmake_minimum_required ( VERSION  3.10 )
project ( cf_template )
set ( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set ( CMAKE_CXX_STANDARD  20 )
set ( CMAKE_CXX_STANDARD_REQUIRED  True )
set ( CMAKE_BUILD_TYPE  Debug )
add_executable ( main  main.cpp )
target_compile_definitions ( main  PRIVATE  DEBUG )

