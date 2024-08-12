#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  volatile int i, pid;
  volatile int sum = 0;

  pid = fork();
  if (!pid) {
    for (i = 0; i < 10000000; i++) {
      sum += i;
    }
  }
  if (pid) {
    for (i = 0; i < 10000000; i++) {
      sum += i;
    }
  }

  wait();
  exit();
}