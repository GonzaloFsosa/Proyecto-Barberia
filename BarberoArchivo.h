#ifndef BARBEROARCHIVO_H
#define BARBEROARCHIVO_H

#include "Barbero.h"

class BarberoArchivo {
public:
    // 1. Guardar al final (para un ALTA nueva)
    bool guardar(Barbero reg);

    // 2. Guardar en una posición específica (para MODIFICAR o BAJA LÓGICA)
    bool guardar(Barbero reg, int pos);

    // 3. Leer un registro de una posición específica
    Barbero leer(int pos);

    // 4. Contar cuántos registros hay en el archivo
    int contarRegistros();

    // 5. Buscar un barbero por ID y devolver su posición (o -1 si no existe)
    int buscar(int idBarbero);
};

#endif // BARBEROARCHIVO_H
