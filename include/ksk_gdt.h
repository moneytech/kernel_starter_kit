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

typedef struct {
  size_t base;
  size_t limit;
  int ring;
  ksk_gdt_entry_type_t type;
  bool grows_down, conforming;
  bool is_read_only;
  ksk_gdt_entry_granularity_t granularity;
  bool is_32_bit_protected_mode;
} ksk_gdt_entry_t;

size_t ksk_gdt_get_table_size();

bool ksk_gdt_set_entry(size_t index, ksk_gdt_entry_t entry);

void ksk_gdt_load();

#endif
