#include "TurnoArchivo.h"
#include <cstdio>

bool TurnoArchivo::guardar(Turno reg) {
    FILE *p = fopen("turnos.dat", "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return ok;
}

bool TurnoArchivo::guardar(Turno reg, int pos) {
    FILE *p = fopen("turnos.dat", "rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Turno), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return ok;
}

Turno TurnoArchivo::leer(int pos) {
    Turno reg;
    FILE *p = fopen("turnos.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, pos * sizeof(Turno), SEEK_SET);
    fread(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return reg;
}

int TurnoArchivo::contarRegistros() {
    FILE *p = fopen("turnos.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Turno);
}

int TurnoArchivo::buscar(int idTurno) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Turno aux = leer(i);
        if (aux.getIdTurno() == idTurno) return i;
    }
    return -1;
}
