#ifndef BARBEROMANAGER_H
#define BARBEROMANAGER_H

#include "Barbero.h"
#include "BarberoArchivo.h"

class BarberoManager {
private:
    BarberoArchivo _archivo;

public:
    void menuBarberos();    // Muestra el submenú
    void altaBarbero();
    void listarBarberos();
    void modificarBarbero();
    void bajaBarbero();
};

#endif
