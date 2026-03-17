#ifndef SALA_H
#define SALA_H

int crea_sala(int cap);
int capacidad_sala(void);
int reserva_asiento(int id_persona);
int libera_asiento(int id_asiento);
int estado_asiento(int id_asiento);
int asientos_libres();
int asientos_ocupados();
int elimina_sala();
int estado_sala();
int sentarse(int id);
int levantarse(int id);
int reserva_multiple(int npersonas, int* lista_id);

#endif
