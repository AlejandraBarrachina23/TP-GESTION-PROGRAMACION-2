#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "menues.h"
#include <conio.h>
#include <windows.h>
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
    cout << "====================================================================================================="<<endl;
    cout << "                                           AGREGAR USUARIO"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;
    unUsuario.cargarDatos();
    unUsuario.grabarArchivo();
    cout <<"EL USUARIO HA SIDO CARGADO EN FORMA EXITOSA."<<endl;
    getch();
    limpiar();
    }
void borrarUsuario(){

    Usuario unUsuario;
    Validador validar;
    int pos,codigo;

    cout << "====================================================================================================="<<endl;
    cout << "                                           BORRAR USUARIO"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;

    cout << "INGRESE CODIGO DEL USUARIO: ";
    cin >> codigo;

    if((pos=validar.existenciaCodigoUsuario(codigo))>=0){
        unUsuario.leerArchivo(pos);
        unUsuario.setEstado(false);
        unUsuario.modificarRegistro(pos);
        cout << "EL USUARIO HA SIDO ELIMINADO EN FORMA EXITOSA."<<endl;
        system("pause");
        system("cls");
    }
    else {cout << "EL NOMBRE INGRESADO NO PERTENECE A UN EMPLEADO EXISTENTE."<<endl;}
}
void listarUsuarios(){

    cout << "========================================================================="<<endl;
    cout << "                              USUARIOS      "<<endl;
    cout << "========================================================================="<<endl;

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
    cout << "INGRESE EL CODIGO DEL USUARIO QUE DESEE LISTAR: ";
    cin >> codigo;

    if((pos=validar.existenciaCodigoUsuario(codigo))>=0){
        limpiar();
        Unusuario.leerArchivo(pos);
        Unusuario.mostrarEncabezado();
        Unusuario.mostrarArchivo();
    }
    else {cout << "EL CODIGO DE USUARIO INGRESADO NO EXISTE."<<endl;}
    getch();
    limpiar();
}
void modificarUsuario(){


    Validador validar;
    Usuario unUsuario;
    int pos=0, codigo;
    char nombre[20];

    cout << "====================================================================================================="<<endl;
    cout << "                                    MODIFICAR USUARIO"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;

    cout << "INGRESE EL CODIGO DEL USUARIO A MODIFICAR: ";
    cin >> codigo;
     if((pos=validar.existenciaCodigoUsuario(codigo))>=0){
        limpiar();
        unUsuario.leerArchivo(pos);
        unUsuario.mostrarEncabezado();
        unUsuario.mostrarArchivo();
        fflush(stdin);
        cout << "INGRESE EL NOMBRE NUEVO: ";
        cin.getline(nombre,20);
        unUsuario.setNombre(nombre);
        unUsuario.modificarRegistro(pos);
        cout << "MODIFICADO CON EXITO."<<endl;
    }
    else {cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}
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
    dwPos.X= x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);

}
void cuentaRegresiva(int tam){
    int i;
    for(i=tam;i>0;i--){

        cout << i << "\b";
        Sleep(1000);
    }
}
void mostrarEncabezado(){

    cout << "\t\tLISTADO DE USUARIOS"<<endl;
    cout << "\t|  USUARIO  |"    "\t|  CONTRASEÑA  |"<<endl;
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
void cuentaVentaUsuario(Fecha fechaDeHoy, char *usuario, int &pEfectivo, int &pDebito, int &pCredito){

    int pos=0,pos2=0;
    CabeceraVentas unaCabeceraVenta;
    DetalleVentas unDetalleVenta;
    while(unaCabeceraVenta.leerenDisco(pos++)){
        if(unaCabeceraVenta.getFechaDeEmision()==fechaDeHoy&&(strcmp(usuario,unaCabeceraVenta.getUsuario())==0)){//COINCIDEN LA FECHA Y EL USUARIO
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
    recuadro(41,9,5,2, cAMARILLO, cROJO);
    recuadro(51,9,5,2, cAMARILLO, cROJO);
    gotoxy(43,10);cout << "SI"<<endl;
    gotoxy(53,10);cout << "NO"<<endl;
    opcion=navegacionMenuHorizontal(38,10,38,48,10);
        if(opcion==38)return true;
        return false;
}
bool consultaParaContinuar(){

    int opcion;
    gotoxy(40,13);cout << "¿DESEA CONTINUAR?"<<endl;
    recuadro(40,15,7,2, cAMARILLO, cROJO);
    recuadro(50,15,7,2, cAMARILLO, cROJO);
    gotoxy(44,16);cout << "SI"<<endl;
    gotoxy(54,16);cout << "NO"<<endl;
    opcion=navegacionMenuHorizontal(41,16,41,51,10);
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


}
void accionAceptada(){

    recuadro(33,17,35,5, cBLANCO, cROJO);
    textcolor(cAMARILLO,cROJO);
    gotoxy(48,17);cout << " AVISO "<<endl;
    textcolor(cBLANCO,cROJO);
    gotoxy(38,19);cout << "LA ACCION HA SIDO EXITOSA."<<endl;
    gotoxy(36,20);cout << "PRESIONE UNA TECLA PARA VOLVER"<<endl;

}

/// MENU COMPRAS - SUBMENU PROVEEDORES
void agregarProveedor(){

    Proveedor unProveedor;
    cout << "====================================================================================================="<<endl;
    cout << "                                    AGREGAR PROVEEDOR"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;
    unProveedor.cargarDatos();

    if(unProveedor.grabarArchivo()){
        cout << "GUARDADO EXITOSAMENTE."<<endl;
    }
    else {cout <<"HA OCURRIDO UN ERROR DURANTE LA GRABACION."<<endl;}
    getch();
    limpiar();

}
void borrarProveedor(){

    cout << "====================================================================================================="<<endl;
    cout << "                                    BORRAR PROVEEDOR"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;

    Validador validar;
    Proveedor unProveedor;
    int codigo;
    int pos;
    cout << "INGRESE EL CODIGO DEL PROVEEDOR QUE SE DESEE ELIMINAR: "<<endl;
    cin >> codigo;
    if((pos=validar.existenciaProveedor(codigo))>=0){
        unProveedor.leerArchivo(pos);
        if(unProveedor.getEstado()==true){
        unProveedor.setEstado(false);
        unProveedor.modificarArchivo(pos);
        cout << "PROVEEDOR ELIMINADO CON EXITO."<<endl;
        }
        else {cout << "EL PROVEEDOR INGRESADO NO EXISTE."<<endl;}
    }

    else {cout << "EL PROVEEDOR INGRESADO NO EXISTE."<<endl;}

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
        cout << "====================================================================================================="<<endl;
        cout << "                                    LISTAR PROVEEDOR POR CODIGO"<<endl;
        cout << "====================================================================================================="<<endl;
        cout << endl;
        fflush(stdin);
        cout << "INGRESE EL CODIGO DEL PROVEEDOR QUE DESEA LISTAR: "<<endl;
        cin >> codigo;

        if((pos=validar.existenciaProveedor(codigo))>=0){
            unProveedor.leerArchivo(pos);
            if(unProveedor.getEstado()==true){
            limpiar();
            unProveedor.mostrarEncabezado();
            unProveedor.mostrarArchivo();
            }
            else cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;
        }
        else cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;

    getch();
    limpiar();
}
void modificarPorcentuales(){

    Validador validar;
    Proveedor unProveedor;
    RetencionesImpositivas ri;
    Producto unProducto;
    cout << "====================================================================================================="<<endl;
    cout << "                                    MODIFICAR PORCENTUALES"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;
    int pos,codigo;
    fflush(stdin);
    cout << "INGRESE EL CODIGO DEL PROVEEDOR: "<<endl;
    cin >>codigo;
    if((pos=validar.existenciaProveedor(codigo))>=0){
        unProveedor.leerArchivo(pos);
        if(unProveedor.getEstado()==true){
            limpiar();
            unProveedor.mostrarEncabezado();
            unProveedor.mostrarArchivo();
            ri.cargarDatos();
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
            cout << "MODIFICADO CON EXITO."<<endl;
        }
        else cout << "EL CODIGO DEL PROVEEDOR INGRESADO NO EXISTE."<<endl;
    }
    else cout << "EL CODIGO DEL PROVEEDOR INGRESADO NO EXISTE."<<endl;

getch();
limpiar();

}
void modificarProveedor(){

    Validador validar;
    Proveedor unProveedor;
    int codigo;
    int pos;
    char nombre [20];
    cout << "====================================================================================================="<<endl;
    cout << "                                    MODIFICAR PROVEEDOR"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;
    cout << "INGRESE CODIGO DE PROVEEDOR: ";
    cin >> codigo;
    if((pos=validar.existenciaProveedor(codigo))>=0){
        unProveedor.leerArchivo(pos);
        unProveedor.mostrarArchivo();
        fflush(stdin);
        cout << "INGRESE LA NUEVA DESCRIPCION: ";
        cin.getline(nombre,20);
        unProveedor.setNombre(nombre);
        unProveedor.modificarArchivo(pos);
        cout << "MODIFICADO CON EXITO."<<endl;
    }
    else {cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}
    getch();
    limpiar();


}

/// MENU COMPRAS - SUBMENU PRODUCTOS
void agregarProducto(){

    system("color 1D");
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
    system("pause");
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
    int cod, pos,opcion;
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
            accionAceptada();
        }
        else accionCancelada();//NO SE BORRA
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
        recuadro(24,10,16,2, cAMARILLO, cROJO);
        recuadro(44,10,16,2, cAMARILLO, cROJO);
        recuadro(64,10,16,2, cAMARILLO, cROJO);
        gotoxy(28,11);cout << "DESCRIPCION";
        gotoxy(50,11);cout << "PROVEEDOR";
        gotoxy(71,11);cout << "SALIR";
        fflush(stdin);
        opcion=navegacionMenuHorizontal(25,11,25,65,20);
        if(opcion==25){//OPCION DESCRIPCION
            gotoxy(30,14);cout << "INGRESE LA NUEVA DESCRIPCION: "<<endl;
            gotoxy(60,14);cin.getline(descripcion,20);
            convierteAMiniscula(descripcion);
            unProducto.setDescipcion(descripcion);
            unProducto.modificarArchivo(pos);
            accionAceptada();
        }
        if(opcion==45)cout << "PROVEEDOR"<<endl;
        if(opcion==65)cout << "IRSE"<<endl;



    }
    else {cout << "EL CODIGO INGRESADO NO EXISTE"<<endl;}
    getch();
    limpiar();
}

/// MENU COMPRAS
void agregarCompra(char *usuario){

    cout << "====================================================================================================="<<endl;
    cout << "                                           AGREGAR COMPRA"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;

    Validador validar;
    Producto unProducto;
    CabeceraCompra unaCabeceraCompra;
    DetalleCompra unDetalleCompra;
    int stockAnterior,pos=0, cuentaLinea=1;
    char continuar='S';
    float stockValorizado,subTotalCompra,costoReal;
    fflush(stdin);
    unaCabeceraCompra.cargarDatos(usuario);

        while(continuar=='s'||continuar=='S'){
            unDetalleCompra.cargarDatos(unaCabeceraCompra.getNrodeFactura(),cuentaLinea,unaCabeceraCompra.getCodigoProveedor()); //SET NRO FACTURA, NRO DE LINEA, PROVEEDOR
            pos=validar.existenciaCodigo(unDetalleCompra.getcodigoProducto());//BUSCA EL PRODUCTO A TRAVES DEL CODIGO
            unProducto.leerArchivo(pos);//CARGA OBJETO
            unDetalleCompra.calculoPrecioBruto(unProducto);//CALCULA EL PRECIO BRUTO LLENA PRECIO BRUTO.
            subTotalCompra= unDetalleCompra.getCantidad()*unDetalleCompra.getPrecioBruto();//ARROJA EL SUBTOTAL DE LA COMPRA DEL PRODUCTO
            stockAnterior=unProducto.getStockSucursal()+unProducto.getStockDeposito();  //SUMA TODO EL STOCK ANTERIOR
            stockValorizado=stockAnterior*unProducto.getPrecioCosto();//MULTIPLICA EL PRECIO VIEJO POR EL EL STOCK ANTERIOR
            costoReal= (stockValorizado+subTotalCompra)/(stockAnterior+unDetalleCompra.getCantidad()); //TOMA LOS PRECIOS (ANTERIOR Y ACTUAL) Y REALIZA UN PROMEDIO CON EL TOTAL DE MERCADERIA, OBTENIENDO EL COSTO REAL DEL PRODUCTO.
            unDetalleCompra.setPrecioVenta(((unProducto.getRentabilidad()/100)+1)*costoReal);//CALCULA EL PRECIO DE VENTA
            unDetalleCompra.setPrecioVenta((int)unDetalleCompra.getPrecioVenta());//SET PRECIOVENTA.
            unProducto.cargarDatosCompra(unDetalleCompra.getPrecioVenta(),unDetalleCompra.getPrecioBruto(),unDetalleCompra.getCantidad()+unProducto.getStockDeposito()); //SET DE STOCK-COSTO-VENTA DEL PRODUCTO CARGADO

            cout << "STOCK ANTERIOR: " << stockAnterior <<endl;
            cout << "STOCK VALORIZADO: " << stockValorizado <<endl;
            cout << "SUBTOTAL: " << subTotalCompra <<endl;
            cout << "COSTO REAL: "<<costoReal<<endl;
            cout << "RENTABILIDAD: "<< unProducto.getRentabilidad()<<endl;
            cout << "PRECIO VENTA:" << unDetalleCompra.getPrecioVenta()<<endl;

            cout << "DATOS CARGADOS."<<endl;
            cout <<endl;

            cout << "¿DESEA CONTINUAR? <S/N>";
            cin >> continuar;
            getch();
            limpiar();

            unDetalleCompra.grabarArchivo();
            unProducto.modificarArchivo(pos);
            unaCabeceraCompra.leerArchivo(unDetalleCompra.getNroFactura()-1);
            unaCabeceraCompra.mostrarArchivo();
            pos=0;
            while(unDetalleCompra.leerArchivo(pos)){
                if(unDetalleCompra.getNroFactura()==unaCabeceraCompra.getNrodeFactura()) unDetalleCompra.mostrarArchivo();
            pos++;
            }
            cuentaLinea++;
        }
            unaCabeceraCompra.grabarArchivo();
            getch();
            limpiar();

    }
void listarTodasLasCompras(){

    CabeceraCompra unaCabeceraCompra;
    DetalleCompra unDetalleCompra;

    int posC=0, posD=0;

    while(unaCabeceraCompra.leerArchivo(posC)){
        unaCabeceraCompra.mostrarArchivo();
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
    cout << "====================================================================================================="<<endl;
    cout << "                                           LISTADO COMPRAS POR CODIGO"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;

    cout << "INGRESE EL NUMERO DE LA FACTURA QUE DESEA CONSULTAR: ";
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
char continuar;

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
    unDetalleVenta.calculoDeVuelto();
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
    int totalVentasEfectivo=0, totalVentasDebito=0, totalVentasCredito=0;

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
    cuentaVentaUsuario(fechaDeHoy,usuario,totalVentasEfectivo,totalVentasDebito,totalVentasCredito);
    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(40,8);cout << "TOTAL VENTAS EN EFECTIVO: "<<totalVentasEfectivo<<endl;
    gotoxy(40,9);cout << "TOTAL VENTAS EN CON TARJETA DE DEBITO: "<<totalVentasDebito<<endl;
    gotoxy(40,10);cout << "TOTAL VENTAS CON TARJETA DE CREDITO: "<<int(totalVentasCredito*1.08)<<endl;
    gotoxy(40,11);cout << "TOTAL A ENTREGAR: "<< inicioDeCaja+totalVentasEfectivo+totalVentasDebito+totalVentasCredito<<endl;
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

    cout << "====================================================================================================="<<endl;
    cout << "                                           TRANSFERENCIA DE MERCADERIA"<<endl;
    cout << "====================================================================================================="<<endl;

    int cantidadATransferir, pos=0, nroLinea=1, totalATransferir=0;
    char descripcion[20];
    char continuar;
    bool mostrarCabecera=false;
    Producto unProducto;
    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimiento;
    unaCabeceraMovimiento.cargarDatos(usuario,tipo);
    unDetalleMovimiento.mostrarEncabezadoFaltantes();
    while(unProducto.leerArchivo(pos)){

            if(unProducto.getStockSucursal()<unProducto.getStockCritico()&&unProducto.getStockDeposito()>0&&unProducto.getEstado()==true){
                unDetalleMovimiento.mostrarFaltantes(pos);
            }
        pos++;
     }

    cout << "¿DESEA CARGAR LOS DATOS? <S/N>"<<endl;
    cin >> continuar;
    if(continuar=='s'||continuar=='S'){
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
    }
    else {accionCancelada();}

    getch();
    limpiar();
}
void devolucionDeMercaderia(char *usuario, int tipo){

    int codigo, pos,nroLinea=1, pos2;
    bool seguir=true;
    char continuar;
    Validador validar;
    Producto unProducto;
    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimiento;

    cout << "====================================================================================================="<<endl;
    cout << "                                           DEVOLUCION DE MERCADERIA"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;


    unaCabeceraMovimiento.cargarDatos(usuario,tipo); //CARGO LA CABECERA
    while(seguir==true){
    unDetalleMovimiento.cargarDatosDevoluciones(unaCabeceraMovimiento.getNrodeFactura(),nroLinea); //PIDO LOS DATOS, CARGO EL DETALLE
    pos=validar.existenciaCodigo(unDetalleMovimiento.getcodigoProducto()); //BUSCO EL PRODUCTO
    unProducto.leerArchivo(pos);
    unProducto.setStockSucursal(unProducto.getStockSucursal()-unDetalleMovimiento.getCantidad());//RESTO EL STOCK
    unProducto.modificarArchivo(pos);
    unDetalleMovimiento.grabarArchivo();
    nroLinea++;
    cout << "¿DESEA CONTINUAR? <S/N>";
    cin >> continuar;
    getch();
    limpiar();
    if(continuar=='s' || continuar=='S') seguir=true;
    else if (continuar == 'n' || continuar == 'N') {
            seguir=false;
            unaCabeceraMovimiento.grabarArchivo();
    }
    }
}
void listadoDeMovimientos(){
    CabeceraMovimientos unaCabeceraMovimiento;
    DetalleMovimientos unDetalleMovimiento;

    int opcion;
    cout << "====================================================================================================="<<endl;
    cout << "                                           LISTADO DE MOVIMIENTOS"<<endl;
    cout << "====================================================================================================="<<endl;
    cout << endl;

    cout << "¿QUE DESEA LISTAR?"<<endl;
    cin >> opcion;
    limpiar();
    int pos=0, pos2=0;
    while(unaCabeceraMovimiento.leerArchivo(pos++)){
        if(unaCabeceraMovimiento.getTipo()==opcion){
            unaCabeceraMovimiento.mostrarArchivo();
            while(unDetalleMovimiento.leerArchivo(pos2++)){
                if(unaCabeceraMovimiento.getNrodeFactura()==unDetalleMovimiento.getNroFactura()){
                    unDetalleMovimiento.mostrarArchivo();
                }
            }
    getch();
    limpiar();
        }

    pos2=0;
}
}
#endif // FUNCIONES_H_INCLUDE
