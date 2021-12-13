#include "print_dan.h"
extern int globvar;
static int globvar2 = 8;
void print_dan(int var, pid_t pid)
{
register int quick;
int *a;
int i, n;
quick = 20;
globvar2++;
printf("pid = %ld, glob = %d, glob2 = %d, var = %d, register = %d\n", (long)getpid(), globvar, globvar2, var,quick);

  system("chcp 1251");
  system("cls");
  printf("Введите размер массива: ");
  scanf("%d", &n);
  // Выделение памяти
  a = (int*)malloc(n * sizeof(int));
  // Ввод элементов массива
  for (i = 0; i<n; i++)
  {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
  }
  // Вывод элементов массива
  for (i = 0; i<n; i++)
    printf("%d ", a[i]);
  free(a);
  getchar();   getchar();

}