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
    cout <<codigo<<"\t"<<nombre <<"\t\t"<< password<<"\t\t\t"<<estado<<"\t\t\t"<<sector<<endl;
    cout << "-------------------------------------------------------------------------"<<endl;
    }
}
void Usuario::mostrarEncabezado(){

    cout << "CODIGO\tNOMBRE\t\tCONTRASEÑA\t\tESTADO\t\tSECTOR"<<endl;
    cout << "========================================================================="<<endl;

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
    int intentos=1;
    cout << "CODIGO DE USUARIO: ";
    cin >> codigo;
    while(validar.existenciaCodigoUsuario(codigo)>=0){
        cout << "EL CODIGO INGRESADO YA EXISTE."<<endl;
        cout << "CODIGO DE USUARIO: ";
        cin >> codigo;
    }
    cout << "NOMBRE DE USUARIO: ";
    cin >> nombre;
    convierteAMiniscula(nombre);
    while(validar.existenciaUsuario(nombre)>=0){
        cout << "EL USUARIO INGRESADO YA EXISTE."<<endl;
        cout << "NOMBRE DE USUARIO: ";
        cin >> nombre;
    }
        fflush(stdin);
        cout << "CONTRASEÑA: ";
        cin >> password;
        cout << "SECTOR: ";
        cin >> sector;
        while(!validar.intervaloDeNumeros(sector,1,4)){
            cout << "NUMERO DE SECTOR ERRONEO. DEBE INGRESAR UN VALOR DEL 1 AL 4."<<endl;
            cout << "SECTOR: ";
            cin >> sector;
        }
       estado = true;
}
bool Usuario::operator!=(Usuario &aux){

    if(strcmp(aux.getNombre(),nombre)!=0)return true;
    if(strcmp(aux.getPassword(),password)!=0)return true;
    if(aux.getEstado()!=true)return true;
    return false;
}
#endif // USUARIOS_H_INCLUDED
