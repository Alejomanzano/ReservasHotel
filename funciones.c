#include <stdio.h>
#include "funciones.h"
#include <string.h>

void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char tamano[10];
    printf("Ingrese el tamaño de la habitación (simple, doble o triple): ");
    scanf("%s", tamano);
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tamano) == 0) {
            printf("Habitación %s en el hotel %s, precio: %.2f\n", habitaciones[i][0], habitaciones[i][2], precios[i]);
        }
    }
    printf("Ingrese el número de habitación que desea: ");
    scanf("%d", numHabitacion);
}

void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char hotel[40];
    printf("Ingrese el nombre del hotel: ");
    scanf("%s", hotel);
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], hotel) == 0) {
            printf("Habitación %s, tipo: %s, precio: %.2f\n", habitaciones[i][0], habitaciones[i][1], precios[i]);
        }
    }
    printf("Ingrese el número de habitación que desea: ");
    scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    printf("Ingrese su cédula: ");
    scanf("%s", cedula);
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], "") == 0) {
            strcpy(clientes[i][0], "Cliente");
            strcpy(clientes[i][1], cedula);
            for (int j = 0; j < 10; j++) {
                if (reservas[j][3] == 0) {
                    reservas[j][0] = numHabitacion;
                    reservas[j][1] = i;
                    reservas[j][2] = 1;
                    reservas[j][3] = 1;
                    printf("Reserva realizada con éxito\n");
                    return;
                }
            }
        }
    }
    printf("No hay cupo disponible para realizar la reserva\n");
}

void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    printf("Ingrese su cédula: ");
    scanf("%s", cedula);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (strcmp(clientes[j][1], cedula) == 0 && reservas[i][1] == j && reservas[i][3] == 1) {
                *numReserva = i;
                return;
            }
        }
    }
    printf("No se encontró la reserva\n");
}

void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    printf("Reserva número %d\n", numReserva);
    printf("Habitación número %d\n", reservas[numReserva][0]);
    printf("Precio: %.2f\n", precios[reservas[numReserva][0] - 1]);
}

void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    printf("Pago realizado con éxito\n");
    reservas[numReserva][2] = 0;
    reservas[numReserva][3] = 0;
}