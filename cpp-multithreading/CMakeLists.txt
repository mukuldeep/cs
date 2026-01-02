cmake_minimum_required(VERSION 3.17)
project(cpp_multithreading)

set(CMAKE_CXX_STANDARD 14)


#file(GLOB_RECURSE CONFIGURE_DEPENDS all_source_files "*.cpp" "*.cxx")
file(GLOB_RECURSE all_source_files "*.cpp" "*.cxx")

foreach(source_file IN LISTS all_source_files)
    # Get the name of the file without the extension (e.g., 'main' from 'src/main.cpp')
    get_filename_component(target_name ${source_file} NAME_WE)

    # Make sure the target name is valid (e.g., replace spaces or slashes if necessary for complex paths)
    # This example assumes the file names themselves are unique enough to be target names

    # Create an executable with the target name, building from the single source file
    add_executable("${target_name}" "${source_file}")

    # Optional: set output directory for all executables to a common bin folder
#    set_target_properties("${target_name}" PROPERTIES
#            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
#            )
endforeach()

#add_executable(cpp_multithreading main.cpp)
#add_executable(thread_test threading/thread_test.cpp)
#add_executable(race_condition threading/race_condition_1.cpp)
#add_executable(race_condition_sol_mutex threading/race_condition_1_mutex_solution.cpp)
#add_executable(race_condition_sol_atomic threading/race_condition_1_atomic_solution.cpp)
#
#add_executable(mutex_lock_unlock threading/race_condition_1_atomic_solution.cpp)
