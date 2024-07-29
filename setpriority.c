#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  setpriority(5);
  setpriority(0);
  setpriority(11);
  exit();
}