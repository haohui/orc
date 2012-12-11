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

package org.apache.hadoop.hive.ql.io.file.orc;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.hive.serde2.objectinspector.ObjectInspector;

import java.io.IOException;

public class OrcFile {

  public static final String MAGIC = "ORC";
  public static final String COMPRESSION = "orc.compress";
  static final String DEFAULT_COMPRESSION = "ZLIB";
  public static final String COMPRESSION_BLOCK_SIZE = "orc.compress.size";
  static final String DEFAULT_COMPRESSION_BLOCK_SIZE = "262144";
  public static final String STRIPE_SIZE = "orc.stripe.size";
  static final String DEFAULT_STRIPE_SIZE = "268435456";

  /**
   * Create an ORC file reader.
   * @param fs file system
   * @param path file name to read from
   * @param conf the Hadoop configuration
   * @return a new ORC file reader.
   * @throws IOException
   */
  public static Reader getReader(FileSystem fs, Path path, Configuration conf
                                 ) throws IOException {
    return new ReaderImpl(fs, path, conf);
  }

  /**
   * Create an ORC file writer.
   * @param fs file system
   * @param path filename to write to
   * @param inspector the ObjectInspector that inspects the rows
   * @param stripeSize the number of bytes in a stripe
   * @param compress how to compress the file
   * @param compressSize the number of bytes to compress at once
   * @param conf the Hadoop configuration
   * @return a new ORC file writer
   * @throws IOException
   */
  public static Writer getWriter(FileSystem fs,
                                 Path path,
                                 ObjectInspector inspector,
                                 long stripeSize,
                                 CompressionKind compress,
                                 int compressSize,
                                 Configuration conf) throws IOException {
    return new WriterImpl(fs, path, inspector, stripeSize, compress,
      compressSize, conf);
  }

}