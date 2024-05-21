#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

void cargarNombreApellido(char ** nombreApellido);
void mostrarNombreApellido(char ** nombreApellido);
void liberarNombreApellido(char ** nombreApellido);

int main (void){
    char * nombresApellidos[N][2];
    for (int i = 0; i < N; i++)
    {
        printf("\nDato %d\n", i+1);
        cargarNombreApellido(nombresApellidos[i]);
    }
    for (int i = 0; i < N; i++)
    {
        printf("\nDato %d\n", i+1);
        mostrarNombreApellido(nombresApellidos[i]);
    }
    for (int i = 0; i < N; i++)
    {
        liberarNombreApellido(nombresApellidos[i]);
    }
    
    return 0;
}

void cargarNombreApellido(char ** nombreApellido){
    char *Buff; //variable auxiliar
    Buff = (char *) malloc(100*sizeof(char));
    printf("Ingrese sus nombres: ");
    gets(Buff);
    nombreApellido[0] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(nombreApellido[0],Buff);
    printf("Ingrese sus Apellidos: ");
    gets(Buff);
    nombreApellido[1] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(nombreApellido[1],Buff);
    free(Buff);
}

void mostrarNombreApellido(char ** nombreApellido){
    puts (nombreApellido[0]);
    puts (nombreApellido[1]);
}

void liberarNombreApellido(char ** nombreApellido){
    free(nombreApellido[0]);
    free(nombreApellido[1]);
}