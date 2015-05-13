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
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}
  ${PROTOBUF_INCLUDE_DIRS}
  ${ZLIB_INCLUDE_DIRS}
  ${SNAPPY_INCLUDE_DIRS}
  )

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS orc_proto.proto)

set (CMAKE_CXX_FLAGS "-O0 ${CMAKE_CXX_FLAGS} -g ${CXX11_FLAGS} ${WARN_FLAGS}")

if (C09)
  set (ADAOPTOR_CLASS "C09Adapter.cc")
endif (C09)

add_library (orc STATIC
  ${PROTO_HDRS}
  wrap/orc-proto-wrapper.cc
  ByteRLE.cc
  ${ADAPTOR_CLASS}
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
  ColumnPrinter.cc
  )

if (MSVC)
  add_dependencies (orc libprotobuf libprotobuf-lite protoc zlib zlibstatic)
endif (MSVC)

target_link_libraries (orc
  ${PROTOBUF_LITE_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${SNAPPY_LIBRARIES}
  )

add_executable (file-contents
  FileContents.cc
  )

target_link_libraries (file-contents
  orc
  ${PROTOBUF_LIBRARIES}
  )

add_executable (file-scan
  FileScan.cc
  )

target_link_libraries (file-scan
  orc
  ${PROTOBUF_LIBRARIES}
  )

add_executable (file-metadata
  FileMetadata.cc
  )

target_link_libraries (file-metadata
  orc
  ${PROTOBUF_LIBRARIES}
  )
  
 add_executable (file-statistics
  FileStatistics.cc
  )

target_link_libraries (file-statistics
  orc
  ${PROTOBUF_LIBRARIES}
  ) 
