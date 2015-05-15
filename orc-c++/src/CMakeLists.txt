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
  ${CMAKE_CURRENT_BINARY_DIR}
  ${PROTOBUF_INCLUDE_DIRS}
  ${ZLIB_INCLUDE_DIRS}
  ${SNAPPY_INCLUDE_DIRS}
  )

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ../../proto/orc_proto.proto)

set (CMAKE_CXX_FLAGS "-O0 ${CMAKE_CXX_FLAGS} -g ${CXX11_FLAGS} ${WARN_FLAGS}")

if (C09)
  set (ADAOPTOR_CLASS "orc/C09Adapter.cc")
endif (C09)

add_library (orc STATIC
  ${ADAPTOR_CLASS}
  ${PROTO_HDRS}
  wrap/orc-proto-wrapper.cc
  orc/ByteRLE.cc
  orc/ColumnPrinter.cc
  orc/ColumnReader.cc
  orc/Compression.cc
  orc/Exceptions.cc
  orc/Int128.cc
  orc/MemoryPool.cc
  orc/OrcFile.cc
  orc/Reader.cc
  orc/RLEv1.cc
  orc/RLEv2.cc
  orc/RLE.cc
  orc/TypeImpl.cc
  orc/Vector.cc
  )

install(TARGETS orc DESTINATION lib)

if (MSVC)
  add_dependencies (orc libprotobuf libprotobuf-lite protoc zlib zlibstatic)
endif (MSVC)

target_link_libraries (orc
  ${PROTOBUF_LITE_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${SNAPPY_LIBRARIES}
  )

