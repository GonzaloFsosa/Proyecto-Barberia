#include "ClienteArchivo.h"
#include <cstdio>

bool ClienteArchivo::guardar(Cliente reg) {
    FILE *p = fopen("clientes.dat", "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool ClienteArchivo::guardar(Cliente reg, int pos) {
    FILE *p = fopen("clientes.dat", "rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

Cliente ClienteArchivo::leer(int pos) {
    Cliente reg;
    FILE *p = fopen("clientes.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

int ClienteArchivo::contarRegistros() {
    FILE *p = fopen("clientes.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

int ClienteArchivo::buscar(int idCliente) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Cliente aux = leer(i);
        if (aux.getIdCliente() == idCliente) return i;
    }
    return -1;
}
