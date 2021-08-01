#include <stdio.h>
#include <stdlib.h>
int binary_search(int* array, int value, int low, int high) {
  int mid;
  if (high < low) {
    return -1;
  } else {
    mid = (low + high) / 2;
    if (array[mid] > value) {
      return binary_search(array, value, low, mid - 1);
    } else if (array[mid] < value) {
      return binary_search(array, value, mid + 1, high);
    } else {
      return mid;
    }
  }
}
main() {
  freopen("in7.in", "r", stdin);
  freopen("out7.txt", "w", stdout);
  int i, value, answer;
  const int n = 10000;
  int array[n];
  for (i = 0; i < n; i++) {
    scanf("%d", array + i);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &value);
    answer = binary_search(array, value, 0, n - 1);
    printf("%d\n", answer);
  }
}