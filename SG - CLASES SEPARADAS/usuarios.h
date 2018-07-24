#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "funciones.h"

using namespace std;

void Usuario::modificarRegistro(int pos){

        FILE *p;
        p=fopen("archivos/usuarios.dat","rb+");
        if(p==NULL) exit(-1);
        fseek(p,sizeof(Usuario)*pos,0);
        fwrite(this,sizeof(Usuario),1,p);
        fclose(p);
}
bool Usuario::leerArchivo(int pos){

        bool leyo;
        FILE *p;
        p=fopen("archivos/usuarios.dat","rb");
        if(p==NULL) return false;
        fseek(p,sizeof(Usuario)*pos,0);
        leyo = fread(this,sizeof(Usuario),1,p);
        return leyo;
        fclose(p);
}
void Usuario::mostrarArchivo(){
    if(estado==true){
    std::cout << setiosflags(ios::left)<<(char)186<<" "<<setw(12)<<codigo<<setw(25)<<nombre<<setw(25)<<password<<setw(12)<<sector<<endl;
    }
}
void Usuario::mostrarEncabezado(){

recuadro(0, 0,100, 25, cBLANCO, cAZUL);
recuadro(0,0,100, 2, cBLANCO, cAZUL);
    //recuadro(0, 0,102, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,1);cout << "LISTADO DE USUARIOS"<<endl;
    cout<<endl;
    cout <<(char)186<< " CODIGO      NOMBRE                   CONTRASENIA               SECTOR"<<endl;
    cout <<(char)186<< "==================================================================================================="<<endl;

}
bool Usuario::grabarArchivo(){

    bool grabo;
    FILE *p;
    p=fopen("archivos/usuarios.dat","ab");
    if(p==NULL)return false;
    grabo= fwrite(this,sizeof(Usuario),1,p);
    fclose(p);
    return grabo;
}
void Usuario::cargarDatos(){

    Validador validar;
    gotoxy(20,6);cout << "-->>COMPLETE LOS DATOS PARA AGREGAR EL NUEVO USUARIO<<--"<<endl;
    gotoxy(35,8);cout << "INGRESE CODIGO DE USUARIO: ";
    cin >> codigo;
    while(validar.existenciaCodigoUsuario(codigo)>=0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(34,9);cout << "EL CODIGO INGRESADO YA EXISTE."<<endl;
        getch();
        gotoxy(34,9);cout << "                              "<<endl;
        gotoxy(62,8);cout << "         "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,8);cout << "INGRESE CODIGO DE USUARIO: ";
        gotoxy(62,8);cin >> codigo;
    }
    gotoxy(35,9);cout << "NOMBRE DE USUARIO: ";
    cin >> nombre;
    convierteAMiniscula(nombre);

    while(validar.existenciaUsuario(nombre)>=0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(33,10);cout << "EL USUARIO INGRESADO YA EXISTE."<<endl;
        getch();
        gotoxy(33,10);cout << "                               "<<endl;
        gotoxy(54,9);cout << "                   "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,9);cout << "NOMBRE DE USUARIO: ";
        gotoxy(54,9);cin >> nombre;
        convierteAMiniscula(nombre);
    }
        fflush(stdin);
        gotoxy(35,10);cout << "CONTRASEÑA: ";
        cin >> password;
        gotoxy(35,11);cout << "SECTOR: ";
        textcolor(cGRIS_CLARO,cAZUL);
        gotoxy(25,12);cout << "[1-ADMINISTRACION 2-VENTAS 3-COMPRAS 4-MOVIMIENTOS]"<<endl;
        gotoxy(43,11);cin >> sector;
        textcolor(cBLANCO,cAZUL);

    while(!validar.intervaloDeNumeros(sector,1,4)){
            textcolor(cROJO_CLARO,cAZUL);
            gotoxy(25,13);cout << "NUMERO INVALIDO. DEBE INGRESAR UN VALOR DEL 1 AL 4."<<endl;
            getch();
            gotoxy(25,13);cout << "                                                   "<<endl;
            gotoxy(43,11);cout << "                   "<<endl;
            textcolor(cBLANCO,cAZUL);
            gotoxy(35,11);cout << "SECTOR: ";
            gotoxy(43,11);cin >> sector;
        }
    estado = true;
}
bool Usuario::operator!=(Usuario &aux){

    if(strcmp(aux.getNombre(),nombre)!=0)return true;
    if(strcmp(aux.getPassword(),password)!=0)return true;
    return false;
}
#endif // USUARIOS_H_INCLUDED
