#include <stdlib.h>
#include <stdio.h>
#include "sala.h"


int* asientos = NULL;
int capacidad = 0;   

// 0 = vacío

int crea_sala(int cap) {
    capacidad = cap;
    asientos = malloc(sizeof(int) * capacidad);
    if(asientos == NULL) return -1;

    for (int i = 0; i < capacidad; i++) {
        asientos[i] = 0;
    }
    return capacidad;
}

int capacidad_sala() {
    return capacidad;
}

int reserva_asiento(int id_persona) {
    for (int i = 0; i < capacidad; i++) {
        if (asientos[i] == 0) {
            asientos[i] = id_persona;
            return i + 1;
        }
    }
    return -1;
}

int libera_asiento(int id_asiento) {
    if (id_asiento < 1 || id_asiento > capacidad) return -1;
    int i = id_asiento - 1;
    if (asientos[i] != 0) {
        int id = asientos[i];
        asientos[i] = 0;
        return id;
    }
    return -1;
}

int estado_asiento(int id_asiento) {
    if (id_asiento < 1 || id_asiento > capacidad) return -1;
    int i = id_asiento - 1;
    if (asientos[i] != 0) {
        return asientos[i];
    }
    return 0;
}

int asientos_libres() {
    int count = 0;
    for (int i = 0; i < capacidad; i++) {
        if (asientos[i] == 0) count++;
    }
    return count;
}

int asientos_ocupados() {
    return capacidad - asientos_libres();
}

int elimina_sala() {
    if (asientos == NULL) return -1;
    
    free(asientos);
    asientos = NULL;
    capacidad = 0;
    return 0;
}

// funciones tests extra

int estado_sala()
{
   if (capacidad == 0){
   	printf("Sala vacia\n");
   	return -1;
   }
   
   int libres = 0;
   int ocupados = 0;
   for(int i=0; i < capacidad; i++){

   	if(asientos[i] == 0){
   		libres++;
   		printf("ID: %d Libre, ", i+1);
   	} else {
   		ocupados++;
   		printf("ID: %d Ocupado\n", i+1);
   	}
   }
   
   printf("Actualmente hay.. %d asientos vacios y %d ocupados\n", libres, ocupados);
   return 0;
}

int sentarse(int id)
{
    for(int i=0; i < capacidad; i++){
        if(asientos[i] == 0){
            asientos[i] = id;
            printf("Su asiento es el Nº%d\n", i+1);
            return 0;
        }
    }
    printf("La sala está llena");
    return -1;
}

int levantarse(int id)
{
    for(int i=0; i < capacidad; i++){
        if(asientos[i] == id){
            asientos[i] = 0;
            printf("La persona %d se ha levantado del asiento %d\n", id, i+1);
            return 0;
        }
    }
    printf("No se ha encontrado un asiento con ID: %d", id);
    return -1;
}

int reserva_multiple(int npersonas, int* lista_id)
{
    int libres = asientos_libres();
    if (libres < npersonas){
        printf("No hay asientos suficientes para %d personas\n", npersonas);
        return -1;
    }

    for(int i=0; i < npersonas; i++){
        int encontrado = 0;
        for(int j=0; j < capacidad; j++){
            if (asientos[j] == 0 && encontrado == 0){
                asientos[j] = lista_id[i];
                encontrado = 1;
            }
        }
        if (encontrado == 0){
            return -1;
        }

    }
    return 0;
}
