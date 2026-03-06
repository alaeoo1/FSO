#ifndef SALA_H
#define SALA_H

void crea_sala(int cap);
int capacidad_sala(void);
int reserva_asiento(int id_persona);
int libera_asiento(int id_asiento);
int estado_asiento(int id_asiento);
int asientos_libres(void);
int asientos_ocupados(void);
void elimina_sala(void);
void estado_sala(void);

#endif
