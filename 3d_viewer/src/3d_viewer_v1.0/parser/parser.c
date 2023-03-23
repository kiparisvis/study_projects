#include "parser.h"

#include <math.h>

int parse(char *filename, data_t *data) {
  FILE *file = fopen(filename, "r");
  if (!file) return ERROR;
  get_size(file, data);
  data->polygons = (int *)my_calloc(data->polygon_size, sizeof(int));
  data->vertex = (double *)my_calloc(data->vertex_size, sizeof(double));
  rewind(file);
  fill_data(file, data);
  fclose(file);
  return OK;
}

void get_size(FILE *file, data_t *data) {
  char *line = NULL, *tmp = NULL;
  size_t len = 0;
  data->polygon_size = 0;
  data->vertex_size = 0;
  while (getline(&line, &len, file) > 0) {
    if (line[0] == 'v' && line[1] == ' ') {
      data->vertex_size += 3;
    }
    if (line[0] == 'f') {
      tmp = line;
      strtok(tmp, " ");
      tmp = NULL;
      while ((tmp = strtok(NULL, " ")) != NULL) {
        if (isdigit(tmp[0])) data->polygon_size += 2;
      }
    }
  }
  if (line) free(line);
}

void *my_calloc(size_t number, size_t size) {
  void *result = calloc(number, size);
  CHECKMALLOC(result);
  return result;
}

void fill_data(FILE *file, data_t *data) {
  char *line = NULL;
  char *tmp = NULL;
  size_t len = 0;
  int j = 0;
  for (int i = 0; getline(&line, &len, file) != -1;) {
    if (line[0] == 'v' && line[1] == ' ') {
      strtok(line, " ");
      data->vertex[i] = atof(strtok(NULL, " "));
      data->vertex[i + 1] = atof(strtok(NULL, " "));
      data->vertex[i + 2] = atof(strtok(NULL, " "));
      i += 3;
    }
    if (line[0] == 'f') {
      tmp = line;
      strtok(tmp, " ");
      tmp = NULL;
      int i = 0, first = 0;
      while ((tmp = strtok(NULL, " ")) != NULL) {
        if (isdigit(tmp[0])) {
          if (i == 0) {
            data->polygons[j] = atoi(tmp) - 1;
            first = data->polygons[j];
            j++;
            i++;
          } else {
            data->polygons[j] = atoi(tmp) - 1;
            data->polygons[j + 1] = data->polygons[j];
            j += 2;
          }
        }
      }
      data->polygons[j] = first;
      j++;
    }
  }
  if (line) free(line);
}

void rotation_x(data_t *data, double angle) {
  angle = angle * M_PI / 180;
  for (unsigned int i = 1; i < data->vertex_size; i += 3) {
    double temp_y = data->vertex[i];
    double temp_z = data->vertex[i + 1];
    data->vertex[i] = cos(angle) * temp_y - sin(angle) * temp_z;
    data->vertex[i + 1] = sin(angle) * temp_y + cos(angle) * temp_z;
  }
}

void rotation_y(data_t *data, double angle) {
  angle = angle * M_PI / 180;
  for (unsigned int i = 0; i < data->vertex_size; i += 3) {
    double temp_x = data->vertex[i];
    double temp_z = data->vertex[i + 2];
    data->vertex[i] = cos(angle) * temp_x + sin(angle) * temp_z;
    data->vertex[i + 2] = sin(angle) * -temp_x + cos(angle) * temp_z;
  }
}

void rotation_z(data_t *data, double angle) {
  angle = angle * M_PI / 180;
  for (unsigned int i = 0; i < data->vertex_size; i += 3) {
    double temp_x = data->vertex[i];
    double temp_y = data->vertex[i + 1];
    data->vertex[i] = cos(angle) * temp_x - sin(angle) * temp_y;
    data->vertex[i + 1] = sin(angle) * temp_x + cos(angle) * temp_y;
  }
}

void scale(data_t *data, double value) {
  for (unsigned int i = 0; i < data->vertex_size; i++) {
    data->vertex[i] *= value;
  }
}

void move_x(data_t *data, double value) {
  for (unsigned int i = 0; i < data->vertex_size; i += 3) {
    data->vertex[i] += value;
  }
}

void move_y(data_t *data, double value) {
  for (unsigned int i = 1; i < data->vertex_size; i += 3) {
    data->vertex[i] += value;
  }
}

void move_z(data_t *data, double value) {
  for (unsigned int i = 2; i < data->vertex_size; i += 3) {
    data->vertex[i] += value;
  }
}
