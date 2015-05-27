add_library(common hdfs.cc base64.cc datatransfer_sasl.cc sasl_digest_md5.cc status.cc)
target_link_libraries(common hdfs_proto)
add_executable(sasl_digest_md5_test sasl_digest_md5_test.cc)
target_link_libraries(sasl_digest_md5_test common crypto ${GMOCK_LIBRARIES})
add_test(sasl_digest_md5_test sasl_digest_md5_test)

