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
      // unsigned long end_stack;
};

asmlinkage long sys_procmem(int pid, struct proc_segs* info) {
      struct task_struct* ts = NULL;
      struct mm_struct* mm = NULL;

      // my student info
      info->mssv = 1611617;

      // check if there is a task of pid
      for_each_process(ts) {
            if (ts->pid == pid) {
                  mm = ts->mm;
                  break;
            }
      }

      if (mm == NULL) return -1;

      // OK, there is a process

      // code
      info->start_code = mm->start_code;
      info->end_code = mm->end_code;
      // data
      info->start_data = mm->start_data;
      info->end_data = mm->end_data;
      // heap
      info->start_heap = mm->start_brk;
      info->end_heap = mm->brk;
      // stack
      info->start_stack = mm->start_stack;
      // info->end_start = mm->stack_end;

      return 0;
}
