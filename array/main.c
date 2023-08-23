#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARCHI_ARRAY "array.dat"
#define ARR_DIM 10

int cargarArray(int *a, int d);
void mostrarArray(int *a, int v);
void array2Archi(int *a, int v, char *nombreArchivo);
int contarRegistros(char *nombreArchivo);
void mostrarArrayArchi(char *nombreArchivo);

int main() {
  printf("Hello, World!\n");
  int *array = (int *)malloc(sizeof(int) * ARR_DIM);
  int validos = 0;

  validos = cargarArray(array, ARR_DIM);
  printf("Array\n");
  mostrarArray(array, validos);

  array2Archi(array, validos, ARCHI_ARRAY);
  printf("Archivo\n");
  mostrarArrayArchi(ARCHI_ARRAY);

  return 0;
}

int cargarArray(int *a, int d) {
  srand(time(NULL));
  int i = 0;
  for (i = 0; i < d; i++) {
    a[i] = rand() % 101;
  }
  return i;
}

void mostrarArray(int *a, int v) {
  for (int i = 0; i < v; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void array2Archi(int *a, int v, char *nombreArchivo) {
  FILE *archi = fopen(nombreArchivo, "ab");

  if (archi) {
    fwrite(a, sizeof(int), v, archi);
    fclose(archi);
  }
}

int contarRegistros(char *nombreArchivo) {
  FILE *archi = fopen(nombreArchivo, "rb");
  int cant = 0;

  if (archi) {
    fseek(archi, 0, SEEK_END);
    cant = ftell(archi) / sizeof(int);
    fclose(archi);
  }

  return cant;
}

void mostrarArrayArchi(char *nombreArchivo) {
  FILE *archi = fopen(nombreArchivo, "rb");
  int num;
  if (archi) {
    while (fread(&num, sizeof(int), 1, archi)) {
      printf("%d ", num);
    }
    fclose(archi);
  }
}
