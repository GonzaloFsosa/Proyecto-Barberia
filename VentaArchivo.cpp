#include "VentaArchivo.h"
#include <cstdio>

bool VentaArchivo::guardar(Venta reg) {
    FILE *p = fopen("ventas.dat", "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

bool VentaArchivo::guardar(Venta reg, int pos) {
    FILE *p = fopen("ventas.dat", "rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

Venta VentaArchivo::leer(int pos) {
    Venta reg;
    FILE *p = fopen("ventas.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return reg;
}

int VentaArchivo::contarRegistros() {
    FILE *p = fopen("ventas.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Venta);
}

int VentaArchivo::buscar(int idVenta) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Venta aux = leer(i);
        if (aux.getIdVenta() == idVenta) return i;
    }
    return -1;
}
