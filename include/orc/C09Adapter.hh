/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef C09ADAPTER_HH_
#define C09ADAPTER_HH_

#if __cplusplus < 201103L
  #include <stdint.h>
  #include <climits>
  #include <string>

  #ifndef UINT32_MAX
    #define UINT32_MAX (4294967295U)
  #endif

  #define unique_ptr auto_ptr
  #define nullptr NULL
  #define override

  #ifndef _WIN32
  // VS10 has already had this Adapter.
    namespace std {
      template<typename T>
      inline T move(T& x) { return x; }
    } // std
  #endif

  namespace std {
    // A poor man's stoll that converts str to a long long int base 10
    int64_t stoll(std::string str);
  } // namespace std



  /* Containers of unique_ptr<T> are replaced with DataBuffer<T> or std::vector<T>
   * unique_ptr to arrays are replaced with std::vector
   * Unsupported containers (e.g. initializer_list) are replaced with std::vector
   * Rvalue references && are replaced by &
   * auto is replaced with appropriate data type
   */

#else
  #include <initializer_list>
  #include <array>

#endif // __cplusplus


#endif /* C09ADAPTER_HH_ */
