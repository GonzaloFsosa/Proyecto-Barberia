#include "BarberoManager.h"
#include <iostream>
#include <string>
using namespace std;

void BarberoManager::menuBarberos() {
    int opcion;
    do {
        cout << "\n--- MENU BARBEROS ---" << endl;
        cout << "1. Alta de Barbero" << endl;
        cout << "2. Listar Barberos Activos" << endl;
        cout << "3. Modificar Barbero" << endl;
        cout << "4. Dar de Baja (Baja Logica)" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: altaBarbero(); break;
            case 2: listarBarberos(); break;
            case 3: modificarBarbero(); break;
            case 4: bajaBarbero(); break;
            case 0: cout << "Volviendo..." << endl; break;
            default: cout << "Opcion invalida." << endl; break;
        }
    } while(opcion != 0);
}

void BarberoManager::altaBarbero() {
    // 1. Calcular el nuevo ID automáticamente
    int cant = _archivo.contarRegistros();
    int nuevoId = 1; // Si está vacío, el primero es 1

    // Buscamos el ID más alto (esté activo o no)
    for (int i = 0; i < cant; i++) {
        Barbero aux = _archivo.leer(i);
        if (aux.getIdBarbero() >= nuevoId) {
            nuevoId = aux.getIdBarbero() + 1;
        }
    }

    cout << "El ID asignado automaticamente es: " << nuevoId << endl;

    string nombre, apellido, tel, email, dir;
    cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
    cout << "Apellido: "; getline(cin, apellido);
    cout << "Telefono: "; getline(cin, tel);
    cout << "Email: "; getline(cin, email);
    cout << "Direccion: "; getline(cin, dir);

    Barbero b;
    b.setIdBarbero(id);
    b.setNombre(nombre.c_str());
    b.setApellido(apellido.c_str());
    b.setTelefono(tel.c_str());
    b.setEmail(email.c_str());
    b.setDireccion(dir.c_str());
    b.setActivo(true);

    if (_archivo.guardar(b)) {
        cout << "Barbero guardado con exito." << endl;
    } else {
        cout << "Error al guardar en el archivo." << endl;
    }
}

void BarberoManager::listarBarberos() {
    int cant = _archivo.contarRegistros();
    if (cant == 0) {
        cout << "No hay barberos en el sistema." << endl;
        return;
    }

    cout << "\n--- LISTADO DE BARBEROS ACTIVOS ---" << endl;
    for (int i = 0; i < cant; i++) {
        Barbero b = _archivo.leer(i);
        if (b.getActivo()) {
            b.mostrar();
        }
    }
}

void BarberoManager::modificarBarbero() {
    int id;
    cout << "Ingrese ID del barbero a modificar: ";
    cin >> id;

    int pos = _archivo.buscar(id);
    if (pos == -1) {
        cout << "El barbero no existe." << endl;
        return;
    }

    Barbero b = _archivo.leer(pos);
    b.mostrar();

    string nuevoTel;
    cout << "Ingrese nuevo telefono (o deje vacio para mantener): ";
    cin.ignore();
    getline(cin, nuevoTel);

    if (nuevoTel != "") {
        b.setTelefono(nuevoTel.c_str());
        if (_archivo.guardar(b, pos)) {
            cout << "Modificado con exito." << endl;
        }
    } else {
        cout << "No se realizaron cambios." << endl;
    }
}

void BarberoManager::bajaBarbero() {
    int id;
    cout << "Ingrese ID del barbero a dar de baja: ";
    cin >> id;

    int pos = _archivo.buscar(id);
    if (pos == -1) {
        cout << "El barbero no existe." << endl;
        return;
    }

    Barbero b = _archivo.leer(pos);
    if (!b.getActivo()) {
        cout << "El barbero ya estaba dado de baja." << endl;
        return;
    }

    b.setActivo(false); // Baja lógica
    if (_archivo.guardar(b, pos)) {
        cout << "Barbero dado de baja correctamente." << endl;
    }
}
