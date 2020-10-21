#include "asm.h"
#include <string.h>

int64_t asm_add(int64_t a, int64_t b) {
  asm("addq %0, %1\n\t"
  :"+r"(a)
  :"r"(b)

     );

  return a;
  
}

int asm_popcnt(uint64_t x) {
  int s = 0;
  for (int i = 0; i < 64; i++) {
    if ((x >> i) & 1) s++;
  }
  return s;
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  return memcpy(dest, src, n);
}

int asm_setjmp(asm_jmp_buf env) {
  return setjmp(env);
}

void asm_longjmp(asm_jmp_buf env, int val) {
  longjmp(env, val);
}
