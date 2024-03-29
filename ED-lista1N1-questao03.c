/*
** Função : Recebe parametro n e retorna o resultado do fatorial duplo
** Autor : Felipe Nóbrega de Almeida
** Data : 27/03/2024
** Observações:
*/

#include <stdio.h>
#include <locale.h>

int amigaveis(int n1, int n2);
void verificarParesAmigaveis(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  int n;
  printf("Digite um número: ");
  scanf("%d", &n);
  printf("\n");
  printf("Lista de pares de números amigáveis até %d:\n", n);
  verificarParesAmigaveis(n);

  return 0;
}

int amigaveis(int n1, int n2) {
  int i, soma1 = 0, soma2 = 0;

  for (i = 1; i < n1; i++) {
    if (n1 % i == 0) {
      soma1 += i;
    }
  }

  for (i = 1; i < n2; i++) {
    if (n2 % i == 0) {
      soma2 += i;
    }
  }

  if (soma1 == n2 && soma2 == n1) {
    return 1;
  }
  return 0;
}

void verificarParesAmigaveis(int n) {
  int i, j;
  for (i = 220; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (amigaveis(i, j)) {
        printf("Os números %d e %d são amigáveis\n", i, j);
      }
    }
  }
}