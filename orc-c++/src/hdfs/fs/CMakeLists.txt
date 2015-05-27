add_library(fs filesystem.cc inputstream.cc)
target_link_libraries(fs hdfs_proto)
add_executable(inputstream_test inputstream_test.cc)
target_link_libraries(inputstream_test fs rpc reader common hdfs_proto ${PROTOBUF_LIBRARIES} ${OPENSSL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
