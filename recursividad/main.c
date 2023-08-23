#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int num);
int producto(int a, int b);
int potencia(int base, int exponente);
long fibonacci(int num);
int capicuaArray(int *a, int i, int j);
int cargarArray(int *a, int d);
void mostrarArray(int *a, int v, int i);

int main() {

  srand(time(NULL));
  int a = rand() % 11;
  int b = rand() % 11;

  printf("Factorial de %d = %d\n", a, factorial(a));
  printf("Producto %d * %d = %d\n", a, b, producto(a, b));

  printf("%d elevado a %d = %d\n", a, b, potencia(a, b));

  printf("Fibonacci:\n");
  for (int c = 0; c <= rand() % 101; c++) {
    printf("%ld ", fibonacci(c));
  }
  printf("\n");

  const int DIM = 5;

  int *d = (int *)malloc(sizeof(int) * DIM);
  int validos = cargarArray(d, DIM);
  mostrarArray(d, validos, 0);
  printf("\n");
  printf("Capicua: %d\n", capicuaArray(d, 0, validos - 1));

  return 0;
}

int factorial(int num) {
  int rta = 1;
  return (num > 0) ? rta = num * factorial(num - 1) : rta;
}

int producto(int a, int b) {
  return (b >= 1) ? (a = a + producto(a, b - 1)) : 0;
}

int potencia(int base, int exponente) {
  return (exponente > 0) ? base * potencia(base, exponente - 1) : 1;
}

long fibonacci(int num) {
  return (num > 1) ? (fibonacci(num - 1) + fibonacci(num - 2)) : num;
}

int cargarArray(int *a, int d) {
  int i = 0;
  for (i = 0; i < d; i++) {
    printf("Introducir num -> ");
    scanf("%d", &a[i]);
  }
  return i;
}

int capicuaArray(int *a, int i, int j) {
  int rta;
  if (i == j || i - 1 == j) {
    rta = 1;
  } else {
    if (a[i] == a[j]) {
      rta = capicuaArray(a, i + 1, j - 1);
    } else {
      rta = 0;
    }
  }
  return rta;
}

void mostrarArray(int *a, int v, int i) {
  if (i < v) {
    printf("%d ", a[i]);
    mostrarArray(a, v, i + 1);
  }
}
