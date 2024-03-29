/*
** Função : Verifica se o número é automorfico
** Autor : Felipe Nóbrega de Almeida
** Data : 27/03/2024
** Observações:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int verificar_numero_automorfico(int n);
void remove_espacos(char* str);
int* lista_numeros_automorficos(int* contador, int inicio, int fim);

int main() {
  setlocale(LC_ALL, "Portugese");

  int* numeros_automorficos;
  int contador;
  int n;

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  numeros_automorficos = lista_numeros_automorficos(&contador, 2, n);
  printf("Números automórficos entre 2 e %d: ", n);
  for (int i = 0; i < contador; i++) {
    printf("%d ", numeros_automorficos[i]);
  }
  free(numeros_automorficos);

  printf("\n\n");

  numeros_automorficos = lista_numeros_automorficos(&contador, 2, 1000);
  printf("Números automórficos entre 2 e 1000: ");
  for (int i = 0; i < contador; i++) {
    printf("%d ", numeros_automorficos[i]);
  }
  free(numeros_automorficos);
  return 0;
}

int verificar_numero_automorfico(int n) {
  char numero[5];
  sprintf(numero, "%d", n);
  remove_espacos(numero);
  char quadrado[8];
  sprintf(quadrado, "%d", n * n);
  remove_espacos(quadrado);

  int numero_len = strlen(numero);
  int quadrado_len = strlen(quadrado);

  int i, j;
  for (i = numero_len - 1, j = quadrado_len - 1; i >= 0; i--, j--) {
    if (numero[i] != quadrado[j]) {
      return 0;
    }
  }
  return 1; 
}

void remove_espacos(char* str) {
    int i, j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int* lista_numeros_automorficos(int* contador, int inicio, int fim) {
  *contador = 0;
  int i, j;
  int lista[fim - inicio + 1];
  for (i = inicio, j = 0; i <= fim; i++) {
    if (verificar_numero_automorfico(i)) {
      (*contador)++;
      lista[j] = i;
      j++;
    }
  }
  int* lista_final = malloc(sizeof(int) * (*contador));
  if (lista_final == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  for (i = 0; i < (*contador); i++) {
    lista_final[i] = lista[i];
  }
  return lista_final;
}