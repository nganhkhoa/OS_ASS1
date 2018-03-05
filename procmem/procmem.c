#include "procmem.h"
#include <linux/kernel.h>
#include <sys/syscall.h>

long procmem(pid_t pid, struct proc_segs* info) {
      if (pid <= 0)
            return -1;
      return syscall(546, 1, info);
}
