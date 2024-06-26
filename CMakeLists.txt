cmake_minimum_required(VERSION 3.14)
project(leetcode_local)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fsanitize=address -fno-sanitize-recover=all -Wno-c99-designator")
# 遍历问题列表生成可执行文件
file(GLOB problem_dirs "./questions/*")
foreach(problem_dir ${problem_dirs})
    get_filename_component(problem_name ${problem_dir} NAME)
    
    set(problem_main "${CMAKE_BINARY_DIR}/problem_mains/${problem_name}_leetcodemain.cpp")
    configure_file(util/leetcodemain.cpp.in ${problem_main}) ## 帮我完成这里
    add_executable(${problem_name} ${problem_main})
    target_include_directories(${problem_name}   PRIVATE questions/${problem_name})
    target_include_directories(${problem_name}   PRIVATE include)

    set_target_properties(${problem_name} PROPERTIES LINKER_LANGUAGE CXX)
endforeach(problem_dir ${problem_dirs})

