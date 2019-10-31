add_executable(hash_table_test hash_table_test.cc)
target_link_libraries(hash_table_test gtest glog gflags hash_table)
add_test(NAME hash_table_test COMMAND hash_table_test)
