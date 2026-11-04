#include "BarberoArchivo.h"
#include <cstdio>

// 1. GUARDAR AL FINAL (MODO "ab")
bool BarberoArchivo::guardar(Barbero reg) {
    FILE *p = fopen("barberos.dat", "ab"); // "ab" = Append (al final)
    if (p == NULL) return false;

    bool ok = fwrite(&reg, sizeof(Barbero), 1, p);
    fclose(p);
    return ok;
}

// 2. SOBREESCRIBIR EN UNA POSICIÓN (MODO "rb+")
bool BarberoArchivo::guardar(Barbero reg, int pos) {
    FILE *p = fopen("barberos.dat", "rb+"); // "rb+" = Read/Write (permite modificar)
    if (p == NULL) return false;

    // Nos movemos a la posición exacta del registro que queremos pisar
    fseek(p, pos * sizeof(Barbero), SEEK_SET);

    bool ok = fwrite(&reg, sizeof(Barbero), 1, p);
    fclose(p);
    return ok;
}

Barbero BarberoArchivo::leer(int pos) {
    Barbero reg;
    FILE *p = fopen("barberos.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, pos * sizeof(Barbero), SEEK_SET);
    fread(&reg, sizeof(Barbero), 1, p);
    fclose(p);
    return reg;
}

int BarberoArchivo::contarRegistros() {
    FILE *p = fopen("barberos.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Barbero);
}

int BarberoArchivo::buscar(int idBarbero) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Barbero aux = leer(i);
        if (aux.getIdBarbero() == idBarbero) return i;
    }
    return -1;
}
