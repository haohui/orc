/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GMOCK_WRAPPER_H
#define GMOCK_WRAPPER_H

// we need to disable a whole set of warnings as we include gtest.h
// restore most of the warnings after the file is loaded.

#ifdef __clang__
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wdeprecated"
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
  #pragma clang diagnostic ignored "-Wpadded"
  #pragma clang diagnostic ignored "-Wshift-sign-overflow"
  #pragma clang diagnostic ignored "-Wsign-compare"
  #pragma clang diagnostic ignored "-Wsign-conversion"
  #pragma clang diagnostic ignored "-Wundef"
  #pragma clang diagnostic ignored "-Wused-but-marked-unused"
  #pragma clang diagnostic ignored "-Wweak-vtables"
#else
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wsign-compare"
#endif

#include "gmock/gmock.h"

#ifdef __clang__
  #pragma clang diagnostic pop
#else
  #pragma GCC diagnostic pop
#endif

#endif
