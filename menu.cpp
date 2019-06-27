#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
enum class Opciones { Agregar=1, Remover, Mostrar}; // se usa un tipo enumerado para indicar las opciones

void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    TipoCaracter w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n\n";
    cout << "0. Para Salir\n\n";
}

void Menu::agregarObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre : ");
    auto color = input<TipoCaracter>("Ingrese color (Un caracter): ");

    auto x = input<TipoEntero>("Ingrese posicion X : ");
    while (x < 0 || x >= tierra.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << tierra.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");


        auto y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");


            tierra.adicionarObjeto(new Objeto(nombre, color, x, y));
        }
    }
}
void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    auto obj = tierra.removerObjeto(nombre);  //-- separa el objeto de la tierra
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    } else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";

        esperar();
    }
}

void Menu::dibujarMapa () {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}

void Menu::ejecutar() {
    do {
        imprimirMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch (Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;

    }
}