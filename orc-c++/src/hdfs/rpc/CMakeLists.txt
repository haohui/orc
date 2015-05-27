add_library(rpc rpc_connection.cc rpc_engine.cc)
target_link_libraries(rpc hdfs_proto crypto)
add_executable(rpc_test rpc_test.cc)
target_link_libraries(rpc_test rpc common hdfs_proto crypto ${PROTOBUF_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

