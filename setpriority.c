#include "types.h"
#include "stat.h"
#include "user.h"

int fib(int n) {
  return (n < 2) ? n : fib(n-1) + fib(n-2);
}

int
main(void) {
  int x;
  setpriority(4);
  int pid1 = fork();
  int pid2 = fork();
  int pid3 = fork();

  if (!pid1) {
    setpriority(1);
    x = fib(19);
  }
  else if (!pid2) {
    setpriority(4);
    x = fib(9);
  }
  else if (!pid3) {
    setpriority(7);
    x = fib(16);
  }
  else {
    x = fib(11);
  }

  (void)x;

  // wait();
  exit();
}