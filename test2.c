#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  volatile int i, pid;
  volatile int sum = 0;
  volatile int priorities[] = {1, 10, 10};

  for (i = 0; i < 3; i++) {
    pid = fork();
    if (!pid) {
      setpriority(priorities[i]);
      for (i = 0; i < 10000; i++) {
        sum += i;
      }
      exit();
    }
  }

  if (pid) {
    for (i = 0; i < 5; i++) {
      wait();
    }
  }

  exit();
}