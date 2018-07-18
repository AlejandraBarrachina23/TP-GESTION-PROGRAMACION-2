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
        void setOpcion(int _opcion){opcion=_opcion;};
        void derivarMenu(char *);
        void logIn();
        void menuAdministrador(char *usuario);
        void submenuReportes(char *usuario);
        void submenuConfiguracion(char *usuario);
        void menuVentas(char *usuario);
        void menuCompras(char *usuario);
        void submenuProductos(char *usuario);
        void submenuProveedores(char *usuario);
        void menuTransferencias(char *usuario);
};
void Menues::logIn(){

    Usuario unUsuario,aux;
    Validador validar;
    char nombre[20], password[20];
    int pos,intentos=0;
    do{
        pos=0;
        fflush(stdin);
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        recuadro(1, 25,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(3,26);cout << "UTN FRGP - TSP - PROGRAMACION II";
        gotoxy(73,26);cout << "BARRACHINA, MARIA ALEJANDRA";
        gotoxy(40,2);cout << "-SISTEMA DE GESTION-"<<endl;
        recuadro(27,5,46, 18, cBLANCO, cAZUL);
        gotoxy(42,5);cout << "INICIO DE SESION"<<endl;
        textcolor(cBLANCO, cAZUL);
        gotoxy(45,8);cout << "-NOMBRE-";
        gotoxy(44,13);cout << "-CONTRASE�A-";
        recuadro(35,9,30, 2, cBLANCO, cGRIS);
        recuadro(35,14,30, 2, cBLANCO, cGRIS);
        gotoxy(46,10);cin.getline(nombre,20);
        convierteAMiniscula(nombre);
        aux.setNombre(nombre); //CARGO EL NOMBRE
        fflush(stdin);
        gotoxy(46,15);
        ocultarContrasenia(password);
        aux.setPassword(password);
        while(unUsuario.leerArchivo(pos++)){ //COMPARO EL USUARIOS Y CONTRASE�A DE AMBOS OBJETOS

              if(!(unUsuario!=aux)) {
                    limpiar();
                    intentos=0;
                    opcion=unUsuario.getSector(); // GUARDO LA OPCION QUE LE CORRESPONDA AL USUARIO ASI LO DERIVO AL MENU CORRESPONDIENTE
                    derivarMenu(unUsuario.getNombre()); //GUARDO EL NOMBRE DEL USUARIO INGRESADO Y LLAMO A LA FUNCION
                }
        }
        textcolor(cROJO_CLARO, cAZUL);
        gotoxy(38,18);cout << "USUARIO/PASSWORD INCORRECTO"<<endl;
        intentos++;
        if(validar.intentosDeInicio(intentos,3)) {limpiar();exit(0);}
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
void Menues::submenuReportes(char *usuario){

do{

    cout << "SUBMENU REPORTES"<<endl;
    cout << "[1] GANANCIAS"<<endl;
    cout << "[2] PERDIDAS"<<endl;
    cout << "[3] BACKUPS"<<endl;
    cout << "[4] MAYORES VENTAS"<<endl;
    cout << "[5] MENORES VENTAS"<<endl;
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
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
        break;
    }
}
    while(true);

}
void Menues::submenuConfiguracion(char *usuario){

do{

    cout << "SUBMENU CONFIGURACION"<<endl;
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
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
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
    cout << "[0] CIERRE DE SESI�N"<<endl;
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
        submenuConfiguracion(usuario);
        break;
    case 5:
        submenuReportes(usuario);
        break;
    case 0:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::menuVentas(char *usuario){

do{
    recuadro(20, 1,60, 25, cBLANCO, cAZUL);
    recuadro(20, 1,60, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(43,2);cout << "MENU VENTAS"<<endl;
    textcolor(cBLANCO, cGRIS);
    recuadro(33, 7,35, 2, cBLANCO, cGRIS);
    gotoxy(43,8);cout << "AGREGAR VENTA"<<endl;
    recuadro(33,10,35, 2, cBLANCO, cGRIS);
    gotoxy(43,11);cout << "CONSULTAR VENTA"<<endl;
    recuadro(33,13,35, 2, cBLANCO, cGRIS);
    gotoxy(43,14);cout << "CIERRE DE CAJA"<<endl;
    recuadro(33,16,35, 2, cBLANCO, cGRIS);
    gotoxy(43,17);cout << "CIERRE DE SESI�N"<<endl;

    cout << endl;
    recuadro(20,24,60, 2, cBLANCO, cAZUL);
    gotoxy(24,24); cout << "UTILICE LAS TECLAS DE ARRIBA Y ABAJO PARA DESPLAZARSE.";
    cout << endl;
    y=navegacionMenu(35,8,8,17);

    system("cls");
    switch(y) {
    case 8:
        agregarVenta(usuario);
        break;
    case 11:
        listarVentasPorCodigo();
        break;
    case 14:
        cierreDeCaja(usuario);
        break;
    case 17:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::submenuProveedores(char *usuario){

do{

    recuadro(20, 1,60, 25, cBLANCO, cAZUL);
    recuadro(20, 1,60, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(43,2);cout << "SUBMENU PROVEEDORES"<<endl;
    recuadro(33, 4,35, 2, cBLANCO, cGRIS);
    textcolor(cBLANCO, cGRIS);
    gotoxy(43,5);cout << "AGREGAR PROVEDOR"<<endl;
    recuadro(33,7,35, 2, cBLANCO, cGRIS);
    gotoxy(43,8);cout << "BORRAR PROVEEDOR"<<endl;
    recuadro(33,10,35, 2, cBLANCO, cGRIS);
    gotoxy(38,11);cout << "LISTAR TODOS LOS PROVEEDORES"<<endl;
    recuadro(33,13,35, 2, cBLANCO, cGRIS);
    gotoxy(38,14);cout << "LISTAR PROVEEDOR POR CODIGO"<<endl;
    recuadro(33,16,35, 2, cBLANCO, cGRIS);
    gotoxy(43,17);cout << "MODIFICAR PROVEEDOR"<<endl;
    recuadro(33,19,35, 2, cBLANCO, cGRIS);
    gotoxy(40,20);cout << "VOLVER AL MENU ANTERIOR"<<endl;
    recuadro(20,24,60, 2, cBLANCO, cAZUL);
    gotoxy(24,24); cout << "UTILICE LAS TECLAS DE ARRIBA Y ABAJO PARA DESPLAZARSE.";
    cout << endl;
    y=navegacionMenu(35,5,5,20);

    system("cls");
    switch(y) {
    case 5:
        agregarProveedor();
        break;
    case 8:
        borrarProveedor();
        break;
    case 11:
        listarProveedores();
        break;
    case 14:
        listarProveedorPorCodigo();
        break;
    case 17:
        modificarProveedor();
        break;
    case 20:
       menuCompras(usuario);
        break;
    default:
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
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
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
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
    gotoxy(40,20);cout << "CIERRE DE SESI�N"<<endl;
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
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
        break;
    }
}
    while(true);
}
void Menues::menuTransferencias(char *usuario){

do{
    recuadro(20, 1,60, 25, cBLANCO, cAZUL);
    recuadro(20, 1,60, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(43,2);cout << "MENU MOVIMIENTOS"<<endl;
    recuadro(35, 7,30, 2, cBLANCO, cGRIS);
    textcolor(cBLANCO, cGRIS);
    gotoxy(40,8);cout << "TRANSFERIR MERCADERIA"<<endl;
    recuadro(35,10,30, 2, cBLANCO, cGRIS);
    gotoxy(40,11);cout << "DEVOLVER MERCADERIA"<<endl;
    recuadro(35,13,30, 2, cBLANCO, cGRIS);
    gotoxy(40,14);cout << "CONSULTAR MOVIMIENTOS"<<endl;
    recuadro(35,16,30, 2, cBLANCO, cGRIS);
    gotoxy(40,17);cout << "CIERRE DE SESION"<<endl;
    recuadro(20,24,60, 2, cBLANCO, cAZUL);
    gotoxy(24,24); cout << "UTILICE LAS TECLAS DE ARRIBA Y ABAJO PARA DESPLAZARSE.";
    cout << endl;
    y=navegacionMenu(37,8,8,17);

    system("cls");
    switch(y) {
    case 8:
        transferenciaDeMercaderia(usuario,1);
        break;
    case 11:
        devolucionDeMercaderia(usuario,2);
        break;
    case 14:
        listadoDeMovimientos();
        break;
    case 17:
        logIn();
        break;
    default:
        cout << "LA OPCION INGRESADA ES INV�LIDA."<<endl;
        break;
    }
}
    while(true);
}


#endif // MENUES_H_INCLUDED
