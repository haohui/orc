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

#ifndef UNISTD_H
#define UNISTD_H

// account for the lack of pread in Windows
#include <io.h>
#include <BaseTsd.h>
#ifndef ssize_t
#define ssize_t SSIZE_T
#endif

inline ssize_t pread(int fd, void *buf, size_t count, off_t offset) {
  lseek(fd, offset, SEEK_SET);
  ssize_t bytesRead = read(fd, buf, count);
  lseek(fd, offset, SEEK_SET);
  return bytesRead;
}

#endif // UNISTD_H
