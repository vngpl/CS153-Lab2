#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  int i, pid;
  volatile int sum = 0;
  int priorities[] = {1, 3, 5, 7, 10};

  for (i = 0; i < 5; i++) {
    pid = fork();
    if (!pid) {
      setpriority(priorities[i]);
      for (i = 0; i < 10000000; i++) {
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