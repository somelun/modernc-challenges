#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

const uint32_t ArraySize = 17;

void bubble_sort(uint32_t array[]);
void merge_sort(uint32_t array[], uint32_t left, uint32_t right);
void quick_sort(uint32_t array[], uint32_t low, uint32_t high);

void merge(uint32_t array[], uint32_t left, uint32_t middle, uint32_t right);
uint32_t partition(uint32_t array[], uint32_t low, uint32_t high);

void swap(uint32_t* a, uint32_t* b);
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
  // merge_sort(array, 0, ArraySize - 1);
  quick_sort(array, 0, ArraySize - 1);
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
        swap(&array[j], &array[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
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
  if (low < high) {
    uint32_t pivot = partition(array, low, high);

    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
  }
}

uint32_t partition(uint32_t array[], uint32_t low, uint32_t high) {
  uint32_t pivot = array[high];

  uint32_t i = (low - 1);

  for (uint32_t j = low; j <= high - 1; ++j) {
    if (array[j] < pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

/////////////////////////////////////////////////////////////////////
/// Helpers

void swap(uint32_t* a, uint32_t* b) {
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
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

