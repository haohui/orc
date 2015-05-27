add_library(reader remote_block_reader.cc)
target_link_libraries(reader hdfs_proto)
add_executable(remote_block_reader_test remote_block_reader_test.cc)
target_link_libraries(remote_block_reader_test reader hdfs_proto common ${PROTOBUF_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
