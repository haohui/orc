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

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS} ${WARN_FLAGS}")

INCLUDE(CheckCXXSourceCompiles)
CHECK_CXX_SOURCE_COMPILES("
    #include<stdint.h>
    #include<stdio.h>
    int main(int,char*[]){
      int64_t x = 1; printf(\"%lld\",x);
    }"
  INT64_IS_LL
)

configure_file (
  "orc/orc-config.hh.in"
  "orc/orc-config.hh"
  )

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/orc/orc-config.hh"
  "orc/C09Adapter.hh"
  "orc/ColumnPrinter.hh"
  "orc/Int128.hh"
  "orc/MemoryPool.hh"
  "orc/OrcFile.hh"
  "orc/Reader.hh"
  "orc/Vector.hh"
  DESTINATION "include/orc"
  )
