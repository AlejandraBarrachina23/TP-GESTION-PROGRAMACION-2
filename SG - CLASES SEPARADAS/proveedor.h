#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

void Proveedor::cargarDatos(){

    Validador validar;
    bool codigoAdmitido=false;

    fflush(stdin);
    gotoxy(33,4);cout << "INGRESE CODIGO DEL PROVEEDOR: ";
    cin >> codigo;
    while(codigoAdmitido==false){
        if(validar.existenciaProveedor(codigo)>=0){
            textcolor(cROJO_CLARO,cAZUL);
            gotoxy(33,5);cout << "EL CODIGO INGRESADO YA EXISTE."<<endl;
            getch();
            gotoxy(33,5);cout<< "                                "<<endl;
            gotoxy(63,4);cout<< "             "<<endl;
            textcolor(cBLANCO,cAZUL);
            gotoxy(33,4);cout << "INGRESE CODIGO DEL PROVEEDOR: ";
            gotoxy(63,4);cin >> codigo;
        }
        else if(!validar.intervaloDeNumeros(codigo,100,999)){
            textcolor(cROJO_CLARO,cAZUL);
            gotoxy(20,5);cout << "CODIGO ERRONEO. SOLO SE ACEPTAN VALORES DEL 100 AL 999"<<endl;
            getch();
            gotoxy(20,5);cout<< "                                                        "<<endl;
            gotoxy(63,4);cout<< "             "<<endl;
            textcolor(cBLANCO,cAZUL);
            gotoxy(33,4);cout << "INGRESE CODIGO DEL PROVEEDOR: ";
            gotoxy(63,4);cin >> codigo;

        }
        else codigoAdmitido=true;
    }

    fflush(stdin);
    gotoxy(33,5);cout << "NOMBRE DE LA EMPRESA: ";
    cin.getline(nombre,20);
    convierteAMiniscula(nombre);
    while(validar.existenciaProveedor(nombre)>=0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(30,6);cout << "EL NOMBRE DE PROVEEDOR INGRESADO YA EXISTE."<<endl;
        getch();
        gotoxy(30,6);cout << "                                           "<<endl;
        gotoxy(55,5);cout << "                       "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(33,5);cout << "NOMBRE DE LA EMPRESA: ";
        gotoxy(55,5);cin.getline(nombre,20);
        convierteAMiniscula(nombre);
    }
    gotoxy(33,6);cout << "RUBRO:";
    cin.getline(rubro,20);
    convierteAMiniscula(rubro);

    estado=true;
    gotoxy(33,7);cout << "RETENCIONES IMPOSITIVAS: "<<endl;
    porcentuales.cargarDatos();
}
bool Proveedor::leerArchivo(int pos){

    bool leyo;
    FILE *p;
    p=fopen("archivos/proveedores.dat","rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Proveedor)*pos,0);
    leyo=fread(this,sizeof(Proveedor),1,p);
    fclose(p);
    return leyo;
}
bool Proveedor::grabarArchivo(){

    bool grabo;
    FILE *p;
    p=fopen("archivos/proveedores.dat","ab");
    if(p==NULL) return false;
    grabo = fwrite(this,sizeof(Proveedor),1,p);
    fclose(p);
    return grabo;
}
void Proveedor::modificarArchivo(int pos){

    FILE *p;
    p=fopen("archivos/proveedores.dat","rb+");
    if(p==NULL) exit(-1);
    fseek(p,sizeof(Proveedor)*pos,0);
    fwrite(this,sizeof(Proveedor),1,p);
    fclose(p);
}
void Proveedor::mostrarArchivo(){

    if(estado==true){
    cout<< "\t"<<codigo << "\t"<< nombre<<"\t\t"<<rubro<<"\t";
    porcentuales.mostrarArchivo();
    }

}
void Proveedor::mostrarEncabezado(){

    cout << "====================================================================================================="<<endl;
    cout << "                                      PROVEEDORES      "<<endl;
    cout << "====================================================================================================="<<endl;
    cout << "\tCODIGO\tEMPRESA\t\tRUBRO\t\tIVA\tPERCEPCION\tIB"<<endl;
    cout << "====================================================================================================="<<endl;

}




#endif // PROVEEDOR_H_INCLUDED
