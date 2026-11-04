#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H
#include "Cliente.h"

class ClienteArchivo {
public:
    bool guardar(Cliente reg);
    bool guardar(Cliente reg, int pos);
    Cliente leer(int pos);
    int contarRegistros();
    int buscar(int idCliente);
};
#endif
