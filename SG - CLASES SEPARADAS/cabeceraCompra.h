#ifndef CABECERACOMPRA_H_INCLUDED
#define CABECERACOMPRA_H_INCLUDED

void CabeceraCompra::cargarDatos(char *_usuario){
    Validador validar;
    char nombreProveedor[20];
    gotoxy(35,4);cout << "NUMERO DE FACTURA " << cuentaRegistros(rutaCabeceraCompra,tamanioCabeceraCompra)+1<<endl;
    NrodeFactura=cuentaRegistros(rutaCabeceraCompra,tamanioCabeceraCompra)+1;
    strcpy(usuario,_usuario);
    gotoxy(35,5);cout << "TIPO DE FACTURA: ";
    cin.getline(tipo,10);
    convierteAMiniscula(tipo);

    while(strcmp(tipo,"remito")&&(strcmp(tipo,"a"))){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(25,6);cout << "TIPO INVALIDO. SOLO SE ACEPTA 'A' o 'REMITO'"<<endl;
        getch();
        gotoxy(25,6);cout << "                                            "<<endl;
        gotoxy(52,5);cout << "                    "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,5);cout << "TIPO DE FACTURA: ";
        gotoxy(52,5);cin.getline(tipo,10);
        convierteAMiniscula(tipo);
    }
    gotoxy(35,6);cout << "CODIGO DE PROVEEDOR: ";
    cin >> codigoProveedor;
    while(validar.existenciaProveedor(codigoProveedor)<0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(25,7);cout << "EL CODIGO DE PROVEEDOR INGRESADO NO EXISTE."<<endl;
        getch();
        gotoxy(25,7);cout << "                                           "<<endl;
        gotoxy(56,6);cout << "         "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,6);cout << "CODIGO DE PROVEEDOR: ";
        gotoxy(56,6);cin >> codigoProveedor;
    }
    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(35,7);cout << "NOMBRE DE PROVEEDOR:"<<strcpy(nombreProveedor,buscarProveedor(codigoProveedor))<<endl;
    textcolor(cBLANCO,cAZUL);
}
void CabeceraCompra::mostrarArchivo(){

    Proveedor unProveedor;
    Validador validar;
    int pos;
    pos=validar.existenciaProveedor(codigoProveedor);
    unProveedor.leerArchivo(pos);
    CabeceraDocumento::mostrarArchivo();
    cout << "\tTIPO: "<<tipo<< "\t\t\t\tPROVEEDOR: "<<unProveedor.getNombre()<<endl;
    cout << "====================================================================================================="<<endl;
}
bool CabeceraCompra::leerArchivo(int pos){

    bool leyo;
    FILE *p;
    p=fopen("archivos/cabeceraCompra.dat","rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(CabeceraCompra),0);
    leyo=fread(this,sizeof(CabeceraCompra),1,p);
    fclose(p);
    return leyo;

}
bool CabeceraCompra::grabarArchivo(){

    bool grabo;
    FILE *p;
    p=fopen("archivos/cabeceraCompra.dat","ab");
    if(p==NULL)return false;
    grabo= fwrite(this,sizeof(CabeceraCompra),1,p);
    fclose(p);
    return grabo;

}

#endif // CABECERACOMPRA_H_INCLUDED
