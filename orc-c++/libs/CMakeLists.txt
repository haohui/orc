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

if (MSVC)
  if (NOT Protobuf_FOUND)
    add_subdirectory(protobuf-${PROTOBUF_VERSION})
  endif (NOT Protobuf_FOUND)
  
  if (NOT ZLIB_FOUND)
    add_subdirectory(zlib-${ZLIB_VERSION})
  endif (NOT ZLIB_FOUND)
endif (MSVC)
add_subdirectory(gmock-${GMOCK_VERSION})
