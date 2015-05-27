include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/proto
  ${PROJECT_SOURCE_DIR}/orc-c++/src
  ${PROJECT_SOURCE_DIR}/orc-c++/libs/asio-1.10.2/include
  ${PROJECT_SOURCE_DIR}/orc-c++/libs/boringssl/include
  ${PROTOBUF_INCLUDE_DIRS}
  ${GMOCK_INCLUDE_DIRS}
)

add_definitions(-DASIO_STANDALONE)

if(UNIX)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -fPIC -fno-strict-aliasing")
endif()

add_subdirectory(common)
add_subdirectory(fs)
add_subdirectory(reader)
add_subdirectory(rpc)
add_subdirectory(proto)

