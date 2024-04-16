#include<stdio.h>
#include<stdlib.h>
#define ANIOS 5
#define MESES 12


void cargar(int matriz[][MESES]);
void mostrar(int matriz[][MESES]);
void promedio (int matriz[][MESES]);
void minimo(int matriz[][MESES]);
void maximo(int matriz[][MESES]);

int main(void){
    int matriz[ANIOS][MESES];
    cargar(matriz);
    mostrar(matriz);
    promedio(matriz);
    maximo(matriz);
    minimo(matriz);
    getchar();
}

void cargar(int matriz[][MESES]){
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            matriz[i][j] = (rand()+1)%40000+10000;
        }
    }
}

void mostrar(int matriz[][MESES]){
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedio(int matriz[][MESES]){
    for (int i = 0; i < ANIOS; i++)
    {
        float acumulador = 0;
        for (int j = 0; j < MESES; j++)
        {
            acumulador += matriz[i][j];
        }
        printf("promedio %d: %f", i+1, acumulador/MESES);
        printf("\n");
    }
}

void maximo(int matriz[][MESES]){
    int mes = 0;
    int anio = 0;
    int maximo = 0;
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            int valor = matriz[i][j];
            if(maximo < valor){
                maximo = valor;
                mes = j+1;
                anio = i+1;
            }
        }
    }
    printf("maximo: %d, año: %d, mes: %d\n", maximo, anio, mes);
}

void minimo(int matriz[][MESES]){
    int mes = 0;
    int anio = 0;
    int minimo = 100000;
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            int valor = matriz[i][j];
            if(minimo > valor){
                minimo = valor;
                mes = j+1;
                anio = i+1;
            }
        }
    }
    printf("maximo: %d, año: %d, mes: %d\n", minimo, anio, mes);
}

