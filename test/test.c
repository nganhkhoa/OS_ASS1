#include <procmem.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>

int main() {
      pid_t mypid = getpid();
      printf("PID: %d\n", mypid);
      struct proc_segs info;

      if (procmem(mypid, &info) == 0) {
            printf("Student ID: %lu\n", info.mssv);
            printf("Code segment: %lx-%lx\n", info.start_code, info.end_code);
            printf("Data segment: %lx-%lx\n", info.start_data, info.end_data);
            printf("Heap segment: %lx-%lx\n", info.start_heap, info.end_heap);
            printf("Start stack: %lx\n", info.start_stack);
      }
      else {
            printf("Cannot get infomation from the process id %d\n", mypid);
      }

      sleep(100);
      return 0;
}
