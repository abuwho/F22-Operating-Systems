#include <stdio.h>

long long tribonacci(int n) {
  if (n == 0) return 0;
  if (n < 3) return 1;

  long long x = 0, y = 1, z = 1;
  long long ans;
  for (int i = 3; i <= n; i++) {
    ans = x + y + z;
    x = y;
    y = z;
    z = ans;
  }

  return ans;
}

int main(void)
{

    printf("%ld\n", tribonacci(4));
    printf("%ld", tribonacci(36));

    return 0;
}