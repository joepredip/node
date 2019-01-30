// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_CELL_H_
#define V8_OBJECTS_CELL_H_

#include "src/objects/heap-object.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

class Cell : public HeapObject {
 public:
  // [value]: value of the cell.
  DECL_ACCESSORS(value, Object)

  DECL_CAST(Cell)

  static inline Cell FromValueAddress(Address value);

  inline Address ValueAddress() { return address() + kValueOffset; }

  // Dispatched behavior.
  DECL_PRINTER(Cell)
  DECL_VERIFIER(Cell)

  // Layout description.
#define CELL_FIELDS(V)         \
  V(kValueOffset, kTaggedSize) \
  /* Total size. */            \
  V(kSize, 0)

  DEFINE_FIELD_OFFSET_CONSTANTS(HeapObject::kHeaderSize, CELL_FIELDS)
#undef CELL_FIELDS

  typedef FixedBodyDescriptor<kValueOffset, kSize, kSize> BodyDescriptor;

  OBJECT_CONSTRUCTORS(Cell, HeapObject);
};

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"

#endif  // V8_OBJECTS_CELL_H_
