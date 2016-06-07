#include <stdio.h>
#include <conio.h>
#include <stdlib.h>//Necess�rio para as fun��es rand() e srand()
#include <time.h>//Necess�rio para fun��o time()
#define MAX 10//Usar RAND_MAX no lugar para ir at� 32762

//Fun��o de Ordena��o por Quick Sort
void quick_sort(int *a, int esq, int dir) {
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j) {
        while(a[i] < x) {
            i++;
        }
        while(a[j] > x) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quick_sort(a, esq, j);
    }
    if(i < dir) {
        quick_sort(a, i, dir);
    }
}
 
int main(){
    int i, vet[MAX];
    srand(time(NULL));//Alimenta o vetor para que ele n�o apresente sempre os mesmos n�meros
    for(i = 0; i < MAX; i++){
          vet[i] = rand()% 100;//Express�o para que seja criado n�meros de 0 � 1000
    }
    
    //Imprime os valores desordenados
    printf("\n\nValores Desordenados\n");
    for(i = 0; i < MAX; i++){
          printf("%d\n", vet[i]);
    }
    
    //Ordena os valores
    quick_sort(vet, 0, MAX - 1);
 
    //Imprime os valores ordenados
    printf("\n\nValores ordenados\n");
    for(i = 0; i < MAX; i++){
          printf("%d\n", vet[i]);
    }
 
    system("pause");
    return 0;
}
 
