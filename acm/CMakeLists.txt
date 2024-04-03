project(acm)
file(GLOB acm_problem_dirs "questions/*")
foreach(acm_problem_dir ${acm_problem_dirs})
    get_filename_component(acmproblem_name ${acm_problem_dir} NAME)

    add_executable(${acmproblem_name} questions/${acmproblem_name}/main.cpp)
    set_target_properties(${acmproblem_name} PROPERTIES LINKER_LANGUAGE CXX)

endforeach(acm_problem_dir ${acm_problem_dirs})
