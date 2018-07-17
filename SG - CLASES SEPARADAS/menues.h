#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED
#include "funciones.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

class Menues{
    private:
        int opcion;
        int y;
        char identificador[20];
    public:
        main();
        void setOpcion(int _opcion){opcion=_opcion;};
        void derivarMenu(char *);
        void logIn();
        void menuAdministrador(char *usuario);
        void submenuAdministrador(char *usuario);
        void menuVentas(char *usuario);
        void menuCompras(char *usuario);
        void submenuProductos(char *usuario);
        void submenuProveedores(char *usuario);
        void menuTransferencias(char *usuario);
};

void Menues::logIn(){
    system("color 1D");
    Usuario unUsuario,aux;
    Validador validar;
    char nombre[20], password[20];
    int pos,intentos=0;
    do{
        pos=0;
        fflush(stdin);
        recuadro(25, 1,45, 20, cBLANCO, cAZUL);
        recuadro(25, 1,45, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "-INICIO SESION-"<<endl;
        textcolor(cBLANCO, cAZUL);
        gotoxy(44,5);cout << "-NOMBRE-";
        gotoxy(42,9);cout << "-CONTRASEÑA-";
        recuadro(33,6,30, 2, cBLANCO, cGRIS);
        recuadro(33,10,30, 2, cBLANCO, cGRIS);
        gotoxy(45,7);cin.getline(nombre,20);
        convierteAMiniscula(nombre);
        aux.setNombre(nombre); //CARGO EL NOMBRE
        fflush(stdin);
        gotoxy(45,11);
        ocultarContrasenia(password);
        aux.setPassword(password);
        while(unUsuario.leerArchivo(pos++)){ //COMPARO EL USUARIOS Y CONTRASEÑA DE AMBOS OBJETOS

              if(!(unUsuario!=aux)) {
                    limpiar();
                    intentos=0;
                    opcion=unUsuario.getSector(); // GUARDO LA OPCION QUE LE CORRESPONDA AL USUARIO ASI LO DERIVO AL MENU CORRESPONDIENTE
                    derivarMenu(unUsuario.getNombre()); //GUARDO EL NOMBRE DEL USUARIO INGRESADO Y LLAMO A LA FUNCION
                }
        }
        textcolor(cROJO_CLARO, cAZUL);
        gotoxy(35,14);
        cout << "USUARIO/PASSWORD INCORRECTO"<<endl;
        intentos++;
        if(validar.intentosDeInicio(intentos,3)) exit (0);
        getch();
    }

    while(true);
}
void Menues::derivarMenu(char *usuario){

    switch(opcion){
        case 1:
            menuAdministrador(usuario);
            break;
        case 2:
            menuVentas(usuario);
            break;
        case 3:
            menuCompras(usuario);
            break;
        case 4:
            menuTransferencias(usuario);
            break;
    }
}
void Menues::submenuAdministrador(char *usuario){

do{

    cout << "SUBMENU ADMINISTRADOR"<<endl;
    cout << "[1] AGREGAR USUARIO"<<endl;
    cout << "[2] BORRAR USUARIO"<<endl;
    cout << "[3] LISTAR USUARIOS"<<endl;
    cout << "[4] LISTAR USUARIO POR CODIGO"<<endl;
    cout << "[5] MODIFICAR USUARIO"<<endl;
    cout << "[0] VOLVER AL MENU ANTERIOR"<<endl;
    cout << endl;
    cout << "INGRESE UNA OPCION:";
    cin >> opcion;
    system("cls");
    switch(opcion) {
    case 1:
        agregarUsuario();
        break;
    case 2:
        borrarUsuario();
        break;
    case 3:
        listarUsuarios();
        break;
    case 4:
        listarUsuarioPorCodigo();
        break;
    case 5:
        modificarUsuario();
        break;
    case 0:
        menuAdministrador(usuario);
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);

}
void Menues::menuAdministrador(char *usuario){

do{

    cout << "MENU ADMINISTRADOR"<<endl;
    cout << "[1] MENU COMPRAS"<<endl;
    cout << "[2] MENU VENTAS"<<endl;
    cout << "[3] MENU MOVIMIENTOS"<<endl;
    cout << "[4] CONFIGURACON"<<endl;
    cout << "[5] REPORTES"<<endl;
    cout << "[0] CIERRE DE SESIÓN"<<endl;
    cout << endl;
    cout << "INGRESE UNA OPCION:";
    cin >> opcion;
    system("cls");
    switch(opcion) {
    case 1:
        menuCompras(usuario);
        break;
    case 2:
        menuVentas(usuario);
        break;
    case 3:
        menuTransferencias(usuario);
        break;
    case 4:
        submenuAdministrador(usuario);
        break;
    case 5:
        cout << "NO DESARROLLADA."<<endl;
        break;
    case 0:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::menuVentas(char *usuario){

do{

    cout << "MENU VENTAS"<<endl;
    cout << "[1] AGREGAR VENTA"<<endl;
    cout << "[2] CONSULTAR VENTA"<<endl;
    cout << "[3] CIERRE DE CAJA"<<endl;
    cout << "[0] CIERRE DE SESIÓN"<<endl;
    cout << endl;
    cout << "INGRESE UNA OPCION:";
    cin >> opcion;
    system("cls");
    switch(opcion) {
    case 1:
        agregarVenta(usuario);
        break;
    case 2:
        listarVentasPorCodigo();
        break;
    case 3:
        cierreDeCaja(usuario);
        break;
    case 0:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::submenuProveedores(char *usuario){

do{
    cout << "SUBMENU PROVEEDORES"<<endl;
    cout << "[1] AGREGAR PROVEEDORES"<<endl;
    cout << "[2] BORRAR PROVEEDORES"<<endl;
    cout << "[3] LISTAR TODOS LOS PROVEEDORES"<<endl;
    cout << "[4] LISTAR PROVEEDORES POR CODIGO"<<endl;
    cout << "[5] MODIFICAR PROVEEDOR"<<endl;
    cout << "[6] MODIFICAR PORCENTUALES"<<endl;
    cout << "[0] VOLVER AL MENU ANTERIOR"<<endl;
    cout << endl;
    cout << "INGRESE UNA OPCION:";
    cin >> opcion;
    system("cls");
    switch(opcion) {
    case 1:
        agregarProveedor();
        break;
    case 2:
        borrarProveedor();
        break;
    case 3:
        listarProveedores();
        break;
    case 4:
        listarProveedorPorCodigo();
        break;
    case 5:
        modificarProveedor();
        break;
    case 6:
        modificarPorcentuales();
    case 0:
        menuCompras(usuario);
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::submenuProductos(char *usuario){

do{
    recuadro(20, 1,60, 25, cBLANCO, cAZUL);
    recuadro(20, 1,60, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(43,2);cout << "SUBMENU PRODUCTOS"<<endl;
    recuadro(33, 4,35, 2, cBLANCO, cGRIS);
    textcolor(cBLANCO, cGRIS);
    gotoxy(43,5);cout << "AGREGAR PRODUCTO"<<endl;
    recuadro(33,7,35, 2, cBLANCO, cGRIS);
    gotoxy(42,8);cout << "BORRAR PRODUCTO"<<endl;
    recuadro(33,10,35, 2, cBLANCO, cGRIS);
    gotoxy(41,11);cout << "LISTAR TODOS LOS PRODUCTOS"<<endl;
    recuadro(33,13,35, 2, cBLANCO, cGRIS);
    gotoxy(38,14);cout << "LISTAR PRODUCTOS POR CODIGO"<<endl;
    recuadro(33,16,35, 2, cBLANCO, cGRIS);
    gotoxy(38,17);cout << "MODIFICAR PRODUCTO"<<endl;
    recuadro(33,19,35, 2, cBLANCO, cGRIS);
    gotoxy(40,20);cout << "VOLVER AL MENU ANTERIOR"<<endl;
    recuadro(20,24,60, 2, cBLANCO, cAZUL);
    gotoxy(24,24); cout << "UTILICE LAS TECLAS DE ARRIBA Y ABAJO PARA DESPLAZARSE.";
    cout << endl;
    y=navegacionMenu(35,5,5,20);

    system("cls");
    switch(y) {
    case 5:
        agregarProducto();
        break;
    case 8:
        borrarProducto();
        break;
    case 11:
        listarProductos();
        break;
    case 14:
        listarProductoPorCodigo();
        break;
    case 17:
        modificarProducto();
    case 20:
        menuCompras(usuario);
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::menuCompras(char *usuario){
do{

    recuadro(20, 1,60, 25, cBLANCO, cAZUL);
    recuadro(20, 1,60, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(43,2);cout << "MENU COMPRAS"<<endl;
    recuadro(33, 4,30, 2, cBLANCO, cGRIS);
    textcolor(cBLANCO, cGRIS);
    gotoxy(43,5);cout << "PRODUCTOS"<<endl;
    recuadro(33,7,30, 2, cBLANCO, cGRIS);
    gotoxy(42,8);cout << "PROVEEDORES"<<endl;
    recuadro(33,10,30, 2, cBLANCO, cGRIS);
    gotoxy(41,11);cout << "AGREGAR COMPRA"<<endl;
    recuadro(33,13,30, 2, cBLANCO, cGRIS);
    gotoxy(38,14);cout << "LISTAR TODAS LAS COMPRAS"<<endl;
    recuadro(33,16,30, 2, cBLANCO, cGRIS);
    gotoxy(38,17);cout << "LISTAR COMPRA POR CODIGO"<<endl;
    recuadro(33,19,30, 2, cBLANCO, cGRIS);
    gotoxy(40,20);cout << "CIERRE DE SESIÓN"<<endl;
    recuadro(20,24,60, 2, cBLANCO, cAZUL);
    gotoxy(24,24); cout << "UTILICE LAS TECLAS DE ARRIBA Y ABAJO PARA DESPLAZARSE.";
    cout << endl;
    y=navegacionMenu(35,5,5,20);

    system("cls");
    switch(y) {
    case 5:
        submenuProductos(usuario);
        break;
    case 8:
        submenuProveedores(usuario);
        break;
    case 11:
        agregarCompra(usuario);
        break;
    case 14:
        listarTodasLasCompras();
        break;
    case 17:
        listarComprasPorCodigo();
        break;
    case 20:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::menuTransferencias(char *usuario){

do{

    cout << "MENU MOVIMIENTOS"<<endl;
    cout << "[1] TRANSFERENCIA DE MERCADERIA"<<endl;
    cout << "[2] DEVOLUCION DE MERCADERIA"<<endl;
    cout << "[3] CONSULTAR TRANSFERENCIAS Y DEVOLUCIONES"<<endl;
    cout << "[0] CIERRE DE SESIÓN"<<endl;
    cout << endl;
    cout << "INGRESE UNA OPCION:";
    cin >> opcion;
    system("cls");
    switch(opcion) {
    case 1:
        transferenciaDeMercaderia(usuario,1);
        break;
    case 2:
        devolucionDeMercaderia(usuario,2);
        break;
    case 3:
        cout << "LISTAR"<<endl;
        break;
    case 0:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INVÁLIDA."<<endl;
        break;
    }
}
    while(true);
}


#endif // MENUES_H_INCLUDED
