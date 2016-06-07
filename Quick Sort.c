#include <stdio.h>
#include <conio.h>
#include <stdlib.h>//Necessário para as funções rand() e srand()
#include <time.h>//Necessário para função time()
#define MAX 10//Usar RAND_MAX no lugar para ir até 32762

//Função de Ordenação por Quick Sort
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
    srand(time(NULL));//Alimenta o vetor para que ele não apresente sempre os mesmos números
    for(i = 0; i < MAX; i++){
          vet[i] = rand()% 100;//Expressão para que seja criado números de 0 à 1000
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
 
