#include <assert.h>
#include <stdio.h>
#include "sala.h"

#define DebeSerCierto(x) assert(x)
#define DebeSerFalso(x) assert(!(x))


void INICIO_TEST (const char* titulo_test) {
    printf("********** batería de pruebas para %s: ", titulo_test);
    fflush(stdout);
}

void FIN_TEST (const char* titulo_test) {
    printf("********** hecho\n");
}

void test_ReservaBasica() {
    int mi_asiento;
    #define CAPACIDAD_RB 500
    #define ID_1 1500

    INICIO_TEST("Reserva básica");
    crea_sala(CAPACIDAD_RB);
    DebeSerCierto(capacidad_sala()==CAPACIDAD_RB);
    DebeSerCierto((mi_asiento=reserva_asiento(ID_1))>=0);
    DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_RB);
    DebeSerCierto(estado_asiento(mi_asiento)>0);
    DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
    DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_RB);
    elimina_sala();
    FIN_TEST("Reserva básica");
}
void test_ReservasMultiples() {
    #define CAPACIDAD_M 5
    #define ID1 100
    #define ID2 200
    int asiento1;
    int asiento2;

    INICIO_TEST("Reservas múltiples");
    crea_sala(CAPACIDAD_M);
    DebeSerCierto((asiento1 = reserva_asiento(ID1)) >= 0);
    DebeSerCierto((asiento2 = reserva_asiento(ID2)) >= 0 && asiento2 != asiento1);
    DebeSerCierto(estado_asiento(asiento1) == ID1);
    DebeSerCierto(estado_asiento(asiento2) == ID2);
    DebeSerCierto(asientos_ocupados() == 2);
    libera_asiento(asiento1);
    libera_asiento(asiento2);
    elimina_sala();
    FIN_TEST("Reservas múltiples");
}

void test_AsientoInvalido() {
    INICIO_TEST("Asiento inválido");
    crea_sala(10);
    DebeSerCierto(reserva_asiento(123) >= 0);  // Reserva uno válido
    DebeSerCierto(estado_asiento(0) == -1);    // Asiento < 1 → -1
    DebeSerCierto(libera_asiento(999) == -1);  // Liberar inválido → -1
    elimina_sala();
    FIN_TEST("Asiento inválido");
}

void test_LiberaVacio() {
    #define ID_VACIO 999
    INICIO_TEST("Libera vacío");
    crea_sala(5);
    DebeSerCierto(reserva_asiento(ID_VACIO) >= 0);
    libera_asiento(1);  // Libera el reservado
    DebeSerCierto(estado_asiento(1) == 0);     // Ya vacío
    DebeSerCierto(libera_asiento(1) == -1);    // Liberar vacío → -1
    elimina_sala();
    FIN_TEST("Libera vacío");
}

void test_LlenaSala() {
    #define CAPACIDAD_L 3
    INICIO_TEST("Llena sala");
    crea_sala(CAPACIDAD_L);
    DebeSerCierto(reserva_asiento(1) >= 0);
    DebeSerCierto(reserva_asiento(2) >= 0);
    DebeSerCierto(reserva_asiento(3) >= 0);
    DebeSerCierto(reserva_asiento(4) == -1);  // No hay más asientos
    DebeSerCierto(asientos_libres() == 0);
    elimina_sala();
    FIN_TEST("Llena sala");
}

void test_ReutilizaAsiento() {
    #define ID1_RA 1000
    INICIO_TEST("Reutiliza asiento");
    crea_sala(5);
    int asiento = reserva_asiento(ID1_RA);
    DebeSerCierto(asiento >= 0);
    DebeSerCierto(libera_asiento(asiento) == ID1_RA);
    DebeSerCierto(reserva_asiento(ID1_RA) >= 0);  // Mismo ID reutiliza
    DebeSerCierto(estado_asiento(asiento) == ID1_RA);
    elimina_sala();
    FIN_TEST("Reutiliza asiento");
}

void test_Estado() {
    INICIO_TEST("estado_sala()");
    crea_sala(3);
    reserva_asiento(123);
    estado_sala();
    elimina_sala();
    FIN_TEST("estado_sala()");
}


void ejecuta_tests () {
    
    test_ReservaBasica();
    test_ReservasMultiples();
    test_AsientoInvalido();
    test_LiberaVacio();
    test_LlenaSala();	
    //test_ReutilizaAsiento();
    test_Estado();

}

int main(void) {
    puts("Iniciando tests...");
    ejecuta_tests();
    puts("Batería de test completa.");
    return 0;
}

