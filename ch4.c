#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>

const size_t SIZE = 16;

size_t find(size_t n, size_t parent[static n], size_t i);
void find_replace(size_t n, size_t parent[static n], size_t i, size_t v);
size_t find_compress(size_t n, size_t parent[static n], size_t i);
void make_union(size_t n, size_t parent[static n], size_t i, size_t j);

void print(size_t n, size_t parent[static n]);

int main(int argc, char* argv[argc + 1]) {
  size_t parent[SIZE];
  for (size_t i = 0; i < SIZE; ++i) {
    parent[i] = i;
  }

  printf("Initial set:\n");
  print(SIZE, parent);

  find_replace(SIZE, parent, 7, 9);
  print(SIZE, parent);

  // TODO: add normal tests

  return EXIT_SUCCESS;
}

size_t find(size_t n, size_t parent[static n], size_t i) {
  if (i >= n) {
    return SIZE_MAX;
  }

  if (parent[i] == i) {
    return i;
  } else {
    return find(n, parent, parent[i]);
  }
}

void find_replace(size_t n, size_t parent[static n], size_t i, size_t v) {
  if (i >= n) {
    return;
  }

  size_t old_parent = parent[i];
  if (parent[i] == i) {
    parent[i] = v;
  } else {
    parent[i] = v;
    find_replace(n, parent, old_parent, v);
  }
}

size_t find_compress(size_t n, size_t parent[static n], size_t i) {
  if (i >= n) {
    return SIZE_MAX;
  }

  if (parent[i] != i) {
    parent[i] = find_compress(n, parent, parent[i]);
  }

  return parent[i];
}

void make_union(size_t n, size_t parent[static n], size_t i, size_t j) {
  if (i >= n || j >= n) {
    return;
  }

  find_replace(n, parent, i, find_compress(n, parent, j));
}

void print(size_t n, size_t parent[static n]) {
  for (size_t i = 0; i < n; ++i) {
    printf("%zu ", parent[i]);
  }
  printf("\n");
}

