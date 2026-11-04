#ifndef CORTEARCHIVO_H
#define CORTEARCHIVO_H
#include "Corte.h"

class CorteArchivo {
public:
    bool guardar(Corte reg);
    bool guardar(Corte reg, int pos);
    Corte leer(int pos);
    int contarRegistros();
    int buscar(int idCorte);
};
#endif
