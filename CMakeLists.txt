cmake_minimum_required(VERSION 3.14)
project(leetcode_local)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fno-sanitize-recover=all")

# 遍历问题列表生成可执行文件
file(GLOB problem_dirs "questions/*")
foreach(problem_dir ${problem_dirs})
    get_filename_component(problem_name ${problem_dir} NAME)
    
    add_executable(${problem_name} util/leetcodemain.cpp)
    target_include_directories(${problem_name}   PRIVATE questions/${problem_name})
    target_include_directories(${problem_name}   PRIVATE util)

    set_target_properties(${problem_name} PROPERTIES LINKER_LANGUAGE CXX)
    # target_sources(${problem_name} PRIVATE ${problem_dir}/solution.hpp ${problem_dir}/units.hpp util/basic.hpp)
endforeach(problem_dir ${problem_dirs})


