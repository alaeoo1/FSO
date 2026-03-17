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
    DebeSerCierto(crea_sala(CAPACIDAD_RB) == CAPACIDAD_RB);
    DebeSerCierto(capacidad_sala()==CAPACIDAD_RB);
    DebeSerCierto((mi_asiento=reserva_asiento(ID_1))>=0);
    DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_RB);
    DebeSerCierto(estado_asiento(mi_asiento)>0);
    DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
    DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_RB);
    elimina_sala();
    FIN_TEST("Reserva básica");
}
<<<<<<< HEAD
=======
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
>>>>>>> c7c5e7364eb7ef1e81fd91fba9743188014ad503

void test_AsientoInvalido() {
    INICIO_TEST("Asiento inválido");
    crea_sala(10);
    DebeSerCierto(reserva_asiento(123) >= 0);
    DebeSerCierto(estado_asiento(0) == -1);
    DebeSerCierto(libera_asiento(999) == -1);
    elimina_sala();
    FIN_TEST("Asiento inválido");
}

void test_LiberaVacio() {
    INICIO_TEST("Libera vacío");
    crea_sala(5);
    DebeSerCierto(libera_asiento(1) == -1);
    DebeSerCierto(reserva_asiento(999) >= 0);
    libera_asiento(2);
    DebeSerCierto(estado_asiento(2) == 0);
    DebeSerCierto(libera_asiento(2) == -1);
    elimina_sala();
    FIN_TEST("Libera vacío");
}

void test_LlenaSala() {
    INICIO_TEST("Llena sala");
    crea_sala(3);
    DebeSerCierto(reserva_asiento(1) >= 0);
    DebeSerCierto(reserva_asiento(2) >= 0);
    DebeSerCierto(reserva_asiento(3) >= 0);
    DebeSerCierto(reserva_asiento(4) == -1);  // No hay más asientos
    DebeSerCierto(asientos_libres() == 0);
    elimina_sala();
    FIN_TEST("Llena sala");
}

void test_ReutilizaAsiento() {
    INICIO_TEST("Reutiliza asiento");
    crea_sala(5);
    int asiento = reserva_asiento(1000);
    DebeSerCierto(asiento >= 0);
    DebeSerCierto(libera_asiento(asiento) == 1000);
    DebeSerCierto(reserva_asiento(1000) >= 0);  // Mismo ID reutiliza
    DebeSerCierto(estado_asiento(asiento) == 1000);
    elimina_sala();
    FIN_TEST("Reutiliza asiento");
}

void test_Estado() {
    INICIO_TEST("estado_sala");
    crea_sala(3);
    reserva_asiento(123);
    estado_sala();
    elimina_sala();
    FIN_TEST("estado_sala");
}

void test_Sentarse() {

    INICIO_TEST("Test sentarse");
    crea_sala(4);
    sentarse(123);
    DebeSerCierto(asientos_ocupados() == 1);
    DebeSerCierto(asientos_libres() == 4 - 1);
    DebeSerCierto(estado_asiento(1) == 123);

    elimina_sala();
    FIN_TEST("Test sentarse");
}

void test_Levantarse() {

    INICIO_TEST("Levantarse");
    crea_sala(5);
    sentarse(101);
    DebeSerCierto(asientos_ocupados() == 1);
    levantarse(101);
    DebeSerCierto(asientos_ocupados() == 0);
    levantarse(103);

    elimina_sala();
    FIN_TEST("Levantarse");
}

void test_ReservaMultiple(){
    INICIO_TEST("Reserva Multiple");
    int ids[3] = {7, 11, 13};
    crea_sala(5);
    DebeSerCierto(reserva_multiple(3, ids) == 0);
    DebeSerCierto(asientos_ocupados() == 3);
    elimina_sala();
}


void ejecuta_tests () {
    
    test_ReservaBasica();
    test_AsientoInvalido();
    test_LiberaVacio();
    test_LlenaSala();	
    //test_ReutilizaAsiento();
    test_Estado();
    test_Sentarse();
    test_Levantarse();
    test_ReservaMultiple();

}

int main(void) {
    puts("Iniciando tests...");
    ejecuta_tests();
    puts("Batería de test completa.");
    return 0;
}

