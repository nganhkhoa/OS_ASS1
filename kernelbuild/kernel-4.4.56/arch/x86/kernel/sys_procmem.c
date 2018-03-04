#include <linux/linkage.h>
#include <linux/sched.h>


struct proc_segs {
      unsigned long mssv;
      // code
      unsigned long start_code;
      unsigned long end_code;
      // data
      unsigned long start_data;
      unsigned long end_data;
      // heap
      unsigned long start_heap;
      unsigned long end_heap;
      // stack
      unsigned long start_stack;
      unsigned long end_stack;
};

asmlinkage long sys_procmem(int pid, struct proc_segs* info) {
      // TODO:
}
