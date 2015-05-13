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

cmake_minimum_required (VERSION 2.6)

project(ORC)
set (ORC_VERSION "1.0.0")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set (GMOCK_VERSION "1.7.0")
include_directories(
  ${CMAKE_SOURCE_DIR}/third_party/gmock-${GMOCK_VERSION}/include
  ${CMAKE_SOURCE_DIR}/third_party/gmock-${GMOCK_VERSION}/gtest/include
  )

if (MSVC)
  set (GMOCK_LIB "${CMAKE_BINARY_DIR}/third_party/gmock-${GMOCK_VERSION}/gmock_main")
  set (PROTOBUF_VERSION "2.6.0")
  set (ZLIB_VERSION "1.2.8")
  add_definitions (-D_SCL_SECURE_NO_WARNINGS)
  add_definitions (-D_CRT_SECURE_NO_WARNINGS)
  # TODO: We assume MSVC debug mode. In the future, set these flags
  # appropriately for all build mode.
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:libc.lib")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:libcmt.lib")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:msvcrt.lib")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:libcd.lib")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:msvcrtd.lib")
  include_directories(${CMAKE_SOURCE_DIR}/os/win)
  
  find_package (Protobuf)
  
  if (NOT Protobuf_FOUND)
    include_directories(
    ${CMAKE_SOURCE_DIR}/third_party/protobuf-${PROTOBUF_VERSION}/include
    )
    set (PROTOBUF_PROTOC_EXECUTABLE ${CMAKE_BINARY_DIR}/third_party/protobuf-${PROTOBUF_VERSION}/${CMAKE_CFG_INTDIR}/protoc.exe)
    set (PROTOBUF_LITE_LIBRARIES "${CMAKE_BINARY_DIR}/third_party/protobuf-${PROTOBUF_VERSION}/${CMAKE_CFG_INTDIR}/libprotobuf-lite.lib")
    set (PROTOBUF_LIBRARIES "${CMAKE_BINARY_DIR}/third_party/protobuf-${PROTOBUF_VERSION}/${CMAKE_CFG_INTDIR}/libprotobuf.lib")
    message (STATUS "PROTOBUF_LIBRARIES = ${PROTOBUF_LIBRARIES}")
    message (STATUS "PROTOBUF_LITE_LIBRARIES = ${PROTOBUF_LITE_LIBRARIES}")
    message (STATUS "PROTOBUF_LIBRARY = ${PROTOBUF_LIBRARY}")
    message (STATUS "PROTOBUF_LITE_LIBRARY = ${PROTOBUF_LITE_LIBRARY}")
  endif (NOT Protobuf_FOUND)
  
  find_package(ZLIB)
  
  if (NOT ZLIB_FOUND)
    set (ZLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/third_party/zlib-${ZLIB_VERSION}/include)
    include_directories(${ZLIB_INCLUDE_DIR})
    set (ZLIB_LIBRARIES "${CMAKE_BINARY_DIR}/third_party/zlib-${ZLIB_VERSION}/${CMAKE_CFG_INTDIR}/zlibstaticd.lib")
    message (STATUS "ZLIB_INCLUDE_DIR = ${ZLIB_INCLUDE_DIR}")
    message (STATUS "ZLIB_LIBRARIES = ${ZLIB_LIBRARIES}")
  endif (NOT ZLIB_FOUND)
  
else(MSVC)
  set (GMOCK_LIB "${CMAKE_BINARY_DIR}/third_party/gmock-${GMOCK_VERSION}/libgmock_main.a")

  find_package (Protobuf REQUIRED)
  MESSAGE( STATUS "PROTOBUF_INCLUDE_DIR:       " ${PROTOBUF_INCLUDE_DIR} )
  MESSAGE( STATUS "PROTOBUF_LITE_LIBRARIES:    " ${PROTOBUF_LITE_LIBRARIES} )
  MESSAGE( STATUS "PROTOBUF_LIBRARIES:         " ${PROTOBUF_LIBRARIES} )
  MESSAGE( STATUS "PROTOBUF_PROTOC_EXECUTABLE: " ${PROTOBUF_PROTOC_EXECUTABLE} )
  MESSAGE( STATUS "PROTOBUF_LIBRARY:           " ${PROTOBUF_LIBRARY} )
  MESSAGE( STATUS "PROTOBUF_LITE_LIBRARY:      " ${PROTOBUF_LITE_LIBRARY} )

  find_package(ZLIB REQUIRED)
  MESSAGE( STATUS "ZLIB_INCLUDE_DIR:           " ${ZLIB_INCLUDE_DIR} )
  MESSAGE( STATUS "ZLIB_LIBRARY:               " ${ZLIB_LIBRARY} )
  MESSAGE( STATUS "ZLIB_INCLUDE_DIRS:          " ${ZLIB_INCLUDE_DIR} )
  MESSAGE( STATUS "ZLIB_LIBRARIES:             " ${ZLIB_LIBRARIES} )

  find_package(Snappy REQUIRED)
  MESSAGE( STATUS "SNAPPY_ROOT_DIR:            " ${SNAPPY_ROOT_DIR} )
  MESSAGE( STATUS "SNAPPY_LIBRARY:             " ${SNAPPY_LIBRARY} )
  MESSAGE( STATUS "SNAPPY_INCLUDE_DIR:         " ${SNAPPY_INCLUDE_DIR} )
  MESSAGE( STATUS "SNAPPY_LIBRARIES:           " ${SNAPPY_LIBRARIES} )
  MESSAGE( STATUS "SNAPPY_INCLUDE_DIRS:        " ${SNAPPY_INCLUDE_DIRS} )
endif(MSVC)

if(NOT APPLE AND NOT MSVC)
  list (APPEND GMOCK_LIB pthread)
endif(NOT APPLE AND NOT MSVC)
enable_testing()

if(NOT C09 AND NOT MSVC)
  # Visual studio enables C++11 support by default.
  set (CXX11_FLAGS "-std=c++11")
endif(NOT C09 AND NOT MSVC)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set (COVERAGE_FLAGS "--coverage -g -O0")
  set (CXX11_FLAGS "${CXX11_FLAGS}")
  set (WARN_FLAGS "-Weverything -Wno-c++98-compat -Wno-missing-prototypes")
  set (WARN_FLAGS "${WARN_FLAGS} -Wno-c++98-compat-pedantic -Wno-padded")
  set (WARN_FLAGS "${WARN_FLAGS} -Wno-covered-switch-default")
  set (WARN_FLAGS "${WARN_FLAGS} -Wno-missing-noreturn -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set (WARN_FLAGS "-Wall -Werror")
endif ()

if (NOT MSVC)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif (NOT MSVC)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_FLAGS}")

set (EXAMPLE_DIRECTORY ${CMAKE_SOURCE_DIR}/examples)

add_subdirectory(third_party)
add_subdirectory(src)
if(NOT C09)
  add_subdirectory(test)
endif(NOT C09)

configure_file (
  "include/orc/orc-config.hh.in"
  "include/orc/orc-config.hh"
  )

