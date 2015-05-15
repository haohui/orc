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

configure_file (
  "include/orc/orc-config.hh.in"
  "include/orc/orc-config.hh"
  )

include_directories (
  "include"
  )

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/include/orc/orc-config.hh"
  "include/orc/C09Adapter.hh"
  "include/orc/ColumnPrinter.hh"
  "include/orc/Int128.hh"
  "include/orc/MemoryPool.hh"
  "include/orc/OrcFile.hh"
  "include/orc/Reader.hh"
  "include/orc/Vector.hh"
  DESTINATION "include"
  )

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(test)
