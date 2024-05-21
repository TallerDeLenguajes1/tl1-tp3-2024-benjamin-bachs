#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos //El tamaño de este arreglo depende de la variable
} Cliente;

void cargarProductos(Producto *productos, int M);
void cargarNombre(char ** nombreCliente);
void cargarClientes(Cliente *clientes, int N);
int calcularProducto(Producto producto);
void mostrarProductos(Producto *productos, int M);
void mostrarClientes(Cliente *clientes, int N);

int main (void){
    int N;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &N);
    Cliente *clientes = (Cliente *) malloc(N * sizeof(Cliente));
    cargarClientes(clientes, N);
    mostrarClientes(clientes, N);
}

void cargarNombre(char ** nombreCliente){
    char *Buff; //variable auxiliar
    Buff = (char *) malloc(100*sizeof(char));
    printf("Ingrese el nombre del cliente: ");
    fflush(stdin);
    gets(Buff);
    *nombreCliente = (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(*nombreCliente,Buff);
    free(Buff);
}

void cargarProductos(Producto *productos, int M){
    for (int i = 0; i < M; i++)
    {
        productos[i].ProductoID = i;
        productos[i].Cantidad = rand()%10+1;
        productos[i].TipoProducto = TiposProductos[rand()%5];
        productos[i].PrecioUnitario = rand()%91+10;
    }
    
}

void cargarClientes(Cliente *clientes, int N){
    for (int i = 0; i < N; i++)
    {
        printf("\nCliente %d\n", i+1);
        clientes[i].ClienteID = i;
        cargarNombre(&(clientes[i].NombreCliente));
        clientes[i].CantidadProductosAPedir = rand()%4+1;
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        cargarProductos(clientes[i].Productos, clientes[i].CantidadProductosAPedir);
    }
}

int calcularProducto(Producto producto){
    return producto.Cantidad * producto.PrecioUnitario;
}

void mostrarProductos(Producto *productos, int M){
    int total = 0;
    for (int i = 0; i < M; i++)
    {
        printf("Producto %d\n",productos[i].ProductoID+1);
        printf("Cantidad: %d\n",productos[i].Cantidad);
        printf("Tipo: %s\n",productos[i].TipoProducto);
        printf("Precio: %f\n\n",productos[i].PrecioUnitario);
        total += calcularProducto(productos[i]);
    }
    printf("El total del cliente es: %d\n", total);
    
}

void mostrarClientes(Cliente *clientes, int N){
    for (int i = 0; i < N; i++)
    {
        printf("\nCliente %d\n", clientes[i].ClienteID + 1);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad productos %d\n\n", clientes[i].CantidadProductosAPedir);
        mostrarProductos(clientes[i].Productos, clientes[i].CantidadProductosAPedir);
    }
}