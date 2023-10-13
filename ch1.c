#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

const uint32_t ArraySize = 17;

void bubble_sort(uint32_t array[]);
void merge_sort(uint32_t array[], uint32_t left, uint32_t right);
void quick_sort(uint32_t array[], uint32_t low, uint32_t high);

void merge(uint32_t arr[], uint32_t l, uint32_t m, uint32_t r);

void swap(uint32_t array[], uint32_t a, uint32_t b);
void print_array(uint32_t array[]);
bool is_sorted(uint32_t array[]);

int main(int argc, char* argv[argc + 1]) {
  srand(0);

  uint32_t array[ArraySize] = { 66, 251, 159, 224, 89, 129, 90, 129, 102, 161, 14, 92, 78, 180, 218, 236, 47 };
  // for (size_t i = 0; i < ArraySize; ++i) {
  //   array[i] = rand();
  // }
  print_array(array);


  // bubble_sort(array);
  merge_sort(array, 0, ArraySize - 1);
  print_array(array);

  if (is_sorted(array)) {
    printf("sorted\n");
  } else {
    printf("not sorted\n");
  }

  return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////
/// Bubble Sort

void bubble_sort(uint32_t array[]) {
  uint32_t it = 0;
  bool swapped;
  for (int i = 0; i < ArraySize - 1; ++i) {
    swapped = false;
    for (int j = 0; j < ArraySize - i - 1; ++j) {
      it++;
      if (array[j] > array[j + 1]) {
        swap(array, j, j + 1);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }

  printf("it: %d\n", it);
}

/////////////////////////////////////////////////////////////////////
/// Merge Sort

void merge_sort(uint32_t array[], uint32_t left, uint32_t right) {
  if (left < right) {
    uint32_t middle = left + (right - left) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    merge(array, left, middle, right);
  }
}

void merge(uint32_t array[], uint32_t l, uint32_t m, uint32_t r)
{
  uint32_t n1 = m - l + 1;
  uint32_t n2 = r - m;

  uint32_t L[n1], R[n2];

  for (size_t i = 0; i < n1; i++) {
    L[i] = array[l + i];
  }

  for (size_t j = 0; j < n2; j++) {
    R[j] = array[m + 1 + j];
  }

  uint32_t i = 0;
  uint32_t j = 0;
  uint32_t k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k++] = L[i++];
    } else {
      array[k++] = R[j++];
    }
  }

  while (i < n1) {
    array[k++] = L[i++];
  }

  while (j < n2) {
    array[k++] = R[j++];
  }
}

/////////////////////////////////////////////////////////////////////
/// Quicksort

void quick_sort(uint32_t array[], uint32_t low, uint32_t high) {
  //
}

/////////////////////////////////////////////////////////////////////
/// Helpers

void swap(uint32_t array[], uint32_t a, uint32_t b) {
  array[a] += array[b];
  array[b] = array[a] - array[b];
  array[a] -= array[b];
}

void print_array(uint32_t array[]) {
  for (size_t i = 0; i < ArraySize; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

bool is_sorted(uint32_t array[]) {
  for (size_t i = 1; i < ArraySize; ++i) {
    if (array[i - 1] > array[i]) {
      return false;
    }
  }
  return true;
}

