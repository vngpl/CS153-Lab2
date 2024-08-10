#include "types.h"
#include "stat.h"
#include "user.h"

// int fib(int n) {
//   return (n < 2) ? n : fib(n-1) + fib(n-2);
// }

int
main(void) {
  int pid = fork();

  if (!pid) {
    printf(1, "in child\n");
    // int result = fib(45);
    // printf(1, "%d\n", result);
  }
  if (pid) {
    wait();
    printf(1, "\nin parent\n");
  }

  getprocinfo();
  exit();
}