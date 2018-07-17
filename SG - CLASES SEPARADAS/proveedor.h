#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

void Proveedor::cargarDatos(){

    Validador validar;

    cin.ignore();
    cout << "INGRESE CODIGO DEL PROVEEDOR: ";
    cin >> codigo;
    while(validar.existenciaProveedor(codigo)>=0){
        cout << "EL CODIGO INGRESADO YA EXISTE."<<endl;
        cout << "INGRESE CODIGO DEL PROVEEDOR: ";
        cin >> codigo;
    }
    cin.ignore();
    cout << "NOMBRE DE LA EMPRESA: ";
    cin.getline(nombre,20);
    convierteAMiniscula(nombre);
    while(validar.existenciaProveedor(nombre)>=0){
        cout << "EL NOMBRE DE PROVEEDOR INGRESADO YA EXISTE."<<endl;
        cout << "NOMBRE DE LA EMPRESA: ";
        cin.getline(nombre,20);
        convierteAMiniscula(nombre);
    }
    cout << "RUBRO:";
    cin.getline(rubro,20);
    convierteAMiniscula(rubro);

    estado=true;
    cout << "RETENCIONES IMPOSITIVAS: "<<endl;
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
