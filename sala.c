#include <stdlib.h>
#include <stdio.h>
#include "sala.h"


int* asientos = NULL;
int capacidad = 0;   

// 0 = vacío

void crea_sala(int cap) {
    capacidad = cap;
    asientos = malloc(sizeof(int) * capacidad);
    for (int i = 0; i < capacidad; i++) {
        asientos[i] = 0;
    }
}

int capacidad_sala(void) {
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

int asientos_libres(void) {
    int count = 0;
    for (int i = 0; i < capacidad; i++) {
        if (asientos[i] == 0) count++;
    }
    return count;
}

int asientos_ocupados(void) {
    return capacidad - asientos_libres();
}

void elimina_sala(void) {
    free(asientos);
    asientos = NULL;
    capacidad = 0;
}

//------------------------------------------------------------ tests extra

void estado_sala()
{
   if (capacidad == 0){
   	printf("Sala vacia\n");
   	return;
   }
   
   int libres = 0;
   int ocupados = 0;
   for(int i=0; i < capacidad; i++){

   	if(asientos[i] == 0){
   		libres++;
   		printf("ID: %d Libre\n", i+1);
   	} else {
   		ocupados++;
   		printf("ID: %d Ocupado\n", i+1);
   	}
   }
   
   printf("Actualmente hay.. %d asientos vacios y %d ocupados", libres, ocupados);
}