// #pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0
#define ERROR 1
#define CHECKMALLOC(x)        \
  if ((x) == NULL) {          \
    perror("ALLOC FAILED: "); \
    abort();                  \
  }

typedef struct Data {
  double *vertex;
  unsigned int vertex_size;
  int *polygons;
  unsigned int polygon_size;
} data_t;

int parse(char *filename, data_t *data);
void get_size(FILE *file, data_t *data);
void *my_calloc(size_t number, size_t size);
void fill_data(FILE *file, data_t *data);
void rotation_x(data_t *data, double angle);
void rotation_y(data_t *data, double angle);
void rotation_z(data_t *data, double angle);
void scale(data_t *data, double value);
void move_x(data_t *data, double value);
void move_y(data_t *data, double value);
void move_z(data_t *data, double value);
