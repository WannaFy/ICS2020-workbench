#include "common.h"
#include <inttypes.h>

void mem_read(uintptr_t block_num, uint8_t *buf);
void mem_write(uintptr_t block_num, const uint8_t *buf);

static uint64_t cycle_cnt = 0;
//in fact we cana get a much larger cache to make it avilable.
static int CACHE_LINE_NUM;
static int CACHE_GROUP_NUM;

static Cache cache[MAX_GROUP_NUM][MAX_LINE_NUM];

void cycle_increase(int n) { cycle_cnt += n; }

// TODO: implement the following functions

uint32_t cache_read(uintptr_t addr) {
  //8,6,6先不对一般性做要求。

  //assign
  uint8_t block_addr = addr&63;
  uint8_t group_id   = (addr>>6)&63;
  uint8_t tag        = (addr>>12)&255;


  
}

void cache_write(uintptr_t addr, uint32_t data, uint32_t wmask) {
}


//init CACHE_GROUP_NUM=64;
//CACHE_LINE_NUM=8;
void init_cache(int total_size_width, int associativity_width) {

  CACHE_LINE_NUM=(1<<associativity_width);
  CACHE_GROUP_NUM=((1<<total_size_width)/BLOCK_SIZE)/CACHE_LINE_NUM;
  assert(CACHE_LINE_NUM*BLOCK_SIZE*CACHE_GROUP_NUM==(1<<total_size_width));
  assert(CACHE_GROUP_NUM<=MAX_GROUP_NUM);
  assert(CACHE_LINE_NUM<=MAX_LINE_NUM);
  for (int i=0;i<CACHE_GROUP_NUM;i++)
  {
    for (int j=0;j<CACHE_LINE_NUM;j++)
    {
      cache[i][j].dirty=false;
      cache[i][j].valid=false;
    }
  }
  printf("\033[44;37;5m init cache success!\033[0m\n")

}

void display_statistic(void) {
}