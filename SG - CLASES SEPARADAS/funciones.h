#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "menues.h"
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "declaraciones.h"
#include "usuarios.h"
#include "retencionesImpositivas.h"
#include "productos.h"
#include "validador.h"
#include "fechas.h"
#include "cabeceraCompra.h"
#include "cabeceraDocumento.h"
#include "cabeceraVentas.h"
#include "cabeceraMovimientos.h"
#include "detalleCompra.h"
#include "detalleVentas.h"
#include "detalleMovimientos.h"
#include "proveedor.h"

using namespace std;

///MENU ADMNISTRADOR
void agregarUsuario(){

    Usuario unUsuario;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "AGREGAR USUARIO"<<endl;
    textcolor(cBLANCO, cAZUL);
    unUsuario.cargarDatos();
    unUsuario.grabarArchivo();
    accionAceptada();
    getch();
    limpiar();
    }
void borrarUsuario(){

    Usuario unUsuario;
    Validador validar;
    char usuarioAborrar[20];
    int pos,codigo;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "BORRAR USUARIO"<<endl;

    gotoxy(25,4);cout << "INGRESE EL CODIGO DEL USUARIO QUE DESEA BORRAR: "<<endl;
    gotoxy(73,4);cin >> codigo;

    if((pos=validar.existenciaCodigoUsuario(codigo))>=0){
        unUsuario.leerArchivo(pos);
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(25,5);cout <<"EL USUARIO CORRESPONDIENTE AL CODIGO ES: "<<strcpy(usuarioAborrar,buscarUsuario(unUsuario.getCodigo()));
        textcolor(cBLANCO,cAZUL);
        if(advertenciaDeBorrado()){
            unUsuario.setEstado(false);
            unUsuario.modificarRegistro(pos);
            accionAceptada();
        }
        else accionCancelada();
    }
    else {textcolor(cROJO_CLARO,cAZUL);gotoxy(22,5);cout << "EL CODIGO INGRESADO NO PERTENECE A UN EMPLEADO EXISTENTE."<<endl;}
    getch();
    limpiar();
}
void listarUsuarios(){
    Usuario unUsuario;
    unUsuario.mostrarEncabezado();
    int pos=0;
        while(unUsuario.leerArchivo(pos++)){
                unUsuario.mostrarArchivo();
    }
    getch();
    limpiar();
}
void listarUsuarioPorCodigo(){

    Usuario Unusuario;
    Validador validar;
    int pos,codigo;
    fflush(stdin);
    recuadro(0, 0,102, 25, cBLANCO, cAZUL);
    recuadro(0, 0,102, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,1);cout << "LISTAR USUARIO POR CODIGO"<<endl;
    cout << endl;
    cout << "INGRESE EL CODIGO DEL USUARIO QUE DESEA LISTAR: ";
    cin >> codigo;

    if((pos=validar.existenciaCodigoUsuario(codigo))>=0){
        limpiar();
        Unusuario.leerArchivo(pos);
        Unusuario.mostrarEncabezado();
        Unusuario.mostrarArchivo();
    }
    else {textcolor(cROJO_CLARO,cAZUL);gotoxy(22,5);cout << "EL CODIGO DE USUARIO INGRESADO NO EXISTE."<<endl;}
    getch();
    limpiar();
}
void modificarUsuario(){
    Validador validar;
    Usuario unUsuario;
    int pos=0, codigo,opcion,sector;
    char nombre[20], password[20];

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "MODIFICAR USUARIO"<<endl;
    textcolor(cBLANCO, cAZUL);
    gotoxy(25,4);cout << "INGRESE EL CODIGO DEL USUARIO A MODIFICAR: ";
    cin >> codigo;
     if((pos=validar.existenciaCodigoUsuario(codigo))>=0){
        fflush(stdin);
        unUsuario.leerArchivo(pos);
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(25,5);cout << "NOMBRE: "<< unUsuario.getNombre()<<endl;
        gotoxy(25,6);cout << "CONTRASEÑA: "<<unUsuario.getPassword()<<endl;
        gotoxy(25,7);cout << "SECTOR: "<< unUsuario.getSector()<<endl;
        textcolor(cBLANCO,cAZUL);gotoxy(40,8);cout << "¿QUE DESEA MODIFICAR?"<<endl;
        recuadro(14,10,16,2, cAMARILLO, cROJO);
        recuadro(34,10,16,2, cAMARILLO, cROJO);
        recuadro(54,10,16,2, cAMARILLO, cROJO);
        recuadro(74,10,16,2, cAMARILLO, cROJO);
        gotoxy(20,11);cout << "NOMBRE";
        gotoxy(38,11);cout << "CONTRASEÑA";
        gotoxy(60,11);cout<<"SECTOR";
        gotoxy(80,11);cout << "SALIR";
        opcion=navegacionMenuHorizontal(15,11,15,75,20);
        textcolor(cBLANCO,cAZUL);

        if(opcion==15){
            gotoxy(35,14);cout << "INGRESE EL NUEVO NOMBRE: ";
            cin.getline(nombre,20);
            while(validar.existenciaUsuario(nombre)>=0){
                textcolor(cROJO_CLARO,cAZUL);gotoxy(34,15);cout << "EL NOMBRE INGRESADO YA EXISTE"<<endl;
                getch();
                gotoxy(34,15);cout << "                                      "<<endl;
                gotoxy(60,14);cout << "                   "<<endl;
                textcolor(cBLANCO,cAZUL);
                gotoxy(35,14);cout << "INGRESE EL NUEVO NOMBRE: ";
                gotoxy(60,14);cin.getline(nombre,20);
            }
            unUsuario.setNombre(nombre);
            unUsuario.modificarRegistro(pos);
            accionAceptada();
        }
        else if(opcion==35){
            gotoxy(35,14);cout << "INGRESE LA NUEVA CONTRASEÑA: ";
            cin.getline(password,20);
            unUsuario.setPassword(password);
            unUsuario.modificarRegistro(pos);
            accionAceptada();
        }
        else if(opcion==55){
            gotoxy(35,14);cout << "INGRESE EL NUEVO SECTOR: ";
            gotoxy(23,15);cout << "[1-ADMINISTRACION 2-VENTAS 3-COMPRAS 4-MOVIMIENTOS]"<<endl;
            gotoxy(60,14);cin>>sector;
            while(!validar.intervaloDeNumeros(sector,1,4)){
                textcolor(cROJO_CLARO,cAZUL);gotoxy(25,16);cout << "CODIGO ERRONEO. INGRESE UN VALOR DEL 1 AL 4"<<endl;
                getch();
                textcolor(cBLANCO,cAZUL);
                gotoxy(25,16);cout << "                                              "<<endl;
                gotoxy(60,14);cout << "                   "<<endl;
                gotoxy(35,14);cout << "INGRESE EL NUEVO SECTOR: ";
                gotoxy(23,15);cout << "[1-ADMINISTRACION 2-VENTAS 3-COMPRAS 4-MOVIMIENTOS]"<<endl;
                gotoxy(60,14);cin>>sector;

            }
            unUsuario.setSector(sector);
            unUsuario.modificarRegistro(pos);
            accionAceptada();
        }
        else{ accionCancelada();
        }

    }
    else {textcolor(cROJO_CLARO,cAZUL);gotoxy(33,5);cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}
    getch();
    limpiar();
}

///FUNCIONES GLOBALES
int cuentaRegistros(char *ruta, int tamanio){

    int cantidad;
    FILE *p;
    p=fopen(ruta,"rb");
    if(p==NULL) return 0;
    fseek(p,0,2);
    cantidad=ftell(p)/tamanio;
    fclose(p);
    return cantidad;
}
void convierteAMiniscula(char *mayuscula){

        int i;
        int tam=strlen(mayuscula);
        for(i=0;i<tam;i++){
            mayuscula[i]=tolower(mayuscula[i]);
        }
}
void mostrarVector(Producto *v,int tam){

    int i;
    Producto unProducto;

    for(i=0;i<tam;i++){

        cout << v[i].getCodigoProducto()<<endl;
        cout << v[i].getDescripcion()<<endl;
        cout << "--------------------"<<endl;
    }
    cout << endl;
    cout <<endl;
}
void ordenarVector(Producto *vo, int t) {

    int i,j,pmax;
    Producto aux;

    for(i=0; i<t-1; i++) {
        pmax=i;

        for(j=i+1;j<t;j++) {

            if(vo[j].getCodigoProducto()<vo[pmax].getCodigoProducto()) pmax=j;
        }
        aux=vo[i];
        vo[i]=vo[pmax];
        vo[pmax]=aux;
    }
}
void ordenarArchivoAscendente(int cantidad){

        int pos=0;
        int i=0;
        Producto unProducto;
        Producto *vOrdenar;
        vOrdenar=new Producto[cantidad];
        while(unProducto.leerArchivo(pos)){
            vOrdenar[i]=unProducto;
            i++;
            pos++;
        }
        ordenarVector(vOrdenar,cantidad);
        pos=0;
        i=0;
        while(unProducto.leerArchivo(pos)){
            unProducto=vOrdenar[i];
            unProducto.modificarArchivo(pos);
            pos++;
            i++;
        }
        delete(vOrdenar);
}
void limpiar(){
    system("cls");
}
void gotoxy(int x, int y){

    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE); //IDENTIFICADOR DE OBJETO
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);

}
void cuentaRegresiva(int tam){
    int i;
    for(i=tam;i>0;i--){

        cout << i << "\b";
        Sleep(1000);
    }
}
bool grabarBackupProducto(Producto *Vector,int cantidad){

    bool grabo;
    FILE *p;
    p=fopen("backup/producto.dat","wb");
    if(p==NULL) return false;
    grabo=fwrite(Vector,sizeof(Producto),cantidad,p);
    fclose(p);
    return grabo;
}
bool grabarBackupProveedores(Proveedor *Vector,int cantidad){

    bool grabo;
    FILE *p;
    p=fopen("backup/proveedores.dat","wb");
    if(p==NULL) return false;
    grabo=fwrite(Vector,sizeof(Proveedor),cantidad,p);
    fclose(p);
    return grabo;
}
bool grabarRestauracionProductos(Producto *Vector,int cantidad){

    bool grabo;
    FILE *p;
    p=fopen("archivos/producto.dat","wb");
    if(p==NULL) return false;
    grabo=fwrite(Vector,sizeof(Producto),cantidad,p);
    fclose(p);
    return grabo;
}
bool grabarRestauracionProveedor(Proveedor *Vector,int cantidad){

    bool grabo;
    FILE *p;
    p=fopen("archivos/proveedores.dat","wb");
    if(p==NULL) return false;
    grabo=fwrite(Vector,sizeof(Proveedor),cantidad,p);
    fclose(p);
    return grabo;
}
void backupProductos(){

    int totalRegistros;
    int pos=0, i=0;
    Producto unProducto;
    Producto *Vproductos;
    totalRegistros=cuentaRegistros(rutaProducto,tamanioProducto);
    cout << totalRegistros<<endl;
    Vproductos=new Producto[totalRegistros];
    while(unProducto.leerArchivo(pos++)){
        Vproductos[i]=unProducto;
        i++;
    }
    grabarBackupProducto(Vproductos,totalRegistros);
    delete(Vproductos);
}
void backupProveedores(){
    int totalRegistros;
    int pos=0, i=0;
    Proveedor unProveedor;
    Proveedor *Vproveedores;
    totalRegistros=cuentaRegistros(rutaProveedores,tamanioProveedor);
    Vproveedores=new Proveedor[totalRegistros];
    while(unProveedor.leerArchivo(pos++)){
        Vproveedores[i]=unProveedor;
        i++;
    }
    grabarBackupProveedores(Vproveedores,totalRegistros);
    delete(Vproveedores);
}
void restaurarProductos(){

    int totalRegistros;
    int pos=0, i=0;
    Producto unProducto;
    Producto *Vproductos;
    totalRegistros=cuentaRegistros(rutaBackupProducto,tamanioProducto);
    Vproductos=new Producto[totalRegistros];
    while(unProducto.leerBackup(pos++)){
        Vproductos[i]=unProducto;
        i++;
    }
    grabarRestauracionProductos(Vproductos,totalRegistros);
    delete(Vproductos);

}
void restaurarProveedor(){

    int totalRegistros;
    int pos=0, i=0;
    Proveedor unProveedor;
    Proveedor *Vproveedor;
    totalRegistros=cuentaRegistros(rutaBackupProveedores,tamanioProveedor);
    Vproveedor=new Proveedor[totalRegistros];
    while(unProveedor.leerBackup(pos++)){
        Vproveedor[i]=unProveedor;
        i++;
    }
    grabarRestauracionProveedor(Vproveedor,totalRegistros);
    delete(Vproveedor);

}
char *buscarUsuario(int cod){

    Usuario unUsuario;
    int pos=0;
    while(unUsuario.leerArchivo(pos++)){
        if(unUsuario.getCodigo()==cod) return unUsuario.getNombre();
    }

}
char *buscardescripcion(int cod){
    Producto unProducto;
    int pos=0;
    while(unProducto.leerArchivo(pos++)){
        if(unProducto.getCodigoProducto()==cod) return unProducto.getDescripcion();
    }
}
int buscarStockSucursal(int cod){
    Producto unProducto;
    int pos=0;
    while(unProducto.leerArchivo(pos++)){
        if(unProducto.getCodigoProducto()==cod) return unProducto.getStockSucursal();

    }
}
char *buscarProveedor(int cod){
    Proveedor unProveedor;
    int pos=0;
    while(unProveedor.leerArchivo(pos++)){
        if(unProveedor.getCodigoProveedor()==cod) return unProveedor.getNombre();
    }
}
char *buscarRubro(int cod){

    Proveedor unProveedor;
    int pos=0;
    while(unProveedor.leerArchivo(pos++)){
        if(unProveedor.getCodigoProveedor()==cod) return unProveedor.getRubro();
    }

}
int buscarMetodoDePago(int cod){
    CabeceraVentas unaCabeceraVenta;
    int pos=0;
    while(unaCabeceraVenta.leerenDisco(pos++)){
        if(unaCabeceraVenta.getNrodeFactura()==cod) return unaCabeceraVenta.getMetodoDePago();
    }
}
int buscarSumatoriaVentas(int cod){
    DetalleVentas unDetalleVenta;
    int pos=0,total=0;
    while(unDetalleVenta.leerenDisco(pos++)){

        if(unDetalleVenta.getNroFactura()==cod) total+=(unDetalleVenta.getCantidad()*unDetalleVenta.getPrecioVenta());
    }
    return total;
}
float buscarPV(int cod){
    Producto unProducto;
    int pos=0;
    while (unProducto.leerArchivo(pos++)){
        if (unProducto.getCodigoProducto()==cod) return unProducto.getPrecioVenta();
    }
}
float buscarPC(int cod){
    Producto unProducto;
    int pos=0;
    while (unProducto.leerArchivo(pos++)){
        if (unProducto.getCodigoProducto()==cod) return unProducto.getPrecioCosto();
    }
}
void cuentaVentaUsuario(Fecha fechaDeHoy, char *usuario, int &pEfectivo, int &pDebito, int &pCredito,int &contadorEfectivo, int &contadorDebito, int &contadorCredito){

    int pos=0,pos2=0;
    CabeceraVentas unaCabeceraVenta;
    DetalleVentas unDetalleVenta;
    while(unaCabeceraVenta.leerenDisco(pos++)){
        if(unaCabeceraVenta.getFechaDeEmision()==fechaDeHoy&&(strcmp(usuario,unaCabeceraVenta.getUsuario())==0)){//COINCIDEN LA FECHA Y EL USUARIO
            if(unaCabeceraVenta.getMetodoDePago()==1) contadorEfectivo++;
            else if(unaCabeceraVenta.getMetodoDePago()==2)  contadorDebito++;
            else contadorCredito++;

            while(unDetalleVenta.leerenDisco(pos2++)){
                if(unDetalleVenta.getNroFactura()==unaCabeceraVenta.getNrodeFactura()){
                    if(unaCabeceraVenta.getMetodoDePago()==1) pEfectivo+=(unDetalleVenta.getPrecioVenta()*unDetalleVenta.getCantidad());
                    else if(unaCabeceraVenta.getMetodoDePago()==2) pDebito+=(unDetalleVenta.getPrecioVenta()*unDetalleVenta.getCantidad());
                    else pCredito+=(unDetalleVenta.getPrecioVenta()*unDetalleVenta.getCantidad());
                }
            }
            pos2=0;
        }
    }
}
void ocultarContrasenia(char *password){

    char letra;
    int i=0;
    while(true){

        letra=getch();
        if(letra==13){ //SI PRESIONA ENTER AGREGAMOS EL CARACTER PARA TERMINAR LA CADENA
            password[i]='\0';
            break;
        }
        else if(letra==8){ //SI PRESIONA LA TECLA BORRAR, VAMOS HACIA ATRAS Y BORRAMOS
            if(i>0){ //PODEMOS HACERLO MIENTRAS NO NOS ENCONTREMOS EN LA PRIMERA POSICION
                i--;
                cout<<"\b \b";
            }
        }
        else{ // EN CASO DE QUE NO SEA NINGUNA DE LAS ANTERIORES GUARDAMOS EL CARACTER EN EL VECTOR Y AUMENTAMOS EL I.
            password[i++]=letra;
            cout << "* \b";
        }
    }
}
void pantallaBienvenida(char *nombre, int sector){
    char msector[4][15];
    strcpy(msector[0],"ADMINISTRACION");
    strcpy(msector[1],"VENTAS");
    strcpy(msector[2],"COMPRAS");
    strcpy(msector[3],"MOVIMIENTOS");

    limpiar();
    recuadro(30, 8,45, 6, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(45,8);cout << "BIENVENIDO "<< nombre<<endl;
    textcolor(cBLANCO, cAZUL);
    gotoxy(33,10);cout << "SERAS DERIVADO AL SECTOR " <<msector[sector-1]<<endl;
    gotoxy(47,11);cout << "EN   SEGUNDOS";
    gotoxy(50,11);cuentaRegresiva(3);
    limpiar();
}
int navegacionMenu(int cX, int cY, int limiteA, int limiteB){ //PASA COORDENADAS Y LIMITES DE X E Y (DONDE SE MUEVE LA FLECHITA)

    char c;
    int x=cX;
    int y=cY;
    bool derivar=false;
    while(derivar==false){
        textcolor(cBLANCO, cGRIS);
        gotoxy(x,y);cout << "->";
        c=getch();
        gotoxy(x,y);cout << "  ";
            if(c==-32){ //
                c=getch();
                if(c==72){//arriba
                    if(y==limiteA) y=limiteB;
                    else y-=3;
                }
                if(c==80){//abajo
                    if(y==limiteB) y=limiteA;
                    else y+=3;
                }
            }
        gotoxy(x,y);cout << "->";
        if(c==13) derivar=true;
    }
    return y;
}
int navegacionMenuHorizontal(int cX, int cY, int limiteA, int limiteB, int valor){ //PASA COORDENADAS Y LIMITES DE X E Y (DONDE SE MUEVE LA FLECHITA)

    char c;
    int x=cX;
    int y=cY;
    bool derivar=false;
    while(derivar==false){
        gotoxy(x,y);cout << "->";
        c=getch();
        gotoxy(x,y);cout << "  ";
            if(c==-32){ //
                c=getch();
                if(c==75){//derecha
                    if(x==limiteA) x=limiteB;
                    else x-=valor;
                }
                if(c==77){//izquierda
                    if(x==limiteB) x=limiteA;
                    else x+=valor;
                }
            }
        gotoxy(x,y);cout << "->";
        if(c==13) derivar=true;
    }
    return x;
}
bool advertenciaDeBorrado(){
    int opcion;
    gotoxy(40,7);cout << "¿DESEA ELIMINARLO?"<<endl;
    recuadro(41,9,7,2, cAMARILLO, cROJO);
    recuadro(51,9,7,2, cAMARILLO, cROJO);
    gotoxy(45,10);cout << "SI"<<endl;
    gotoxy(55,10);cout << "NO"<<endl;
    opcion=navegacionMenuHorizontal(43,10,43,53,10);
        if(opcion==43)return true;
        return false;
}
bool consultaParaContinuar(){

    int opcion;
    gotoxy(40,13);cout << "DESEA CONTINUAR?"<<endl;
    recuadro(40,15,7,2, cAMARILLO, cROJO);
    recuadro(50,15,7,2, cAMARILLO, cROJO);
    gotoxy(44,16);cout << "SI"<<endl;
    gotoxy(54,16);cout << "NO"<<endl;
    opcion=navegacionMenuHorizontal(41,16,41,51,10);
    textcolor(cBLANCO,cAZUL);
    if(opcion==41)return true;
    return false;
}
bool consultaParaContinuar(int a){

    int opcion;
    gotoxy(40,a);cout << "DESEA CONTINUAR?"<<endl;
    recuadro(40,a+2,7,2, cAMARILLO, cROJO);
    recuadro(50,a+2,7,2, cAMARILLO, cROJO);
    gotoxy(44,a+3);cout << "SI"<<endl;
    gotoxy(54,a+3);cout << "NO"<<endl;
    opcion=navegacionMenuHorizontal(41,a+3,41,51,10);
    textcolor(cBLANCO,cAZUL);
    if(opcion==41)return true;
    return false;
}
void accionCancelada(){

    recuadro(33,15,35,5, cBLANCO, cROJO);
    textcolor(cAMARILLO,cROJO);
    gotoxy(48,15);cout << " AVISO "<<endl;
    textcolor(cBLANCO,cROJO);
    gotoxy(38,17);cout << "LA ACCION HA SIDO CANCELADA."<<endl;
    gotoxy(37,18);cout << "PRESIONE UNA TECLA PARA VOLVER"<<endl;
    textcolor(cBLANCO,cAZUL);
}
void accionCancelada(int a){

    recuadro(33,a,35,5, cBLANCO, cROJO);
    textcolor(cAMARILLO,cROJO);
    gotoxy(48,a);cout << " AVISO "<<endl;
    textcolor(cBLANCO,cROJO);
    gotoxy(38,a+2);cout << "LA ACCION HA SIDO CANCELADA."<<endl;
    gotoxy(37,a+3);cout << "PRESIONE UNA TECLA PARA VOLVER"<<endl;
    textcolor(cBLANCO,cAZUL);
}
void accionAceptada(){

    recuadro(33,17,35,5, cBLANCO, cVERDE);
    textcolor(cAMARILLO,cVERDE);
    gotoxy(48,17);cout << " AVISO "<<endl;
    textcolor(cBLANCO,cVERDE);
    gotoxy(38,19);cout << "LA ACCION HA SIDO EXITOSA."<<endl;
    gotoxy(36,20);cout << "PRESIONE UNA TECLA PARA VOLVER"<<endl;
    textcolor(cBLANCO,cAZUL);
}
void accionAceptada(int a){

    recuadro(33,a,35,5, cBLANCO, cVERDE);
    textcolor(cAMARILLO,cVERDE);
    gotoxy(48,a);cout << " AVISO "<<endl;
    textcolor(cBLANCO,cVERDE);
    gotoxy(38,a+2);cout << "LA ACCION HA SIDO EXITOSA."<<endl;
    gotoxy(36,a+3);cout << "PRESIONE UNA TECLA PARA VOLVER"<<endl;
    textcolor(cBLANCO,cAZUL);

}
float aproximacionDecimal(float precio){
    precio=precio*100;
    precio=ceil(precio);
    precio=precio/100;
    return precio;
}
float aproximacionPrecioVenta(float precio){

    int diferencia, precioModificado,ultimoDigito;
    precioModificado=ceil(aproximacionDecimal(precio));

    ultimoDigito=precioModificado%10;

    if(precio<5) return precio;

    if(ultimoDigito>5) {
        diferencia=10-ultimoDigito;
        precioModificado=precioModificado+diferencia;

    }
    else if(ultimoDigito<5 && ultimoDigito!=0){
        diferencia=5-ultimoDigito;
        precioModificado=precioModificado+diferencia;
    }
	precio=precioModificado;
    return precio;
}

/// MENU COMPRAS - SUBMENU PROVEEDORES
void agregarProveedor(){

    Proveedor unProveedor;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "AGREGAR PROVEEDOR"<<endl;
    textcolor(cBLANCO, cAZUL);
    unProveedor.cargarDatos();

    if(unProveedor.grabarArchivo()){
        accionAceptada(13);
    }
    else {cout <<"HA OCURRIDO UN ERROR DURANTE LA GRABACION."<<endl;}
    getch();
    limpiar();

}
void borrarProveedor(){

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "BORRAR PROVEEDOR"<<endl;
    textcolor(cBLANCO, cAZUL);
    Proveedor unProveedor;
    Validador validar;
    int codigo, pos;
    char proveedorAborrar[20];
    gotoxy(25,4);cout << "INGRESE EL CODIGO DEL PROVEEDOR QUE SE DESEE ELIMINAR: "<<endl;
    gotoxy(80,4);cin >> codigo;

    if((pos=validar.existenciaProveedor(codigo))>=0){
        unProveedor.leerArchivo(pos);
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(25,5);cout <<"EL PROVEEDOR CORRESPONDIENTE AL CODIGO ES: "<<strcpy(proveedorAborrar,buscarProveedor(unProveedor.getCodigoProveedor()));
        textcolor(cBLANCO,cAZUL);
        if(advertenciaDeBorrado()){//SE BORRA

            unProveedor.setEstado(false);
            unProveedor.modificarArchivo(pos);
            accionAceptada(15);
        }
        else accionCancelada();//NO SE BORRA
    }

    else {textcolor(cROJO_CLARO,cAZUL);gotoxy(35,5);cout << "EL PROVEEDOR INGRESADO NO EXISTE."<<endl;}

    getch();
    limpiar();
}
void listarProveedores(){

    Proveedor unProveedor;
    int pos=0;
    unProveedor.mostrarEncabezado();
    while(unProveedor.leerArchivo(pos)){
        unProveedor.mostrarArchivo();
        pos++;
   }
getch();
limpiar();

}
void listarProveedorPorCodigo(){

        Proveedor unProveedor;
        Validador validar;
        int pos,codigo;
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "BORRAR PROVEEDOR"<<endl;
        textcolor(cBLANCO, cAZUL);
        fflush(stdin);
        gotoxy(25,4);cout << "INGRESE EL CODIGO DEL PROVEEDOR QUE DESEA LISTAR: "<<endl;
        gotoxy(75,4);cin >> codigo;

        if((pos=validar.existenciaProveedor(codigo))>=0){
            unProveedor.leerArchivo(pos);
            if(unProveedor.getEstado()==true){
            limpiar();
            unProveedor.mostrarEncabezado();
            unProveedor.mostrarArchivo();
            }
            else cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;
        }
        else {textcolor(cROJO_CLARO,cAZUL);gotoxy(35,5); cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}

    getch();
    limpiar();
}
void modificarProveedor(){

    Validador validar;
    Proveedor unProveedor;
    RetencionesImpositivas ri;
    Producto unProducto;
    int codigo,pos,opcion;
    char nombre [20];
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "MODIFICAR PROVEEDOR"<<endl;
    textcolor(cBLANCO, cAZUL);

    gotoxy(35,4);cout << "INGRESE CODIGO DE PROVEEDOR: ";
    cin >> codigo;
    if((pos=validar.existenciaProveedor(codigo))>=0){
        unProveedor.leerArchivo(pos);
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(35,5);cout << "NOMBRE: "<<unProveedor.getNombre()<<endl;
        gotoxy(35,6);cout << "RETENCIONES IMPOSITIVAS: "<<endl;
        gotoxy(35,7);cout << "IVA: "<<unProveedor.getPorcentuales().getIVA()<<endl;
        gotoxy(35,8);cout << "IB: "<<unProveedor.getPorcentuales().getIB()<<endl;
        gotoxy(35,9);cout << "PERCEPCION: "<<unProveedor.getPorcentuales().getPercepcion()<<endl;
        textcolor(cBLANCO,cAZUL);gotoxy(40,11);cout << "QUE DESEA MODIFICAR?"<<endl;
        recuadro(24,13,16,2, cAMARILLO, cROJO);
        recuadro(44,13,16,2, cAMARILLO, cROJO);
        recuadro(64,13,16,2, cAMARILLO, cROJO);
        gotoxy(30,14);cout << "NOMBRE";
        gotoxy(48,14);cout << "RETENCIONES";
        gotoxy(73,14);cout << "SALIR";
        opcion=navegacionMenuHorizontal(25,14,25,65,20);
        textcolor(cBLANCO,cAZUL);
        if(opcion==25){
            fflush(stdin);
            gotoxy(35,17);cout << "INGRESE LA NUEVA DESCRIPCION: ";
            cin.getline(nombre,20);
            unProveedor.setNombre(nombre);
            unProveedor.modificarArchivo(pos);
            accionAceptada(19);
        }
        else if(opcion==45){
            ri.cargarDatosVertical();
            unProveedor.setPorcentuales(ri);
            unProveedor.modificarArchivo(pos);
            pos=0;
            while(unProducto.leerArchivo(pos)){
                if(codigo==unProducto.getCodigoProveedor()){
                    unProducto.setPorcentuales(ri);
                    unProducto.modificarArchivo(pos);
                }
                pos++;
            }
            accionAceptada(19);
        }
        else {accionCancelada(19);}

    }
    else {cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}
    getch();
    limpiar();


}

/// MENU COMPRAS - SUBMENU PRODUCTOS
void agregarProducto(){

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "AGREGAR PRODUCTO"<<endl;
    textcolor(cBLANCO, cAZUL);
    gotoxy(1,5);
    Producto unProducto;
    Proveedor unProveedor;
    RetencionesImpositivas ri;
    unProducto.cargarDatos();
    int pos=0;
    while(unProveedor.leerArchivo(pos)){
        if(unProducto.getCodigoProveedor()==unProveedor.getCodigoProveedor()){
            //BUSCO EL PROVEEDOR CORRESPONDIENTE Y LE ASIGNO LOS PORCENTUALES CORRESPONDIENTES AL PRODUCTO
            ri.setIVA(unProveedor.getPorcentuales().getIVA());
            ri.setPercepcion(unProveedor.getPorcentuales().getPercepcion());
            ri.setIB(unProveedor.getPorcentuales().getIB());
            unProducto.setPorcentuales(ri);
        }
        pos++;
    }
    unProducto.grabarArchivo();
    ordenarArchivoAscendente(cuentaRegistros(rutaProducto,tamanioProducto));
    getch();
    limpiar();
}
void listarProductos(){

    int pos=0;
    Producto unProducto;
    unProducto.mostrarEncabezado();
    while(unProducto.leerArchivo(pos++)){
        unProducto.mostrarProducto();
    }
    getch();
    system("cls");
}
void listarProductoPorCodigo(){

    Validador validar;
    Producto unProducto;
    int cod;
    int pos;
    recuadro(0, 0,102, 25, cBLANCO, cAZUL);
    recuadro(0, 0,102, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,1);cout << "LISTAR PRODUCTO POR CODIGO"<<endl;
    cout << endl;
    cout << "INGRESE EL CODIGO DEL PRODUCTO A LISTAR: ";
    cin >> cod;

    if((pos=validar.existenciaCodigo(cod))>=0){

        unProducto.leerArchivo(pos);
        limpiar();
        unProducto.mostrarEncabezado();
        unProducto.mostrarProducto();
    }
    else {
        cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
    }
system("pause");
system("cls");
}
void borrarProducto(){

    recuadro(0, 0,102, 25, cBLANCO, cAZUL);
    recuadro(0, 0,102, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,1);cout << "BORRAR PRODUCTO"<<endl;

    Producto unProducto;
    Validador validar;
    int cod, pos;
    char productoAborrar[20];
    gotoxy(30,4);cout << "INGRESE EL CODIGO DEL PRODUCTO A BORRAR: "<<endl;
    gotoxy(70,4);cin >> cod;
    if((pos=validar.existenciaCodigo(cod))>=0){
        unProducto.leerArchivo(pos);
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(25,5);cout <<"EL PRODUCTO CORRESPONDIENTE AL CODIGO ES: "<<strcpy(productoAborrar,buscardescripcion(unProducto.getCodigoProducto()));
        textcolor(cBLANCO,cAZUL);
        if(advertenciaDeBorrado()){//SE BORRA
            unProducto.setEstado(false);
            unProducto.modificarArchivo(pos);
            accionAceptada(13);
        }
        else accionCancelada(13);//NO SE BORRA
    }
    else{
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(35,5); cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
    }
getch();
system("cls");
}
void modificarProducto(){

    Validador validar;
    Producto unProducto;

    int codigo,pos,opcion;
    char descripcion [20],proveedor[20];
    recuadro(0, 0,102, 25, cBLANCO, cAZUL);
    recuadro(0, 0,102, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,1);cout << "MODIFICAR PRODUCTO"<<endl;
    gotoxy(30,4);cout << "INGRESE EL CODIGO DEL PRODUCTO: "<<endl;
    gotoxy(62,4);cin >> codigo;

    if((pos=validar.existenciaCodigo(codigo))>=0){

        unProducto.leerArchivo(pos);
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(30,5);cout << "DESCRIPCION: "<<strcpy(descripcion,buscardescripcion(unProducto.getCodigoProducto()))<<endl;
        gotoxy(30,6);cout << "PROVEEDOR: "<<strcpy(proveedor,buscarProveedor(unProducto.getCodigoProveedor()))<<endl;
        gotoxy(37,8);cout << "¿QUE DESEA MODIFICAR?"<<endl;
        recuadro(30,10,16,2, cAMARILLO, cROJO);
        recuadro(54,10,16,2, cAMARILLO, cROJO);
        gotoxy(34,11);cout << "DESCRIPCION";
        gotoxy(63,11);cout << "SALIR";
        fflush(stdin);
        opcion=navegacionMenuHorizontal(31,11,31,55,24);
        if(opcion==31){//OPCION DESCRIPCION
            textcolor(cBLANCO,cAZUL);
            gotoxy(30,14);cout << "INGRESE LA NUEVA DESCRIPCION: "<<endl;
            gotoxy(60,14);cin.getline(descripcion,20);
            convierteAMiniscula(descripcion);
            unProducto.setDescipcion(descripcion);
            unProducto.modificarArchivo(pos);
            accionAceptada();
        }
        else{accionCancelada();}
    }
    else {cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}
    getch();
    limpiar();
}

/// MENU COMPRAS
void agregarCompra(char *usuario){
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "AGREGAR COMPRA"<<endl;

    bool seguir=true;
    Validador validar;
    Producto unProducto;
    CabeceraCompra unaCabeceraCompra;
    DetalleCompra unDetalleCompra;
    int stockAnterior,pos=0, cuentaLinea=1;
    float stockValorizado,subTotalCompra,costoReal;
    fflush(stdin);
    unaCabeceraCompra.cargarDatos(usuario);

        while(seguir==true){
            recuadro(1, 1,100, 25, cBLANCO, cAZUL);
            recuadro(1, 1,100, 2, cBLANCO, cAZUL);
            textcolor(cBLANCO,cAZUL);
            gotoxy(40,2);cout << "AGREGAR COMPRA"<<endl;
            unaCabeceraCompra.mostrarDatosCargados();
            unDetalleCompra.cargarDatos(unaCabeceraCompra.getNrodeFactura(),cuentaLinea,unaCabeceraCompra.getCodigoProveedor()); //SET NRO FACTURA, NRO DE LINEA, PROVEEDOR
            pos=validar.existenciaCodigo(unDetalleCompra.getcodigoProducto());//BUSCA EL PRODUCTO A TRAVES DEL CODIGO
            unProducto.leerArchivo(pos);//CARGA OBJETO
            unDetalleCompra.calculoPrecioBruto(unProducto);//CALCULA EL PRECIO BRUTO LLENA PRECIO BRUTO.
            subTotalCompra= unDetalleCompra.getCantidad()*unDetalleCompra.getPrecioBruto();//ARROJA EL SUBTOTAL DE LA COMPRA DEL PRODUCTO
            stockAnterior=unProducto.getStockSucursal()+unProducto.getStockDeposito();  //SUMA TODO EL STOCK ANTERIOR
            stockValorizado=stockAnterior*unProducto.getPrecioCosto();//MULTIPLICA EL PRECIO VIEJO POR EL EL STOCK ANTERIOR
            costoReal= (stockValorizado+subTotalCompra)/(stockAnterior+unDetalleCompra.getCantidad()); //TOMA LOS PRECIOS (ANTERIOR Y ACTUAL) Y REALIZA UN PROMEDIO CON EL TOTAL DE MERCADERIA, OBTENIENDO EL COSTO REAL DEL PRODUCTO.
            unDetalleCompra.setPrecioVenta(costoReal+(costoReal*unProducto.getRentabilidad()/100));//CALCULA EL PRECIO DE VENTA  ((unProducto.getRentabilidad()/100)+1)*costoReal
            unProducto.cargarDatosCompra(unDetalleCompra.getPrecioVenta(),costoReal,unDetalleCompra.getCantidad()+unProducto.getStockDeposito()); //SET DE STOCK-COSTO-VENTA DEL PRODUCTO CARGADO

            /*cout << "STOCK ANTERIOR: " << stockAnterior <<endl;
            cout << "STOCK VALORIZADO: " << stockValorizado <<endl;
            cout << "SUBTOTAL: " << subTotalCompra <<endl;
            cout << "COSTO REAL: "<<costoReal<<endl;
            cout << "RENTABILIDAD: "<< unProducto.getRentabilidad()<<endl;
            cout << "PRECIO VENTA:" << unDetalleCompra.getPrecioVenta()<<endl;
            */
            seguir=consultaParaContinuar();
            limpiar();
            unDetalleCompra.grabarArchivo();
            unProducto.modificarArchivo(pos);
            unaCabeceraCompra.leerArchivo(unDetalleCompra.getNroFactura()-1);
            unaCabeceraCompra.mostrarArchivo();
            unDetalleCompra.mostrarEncabezado();

            pos=0;
            while(unDetalleCompra.leerArchivo(pos)){
                if(unDetalleCompra.getNroFactura()==unaCabeceraCompra.getNrodeFactura()) unDetalleCompra.mostrarArchivo();
            pos++;
            }
            cuentaLinea++;
            getch();
            limpiar();

        }
            unaCabeceraCompra.grabarArchivo();
    }
void listarTodasLasCompras(){

    CabeceraCompra unaCabeceraCompra;
    DetalleCompra unDetalleCompra;

    int posC=0, posD=0;

    while(unaCabeceraCompra.leerArchivo(posC)){
        unaCabeceraCompra.mostrarArchivo();
        unDetalleCompra.mostrarEncabezado();
            while(unDetalleCompra.leerArchivo(posD)){
                if(unaCabeceraCompra.getNrodeFactura()==unDetalleCompra.getNroFactura()){
                    unDetalleCompra.mostrarArchivo();
                }
                posD++;
            }
        getch();
        limpiar();
        posD=0;
        posC++;
    }
}
void listarComprasPorCodigo(){

    CabeceraCompra unaCabeceraCompra;
    DetalleCompra unDetalleCompra;
    int nroFactura;
    int pos=0;
    bool cabeceraImpresa=false;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "LISTAR COMPRAS POR CODIGO"<<endl;
    textcolor(cBLANCO, cAZUL);
    gotoxy(25,4);cout << "INGRESE EL NUMERO DE LA FACTURA QUE DESEA CONSULTAR: ";
    cin >> nroFactura;
    limpiar();
    while(unDetalleCompra.leerArchivo(pos)){
        if(unDetalleCompra.getNroFactura()==nroFactura) {
            if(!cabeceraImpresa){
                unaCabeceraCompra.leerArchivo(nroFactura-1);
                unaCabeceraCompra.mostrarArchivo();
                cabeceraImpresa=true;
            }
            unDetalleCompra.mostrarArchivo();
        }
        pos++;
    }
    if(!cabeceraImpresa) cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
    getch();
    limpiar();
}

/// MENU VENTAS
void agregarVenta(char *usuario){

CabeceraVentas unaCabeceraVenta;
DetalleVentas unDetalleVenta;
Producto unProducto;
Validador validar;
unaCabeceraVenta.cargarDatos(usuario);
int cuentaLinea=1,pos;
bool seguir=true;

while(seguir==true){

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "AGREGAR VENTAS"<<endl;
    textcolor(cBLANCO, cAZUL);
    unDetalleVenta.cargarArchivo(unaCabeceraVenta.getNrodeFactura(),cuentaLinea);
    pos=validar.existenciaCodigo(unDetalleVenta.getcodigoProducto());
    unProducto.leerArchivo(pos);
    unProducto.setStockSucursal(unProducto.getStockSucursal()-unDetalleVenta.getCantidad());
    seguir=consultaParaContinuar();
    unProducto.modificarArchivo(pos);
    unDetalleVenta.grabarenDisco();
    if(seguir==true){//SI RESPONDE QUE SI MUESTRA COMO VA QUEDANDO LA FACTURA
        unaCabeceraVenta.mostrarArchivo();
        unDetalleVenta.mostrarEncabezado();
        pos=0;
        while(unDetalleVenta.leerenDisco(pos++)){
            if(unaCabeceraVenta.getNrodeFactura()==unDetalleVenta.getNroFactura()) unDetalleVenta.mostrarArchivo();
        }
        getch();
    }
    cuentaLinea++;
    }
    limpiar();
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "AGREGAR VENTAS"<<endl;
    textcolor(cBLANCO, cAZUL);

    unaCabeceraVenta.setMetodoDePago(unDetalleVenta.calculoConFormaDePago());
    unaCabeceraVenta.grabarenDisco();
    if(unaCabeceraVenta.getMetodoDePago()==1){unDetalleVenta.calculoDeVuelto();};
    getch();
    unaCabeceraVenta.mostrarArchivo();
    unDetalleVenta.mostrarEncabezado();
    pos=0;
    while(unDetalleVenta.leerenDisco(pos++)){
        if(unaCabeceraVenta.getNrodeFactura()==unDetalleVenta.getNroFactura()) unDetalleVenta.mostrarArchivo();
    }
    unDetalleVenta.mostrarPieDePagina(unaCabeceraVenta.getNrodeFactura());
    getch();
    limpiar();

}
void cierreDeCaja(char *usuario){

    Fecha fechaDeHoy;
    int inicioDeCaja;
    int totalVentasEfectivo=0, totalVentasDebito=0, totalVentasCredito=0, cantidadVentasEfectivo=0, cantidadVentasDebito=0, cantidadVentasCredito=0;

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "CIERRE DE CAJA"<<endl;
    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(40,5);cout << "USUARIO: "<< usuario<<endl;
    gotoxy(40,6);cout << "FECHA: "<< fechaDeHoy.getDia()<<"/"<<fechaDeHoy.getMes()<<"/"<<fechaDeHoy.getAnio()<<endl;
    textcolor(cBLANCO, cAZUL);
    gotoxy(40,7);cout << "INICIO DE CAJA: ";
    cin >> inicioDeCaja;
    cuentaVentaUsuario(fechaDeHoy,usuario,totalVentasEfectivo,totalVentasDebito,totalVentasCredito,cantidadVentasEfectivo, cantidadVentasDebito, cantidadVentasCredito);
    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(40,8);cout << "CANTIDAD VENTAS EFECTIVO: "<<cantidadVentasEfectivo<<endl;
    gotoxy(40,9);cout << "TOTAL VENTAS EN EFECTIVO: "<<totalVentasEfectivo<<endl;
    gotoxy(40,10);cout << "CANTIDAD VENTAS DEBITO: "<<cantidadVentasDebito<<endl;
    gotoxy(40,11);cout << "TOTAL VENTAS CON TARJETA DE DEBITO: "<<totalVentasDebito<<endl;
    gotoxy(40,12);cout << "CANTIDAD DE VENTAS CON TARJETA DE CREDITO: "<<cantidadVentasCredito<<endl;
    gotoxy(40,13);cout << "TOTAL VENTAS CON TARJETA DE CREDITO: "<<int(totalVentasCredito*1.08)<<endl;
    gotoxy(40,14);cout << "TOTAL A ENTREGAR: "<< inicioDeCaja+totalVentasEfectivo+totalVentasDebito+totalVentasCredito<<endl;
    getch();
    system("cls");
}
void listarVentasPorCodigo(){

    CabeceraVentas unaCabeceraVenta;
    DetalleVentas unDetalleVenta;
    int nroFactura;
    int pos=0;
    bool cabeceraImpresa=false,detalleImpreso=false;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "CONSULTAR VENTAS"<<endl;
    textcolor(cBLANCO, cAZUL);

    gotoxy(20,4);cout << "INGRESE EL NUMERO DE LA FACTURA QUE DESEA CONSULTAR: ";
    cin >> nroFactura;

    while(unDetalleVenta.leerenDisco(pos)){
        if(unDetalleVenta.getNroFactura()==nroFactura) {
            if(!cabeceraImpresa){
                unaCabeceraVenta.leerenDisco(nroFactura-1);
                unaCabeceraVenta.mostrarArchivo();
                unDetalleVenta.mostrarEncabezado();
                cabeceraImpresa=true;
            }
            unDetalleVenta.mostrarArchivo();
            detalleImpreso=true;
        }
        pos++;
    }
    if(detalleImpreso) unDetalleVenta.mostrarPieDePagina(nroFactura);
    textcolor(cROJO_CLARO,cAZUL);
    if(!cabeceraImpresa) {gotoxy(35,5);cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;}
    getch();
    limpiar();
}

/// MENU MOVIMIENTOS
void transferenciaDeMercaderia(char*usuario, int tipo){

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "TRANSFERENCIA DE MERCADERIA"<<endl;
    textcolor(cBLANCO, cAZUL);

    int cantidadATransferir, pos=0, nroLinea=1, totalATransferir=0;
    bool continuar;
    bool mostrarCabecera=false, muestraCabecera=false;
    Producto unProducto;
    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimiento;
    unaCabeceraMovimiento.cargarDatos(usuario,tipo);
    while(unProducto.leerArchivo(pos)){ //IMPRIME LOS FALTANTES
            if(unProducto.getStockSucursal()<unProducto.getStockCritico()&&unProducto.getStockDeposito()>0&&unProducto.getEstado()==true){
                if(muestraCabecera==false) unDetalleMovimiento.mostrarEncabezadoFaltantes();
                unDetalleMovimiento.mostrarFaltantes(pos);
                muestraCabecera=true;
            }
        pos++;
    }
    if(muestraCabecera==true){
    continuar=consultaParaContinuar(18);
    if(continuar==true){ //REALIZA LA TRANSFERENCIA DE TODOS LOS PROUDCTOS QUE HACE FALTA
    pos=0;
        while(unProducto.leerArchivo(pos)){
            if(unProducto.getStockSucursal()<unProducto.getStockCritico()&&unProducto.getStockDeposito()>0&&unProducto.getEstado()==true){//SI EL SS ES MENOR AL CRITICO Y SI HAY PARA TRANSFERIR EN DEPOSITO
                cantidadATransferir= unProducto.getStockCritico()-unProducto.getStockSucursal();
                while(totalATransferir<cantidadATransferir&&unProducto.getStockDeposito()-totalATransferir>=unProducto.getCantidadxBulto()&&totalATransferir<unProducto.getStockDeposito()){
                    totalATransferir+=unProducto.getCantidadxBulto();
                }
                while(totalATransferir<cantidadATransferir&&totalATransferir<unProducto.getStockDeposito()){
                    totalATransferir+=1;
                }
                unProducto.cargarStock(totalATransferir);
                unDetalleMovimiento.cargarDatos(unaCabeceraMovimiento.getNrodeFactura(),nroLinea,unProducto.getCodigoProducto(),totalATransferir);
                unDetalleMovimiento.grabarArchivo();
                unProducto.modificarArchivo(pos);
                totalATransferir=0;
            }
            nroLinea++;
            pos++;
        }
        unaCabeceraMovimiento.grabarArchivo();
        accionAceptada(18);
    }
    else {accionCancelada(18);}
    }
    else {gotoxy(38,5);textcolor(cROJO_CLARO,cAZUL);cout << "NO HAY PRODUCTOS A TRANSFERIR"<<endl;}
    getch();
    limpiar();
}
void devolucionDeMercaderia(char *usuario, int tipo){

    int codigo, pos,nroLinea=1, pos2;
    bool seguir=true;
    Validador validar;
    Producto unProducto;
    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimiento;
    unaCabeceraMovimiento.cargarDatos(usuario,tipo); //CARGO LA CABECERA

    while(seguir==true){
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "DEVOLUCION DE MERCADERIA"<<endl;
        unDetalleMovimiento.cargarDatosDevoluciones(unaCabeceraMovimiento.getNrodeFactura(),nroLinea); //PIDO LOS DATOS, CARGO EL DETALLE
        pos=validar.existenciaCodigo(unDetalleMovimiento.getcodigoProducto()); //BUSCO EL PRODUCTO
        unProducto.leerArchivo(pos);
        unProducto.setStockSucursal(unProducto.getStockSucursal()-unDetalleMovimiento.getCantidad());//RESTO EL STOCK
        unProducto.modificarArchivo(pos);
        unDetalleMovimiento.setPrecioCosto(unProducto.getPrecioCosto());
        unDetalleMovimiento.grabarArchivo();
        seguir=consultaParaContinuar();
        nroLinea++;
        limpiar();
    }
    unaCabeceraMovimiento.grabarArchivo();
}
void listadoDeMovimientos(){

    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimiento;
    Validador validar;
    bool cabeceraActiva=false;
    int opcion;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "LISTADO DE MOVIMIENTOS"<<endl;
    textcolor(cBLANCO, cAZUL);

    gotoxy(40,4);cout << "¿QUE DESEA LISTAR?"<<endl;
    gotoxy(35,5);cout << "[1-TRANSFERENCIAS 2-DEVOLUCIONES]"<<endl;
    gotoxy(60,4);cin >> opcion;
    while(!validar.intervaloDeNumeros(opcion,1,2)){
        gotoxy(40,6);cout << "OPCION INCORRECTA. "<<endl;
        getch();
        gotoxy(40,6);cout <<"                     "<<endl;
        gotoxy(60,4);cout<<"         "<<endl;
        gotoxy(40,4);cout << "¿QUE DESEA LISTAR?"<<endl;
        gotoxy(35,5);cout << "[1-TRANSFERENCIAS 2-DEVOLUCIONES]"<<endl;
        gotoxy(60,4);cin >> opcion;

    }


    limpiar();
    int pos=0, pos2=0;
    while(unaCabeceraMovimiento.leerArchivo(pos++)){
        if(unaCabeceraMovimiento.getTipo()==opcion){
            unaCabeceraMovimiento.mostrarArchivo();
            while(unDetalleMovimiento.leerArchivo(pos2++)){
                if(unaCabeceraMovimiento.getNrodeFactura()==unDetalleMovimiento.getNroFactura()){
                    if(cabeceraActiva==false){
                       unDetalleMovimiento.mostrarEncabezado();
                       cabeceraActiva=true;
                    }
                unDetalleMovimiento.mostrarArchivo();
                }
            }
getch();
limpiar();
        }
    pos2=0;
    cabeceraActiva=false;
}
}

///SUBMENU REPORTES
void reporteDeganancia(){

    Fecha fechaInicio;
    Fecha fechaFin;
    CabeceraVentas unaCabeceraVenta;
    DetalleVentas unDetalleVenta;
    int acumulaPV=0;
    float acumulaPC=0.00;
    int pos=0, pos2=0, opcion;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "REPORTE DE GANANCIAS"<<endl;
    textcolor(cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);gotoxy(40,11);cout << "QUE DESEA CONSULTAR?"<<endl;
    recuadro(24,13,16,2, cAMARILLO, cROJO);
    recuadro(44,13,16,2, cAMARILLO, cROJO);
    recuadro(64,13,16,2, cAMARILLO, cROJO);
    gotoxy(30,14);cout << "FECHA";
    gotoxy(48,14);cout << "INTERVALO";
    gotoxy(73,14);cout << "SALIR";
    opcion=navegacionMenuHorizontal(25,14,25,65,20);


    if(opcion==45){
        limpiar();
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "REPORTE DE GANANCIAS"<<endl;
        textcolor(cBLANCO, cAZUL);
        gotoxy(25,5);cout <<"-->>INDIQUE FECHA DE INICIO DE CONSULTA<<--"<<endl;
        fechaInicio.cargarDatos();
        gotoxy(25,5);cout <<"-->>INDIQUE FECHA DEL FINAL DE LA CONSULTA<<--"<<endl;
        gotoxy(40,6);cout <<"                                           "<<endl;
        gotoxy(40,7);cout <<"                                           "<<endl;
        gotoxy(40,8);cout <<"                                           "<<endl;
        fechaFin.cargarDatos();

        while(fechaFin<fechaInicio){
            textcolor(cROJO_CLARO,cAZUL);
            gotoxy(23,10);cout << "LA FECHA INGRESADA DEBE SER MAYOR A LA DE INICIO."<<endl;
            getch();
            gotoxy(23,10);cout << "                                                 "<<endl;
            textcolor(cBLANCO, cAZUL);
            gotoxy(25,5);cout <<"-->>INDIQUE FECHA DEL FINAL DE LA CONSULTA<<--"<<endl;
            gotoxy(40,6);cout <<"                                           "<<endl;
            gotoxy(40,7);cout <<"                                           "<<endl;
            gotoxy(40,8);cout <<"                                           "<<endl;
            fechaFin.cargarDatos();
        }
        limpiar();
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "REPORTE DE GANANCIAS"<<endl;
        textcolor(cBLANCO, cAZUL);
        gotoxy(30,5);cout << "FECHA INICIO: "; fechaInicio.mostrarArchivo();
        gotoxy(30,6);cout << "FECHA DE FINALIZACION: ";fechaFin.mostrarArchivo();

        while(unaCabeceraVenta.leerenDisco(pos)){
            if(unaCabeceraVenta.getFechaDeEmision()>=fechaInicio&&unaCabeceraVenta.getFechaDeEmision()<=fechaFin){

                while(unDetalleVenta.leerenDisco(pos2++)){
                    if(unaCabeceraVenta.getNrodeFactura()==unDetalleVenta.getNroFactura()) {
                        acumulaPV+=(buscarPV(unDetalleVenta.getcodigoProducto())*unDetalleVenta.getCantidad());
                        acumulaPC+=(buscarPC(unDetalleVenta.getcodigoProducto())*unDetalleVenta.getCantidad());
                    }
                }
                pos2=0;
            }
            pos++;
        }
        gotoxy(30,10);cout<<"PRECIO COSTO: "<< acumulaPC<<endl;
        gotoxy(30,11);cout<<"PRECIO VENTA: "<< acumulaPV<<endl;
        gotoxy(30,12);cout << "GANANCIA: "<<acumulaPV-acumulaPC;

        }

    else if(opcion==25){

        limpiar();
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "REPORTE DE GANANCIAS"<<endl;
        textcolor(cBLANCO, cAZUL);
        gotoxy(30,5);cout <<"-->>INDIQUE FECHA DE CONSULTA<<--"<<endl;
        fechaInicio.cargarDatos();
        gotoxy(30,9);cout << "FECHA DE CONSULTA: ";
        fechaInicio.mostrarArchivo();

        while(unaCabeceraVenta.leerenDisco(pos)){
            if(unaCabeceraVenta.getFechaDeEmision()==fechaInicio){
                while(unDetalleVenta.leerenDisco(pos2++)){
                    if(unaCabeceraVenta.getNrodeFactura()==unDetalleVenta.getNroFactura()) {
                        acumulaPV+=(buscarPV(unDetalleVenta.getcodigoProducto())*unDetalleVenta.getCantidad());
                        acumulaPC+=(buscarPC(unDetalleVenta.getcodigoProducto())*unDetalleVenta.getCantidad());
                    }
                }
                pos2=0;
            }
            pos++;
        }
        gotoxy(30,10);cout<<"PRECIO COSTO: "<< acumulaPC<<endl;
        gotoxy(30,11);cout<<"PRECIO VENTA: "<< acumulaPV<<endl;
        gotoxy(30,12);cout << "GANANCIA: "<<acumulaPV-acumulaPC;
    }
    else{accionCancelada(18);}
    getch();
    limpiar();
}
void reporteDePerdida(){

    Fecha fechaInicio;
    Fecha fechaFin;
    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimientos;
    float acumulaPC=0;
    int pos=0, pos2=0,opcion;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "REPORTE DE PERDIDAS"<<endl;
    textcolor(cBLANCO,cAZUL);gotoxy(40,11);cout << "QUE DESEA CONSULTAR?"<<endl;
    recuadro(24,13,16,2, cAMARILLO, cROJO);
    recuadro(44,13,16,2, cAMARILLO, cROJO);
    recuadro(64,13,16,2, cAMARILLO, cROJO);
    gotoxy(30,14);cout << "FECHA";
    gotoxy(48,14);cout << "INTERVALO";
    gotoxy(73,14);cout << "SALIR";
    opcion=navegacionMenuHorizontal(25,14,25,65,20);


    if(opcion==45){
        limpiar();
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "REPORTE DE PERDIDAS"<<endl;
        gotoxy(25,5);cout <<"-->>INDIQUE FECHA DE INICIO DE CONSULTA<<--"<<endl;
        fechaInicio.cargarDatos();
        gotoxy(25,5);cout <<"-->>INDIQUE FECHA DEL FINAL DE LA CONSULTA<<--"<<endl;
        gotoxy(40,6);cout <<"                                           "<<endl;
        gotoxy(40,7);cout <<"                                           "<<endl;
        gotoxy(40,8);cout <<"                                           "<<endl;
        fechaFin.cargarDatos();

        while(fechaFin<fechaInicio){
            textcolor(cROJO_CLARO,cAZUL);
            gotoxy(23,10);cout << "LA FECHA INGRESADA DEBE SER MAYOR A LA DE INICIO."<<endl;
            getch();
            gotoxy(23,10);cout << "                                                 "<<endl;
            textcolor(cBLANCO, cAZUL);
            gotoxy(25,5);cout <<"-->>INDIQUE FECHA DEL FINAL DE LA CONSULTA<<--"<<endl;
            gotoxy(40,6);cout <<"                                           "<<endl;
            gotoxy(40,7);cout <<"                                           "<<endl;
            gotoxy(40,8);cout <<"                                           "<<endl;
            fechaFin.cargarDatos();
        }
        limpiar();
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "REPORTE DE GANANCIAS"<<endl;
        textcolor(cBLANCO, cAZUL);
        gotoxy(30,5);cout << "FECHA INICIO: "; fechaInicio.mostrarArchivo();
        gotoxy(30,6);cout << "FECHA DE FINALIZACION: ";fechaFin.mostrarArchivo();
        while(unaCabeceraMovimiento.leerArchivo(pos)){
            if(unaCabeceraMovimiento.getFechaDeEmision()>=fechaInicio&&unaCabeceraMovimiento.getFechaDeEmision()<=fechaFin){
                while(unDetalleMovimientos.leerArchivo(pos2++)){
                    if(unaCabeceraMovimiento.getNrodeFactura()==unDetalleMovimientos.getNroFactura()) {
                        acumulaPC+=(unDetalleMovimientos.getPrecioCosto()*unDetalleMovimientos.getCantidad());
                    }
                }
                pos2=0;
            }
            pos++;
        }
        gotoxy(33,7);cout << "TOTAL PERDIDA: "<<acumulaPC<<endl;
    }

    else if(opcion==25){

        limpiar();
        recuadro(1, 1,100, 25, cBLANCO, cAZUL);
        recuadro(1, 1,100, 2, cBLANCO, cAZUL);
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,2);cout << "REPORTE DE PERDIDAS"<<endl;
        gotoxy(30,5);cout <<"-->>INDIQUE FECHA DE CONSULTA<<--"<<endl;
        fechaInicio.cargarDatos();
        gotoxy(30,9);cout << "FECHA DE CONSULTA: ";
        fechaInicio.mostrarArchivo();

        while(unaCabeceraMovimiento.leerArchivo(pos)){
            if(unaCabeceraMovimiento.getFechaDeEmision()>=fechaInicio&&unaCabeceraMovimiento.getFechaDeEmision()<=fechaFin){
                while(unDetalleMovimientos.leerArchivo(pos2++)){
                    if(unaCabeceraMovimiento.getNrodeFactura()==unDetalleMovimientos.getNroFactura()) {
                        acumulaPC+=(unDetalleMovimientos.getPrecioCosto()*unDetalleMovimientos.getCantidad());
                    }
                }
                pos2=0;
            }
            pos++;
        }
        gotoxy(33,10);cout << "TOTAL PERDIDA: "<<acumulaPC<<endl;
    }

    else{accionCancelada(18);}

    getch();
    limpiar();

}
void backupDeArchivos(){

    bool seguir;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "BACKUPS DE ARCHIVOS"<<endl;
    gotoxy(25,6);cout << "SE REALIZARA EL BACKUP DE PRODUCTOS Y PROVEEDORES"<<endl;
    seguir=consultaParaContinuar(8);
    if(seguir==true){
        backupProveedores();
        backupProductos();
        accionAceptada(15);
    }
    else{accionCancelada();}
    getch();
    limpiar();
}
void restaurarArchivos(){

    bool seguir;
    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,2);cout << "RESTAURACION DE ARCHIVOS"<<endl;
    gotoxy(25,6);cout << "SE REALIZARA LA RESTAURACION DE PRODUCTOS Y PROVEEDORES"<<endl;
    seguir=consultaParaContinuar(8);
    if(seguir==true){
        restaurarProveedor();
        restaurarProductos();
        accionAceptada(15);
    }
    else{accionCancelada();}

    getch();
    limpiar();

}

#endif // FUNCIONES_H_INCLUDE
