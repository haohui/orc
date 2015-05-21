# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include_directories (
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}/orc-c++/src
  ${PROJECT_SOURCE_DIR}/orc-c++/src
  ${PROTOBUF_INCLUDE_DIRS}
  ${ZLIB_INCLUDE_DIRS}
  ${SNAPPY_INCLUDE_DIRS}
  )

set (PROTOBUF_IMPORT_DIRS ${CMAKE_SOURCE_DIR}/proto)
protobuf_generate_cpp(ORC_PROTO_SRCS ORC_PROTO_HDRS "${CMAKE_SOURCE_DIR}/proto/orc_proto.proto")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS} ${WARN_FLAGS}")

if (C09)
  set (ADAOPTOR_CLASS "C09Adapter.cc")
endif (C09)

add_library (orc STATIC
  ${ADAPTOR_CLASS}
  orc_proto.pb.h
  orc-proto-wrapper.cc
  ByteRLE.cc
  ColumnPrinter.cc
  ColumnReader.cc
  Compression.cc
  Exceptions.cc
  Int128.cc
  MemoryPool.cc
  OrcFile.cc
  Reader.cc
  RLEv1.cc
  RLEv2.cc
  RLE.cc
  TypeImpl.cc
  Vector.cc
  )

install(TARGETS orc DESTINATION lib)

target_link_libraries (orc
  ${PROTOBUF_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${SNAPPY_LIBRARIES}
  )

