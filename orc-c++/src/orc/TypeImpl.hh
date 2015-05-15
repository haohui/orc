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

#ifndef TYPE_IMPL_HH
#define TYPE_IMPL_HH

#include "orc/Vector.hh"

#include "wrap/orc-proto-wrapper.hh"

#include <vector>

namespace orc {

  class TypeImpl: public Type {
  private:
    int columnId;
    TypeKind kind;
    std::vector<Type*> subTypes;
    std::vector<std::string> fieldNames;
    unsigned int subtypeCount;
    unsigned int maxLength;
    unsigned int precision;
    unsigned int scale;

  public:
    /**
     * Create most of the primitive types.
     */
    TypeImpl(TypeKind kind);

    /**
     * Create char and varchar type.
     */
    TypeImpl(TypeKind kind, unsigned int maxLength);

    /**
     * Create decimal type.
     */
    TypeImpl(TypeKind kind, unsigned int precision,
             unsigned int scale);

    /**
     * Create struct type.
     */
    TypeImpl(TypeKind kind,
             const std::vector<Type*>& types,
             const std::vector<std::string>& fieldNames);

    /**
     * Create list, map, and union type.
     */
    TypeImpl(TypeKind kind, const std::vector<Type*>& types);

    virtual ~TypeImpl();

    int assignIds(int root) override;

    int getColumnId() const override;

    TypeKind getKind() const override;

    unsigned int getSubtypeCount() const override;

    const Type& getSubtype(unsigned int i) const override;

    const std::string& getFieldName(unsigned int i) const override;

    unsigned int getMaximumLength() const override;

    unsigned int getPrecision() const override;

    unsigned int getScale() const override;

    std::string toString() const override;
  };

  std::unique_ptr<Type> convertType(const proto::Type& type,
                                    const proto::Footer& footer);
}

#endif
