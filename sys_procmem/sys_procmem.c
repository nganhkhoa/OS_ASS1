#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/mm.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("1611617");

static int pid_mem = 1;

static int __init mm_exp_load(void) {
      struct task_struct* task = NULL;
      struct mm_struct* mm = NULL;
      int match = 0;

      printk("Process id is inspected %d.\n", pid_mem);

      for_each_process(task) {
            if (task->pid == pid_mem) {
                  match = 1;
                  break;
            }
      }

      if (match != 1) {
            printk("PID not found\n");
            return -1;
      }

      mm = task->mm;

      printk("Code  start: %lX\n", mm->start_code);
      printk("Code  end  : %lX\n", mm->end_code);

      printk("Data  start: %lX\n", mm->start_data);
      printk("Data  end  : %lX\n", mm->end_data);

      printk("Heap  start: %lX\n", mm->start_brk);
      printk("Heap  end  : %lX\n", mm->brk);

      printk("Stack start: %lX\n", mm->start_stack);
      // printk("Stack end  : %lX\n", mm->stack_end);
      return 0;
}

static void __exit mm_exp_unload(void) {
      printk("\nPrint segment information module exiting.\n");
}

module_init(mm_exp_load);
module_exit(mm_exp_unload);
module_param(pid_mem, int, 0);
