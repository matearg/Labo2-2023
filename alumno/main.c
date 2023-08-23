#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 3
#define ALUMNOS_ARCHI "alumnos.dat"

typedef struct {
  int id;
  char nombre[20];
  char apellido[20];
  char dni[10];
} stAlumno;

stAlumno cargarAlumno();
void mostrarAlumno(stAlumno a);
int cargarArrayAlumnos(stAlumno *a, int d);
void mostrarArrayAlumnos(stAlumno *a, int v);

int main() {
  stAlumno *arrAlumnos = (stAlumno *)malloc(sizeof(stAlumno) * DIM);
  int vAlumnos = 0;

  vAlumnos = cargarArrayAlumnos(arrAlumnos, DIM);
  system("clear");
  mostrarArrayAlumnos(arrAlumnos, vAlumnos);

  return 0;
}

stAlumno cargarAlumno() {
  stAlumno a;
  static int id = 0;

  id++;
  a.id = id;

  printf("Nombre......: ");
  fflush(stdin);
  scanf("%s", a.nombre);
  printf("Apellido....: ");
  fflush(stdin);
  scanf("%s", a.apellido);
  printf("DNI.........: ");
  fflush(stdin);
  scanf("%s", a.dni);

  return a;
}

void mostrarAlumno(stAlumno a) {
  printf("ID.........: %d\n", a.id);
  printf("Nombre.....: %s\n", a.nombre);
  printf("Apellido...: %s\n", a.apellido);
  printf("DNI........: %s\n", a.dni);
}

int cargarArrayAlumnos(stAlumno *a, int d) {
  int i = 0;
  for (i = 0; i < d; i++) {
    a[i] = cargarAlumno();
    printf("\n");
  }
  return i;
}

void mostrarArrayAlumnos(stAlumno *a, int v) {
  for (int i = 0; i < v; i++) {
    mostrarAlumno(a[i]);
    printf("\n");
  }
}
