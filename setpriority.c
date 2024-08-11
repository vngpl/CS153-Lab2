#include "types.h"
#include "stat.h"
#include "user.h"

int fib(int n) {
  return (n < 2) ? n : fib(n-1) + fib(n-2);
}

int
main(void) {
  int x = fib(22);
  // // p3 (parent) arrives
  // int x;
  // int pid1 = fork(); // p4 (child1) arrives
  // int pid2;

  // if (pid1) {
  //   // p3 (parent) executes below
  //   setpriority(10);
  //   pid2 = fork(); // p5 arrives
  //   // p3 (parent and child2) execute below
  //   x = fib(16);
  // }
  // if (!pid1) {
  //   // p4 (child1) executes below
  //   setpriority(1);
  //   x = fib(21);
  // }

  (void)x;
  // (void)pid2;

  // wait();
  exit();
}