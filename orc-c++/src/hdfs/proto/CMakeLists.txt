protobuf_generate_cpp(HDFS_PROTO_SRCS HDFS_PROTO_HDRS
    datatransfer.proto hdfs.proto Security.proto
    IpcConnectionContext.proto ProtobufRpcEngine.proto RpcHeader.proto
    acl.proto xattr.proto encryption.proto inotify.proto
    ClientNamenodeProtocol.proto)
add_library(hdfs_proto ${HDFS_PROTO_SRCS} ${HDFS_PROTO_HDRS})
add_dependencies(hdfs_proto protoc)
