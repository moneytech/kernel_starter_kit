#ifndef KSK_GDT_H
#define KSK_GDT_H
#include <stdbool.h>
#include <stddef.h>

typedef enum {
  KSK_GDT_CODE_SEGMENT,
  KSK_GDT_DATA_SEGMENT
} ksk_gdt_entry_type_t;

typedef enum {
  KSK_GDT_GRANULARITY_1B,
  KSK_GDT_GRANULARITY_4KB
} ksk_gdt_entry_granularity_t;

/**
 * Not directly equivalent to a GDT entry on the system;
 * rather, this is intended to be an easier-to-understand abstraction.
 *
 * The ksk_gdt_*() calls convert this structure into a system-specific
 * representation.
 */
typedef struct {
  // The address where the segment begins.
  size_t base;
  // The maximum addressable unit. This value will be divided by the
  // given granularity. Ex. If using 4KB granularity, to cover the entire
  // 4GB address space, the value 0xffffffff would become 0xfffff;
  size_t max_addressable_unit;
  // The privilege ring for this memory.
  int ring;
  // Whether this entry is a data or code segment.
  ksk_gdt_entry_type_t type;
  // For data segments, determines if the segment grows down.
  // For code segments, determines if less-privileged code can
  // call the code in the segment.
  bool grows_down_or_conforming;
  // For data segments: whether the memory in the region can be written.
  // For code segments: whether the memory can be read.
  bool is_rw;
  // The granularity, either 1-byte, or 4KB.
  ksk_gdt_entry_granularity_t granularity;
  // Whether this is a 32-bit protected mode segment.
  bool is_32_bit_protected_mode;
} ksk_gdt_entry_t;

// Returns the size of the KSK-provided GDT table.
size_t ksk_gdt_get_table_size();

// Writes a GDT entry at the given index. Returns true if successful.
bool ksk_gdt_set_entry(size_t index, ksk_gdt_entry_t entry);

// Attempts to write all of the entries, starting at the given index.
// Returns the number of successfully-written entries.
size_t ksk_gdt_set_entries(size_t index, ksk_gdt_entry_t* entries, size_t size);

// Loads the KSK-provided GDT table, typically using the "LGDT" instruction.
void ksk_gdt_load();

#endif
