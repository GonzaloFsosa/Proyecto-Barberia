#include "CorteArchivo.h"
#include <cstdio>

bool CorteArchivo::guardar(Corte reg) {
    FILE *p = fopen("cortes.dat", "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Corte), 1, p);
    fclose(p);
    return ok;
}

bool CorteArchivo::guardar(Corte reg, int pos) {
    FILE *p = fopen("cortes.dat", "rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Corte), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Corte), 1, p);
    fclose(p);
    return ok;
}

Corte CorteArchivo::leer(int pos) {
    Corte reg;
    FILE *p = fopen("cortes.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, pos * sizeof(Corte), SEEK_SET);
    fread(&reg, sizeof(Corte), 1, p);
    fclose(p);
    return reg;
}

int CorteArchivo::contarRegistros() {
    FILE *p = fopen("cortes.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Corte);
}

int CorteArchivo::buscar(int idCorte) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Corte aux = leer(i);
        if (aux.getIdCorte() == idCorte) return i;
    }
    return -1;
}
