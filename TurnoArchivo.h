#ifndef TURNOARCHIVO_H
#define TURNOARCHIVO_H
#include "Turno.h"

class TurnoArchivo {
public:
    bool guardar(Turno reg);
    bool guardar(Turno reg, int pos);
    Turno leer(int pos);
    int contarRegistros();
    int buscar(int idTurno);
};
#endif
