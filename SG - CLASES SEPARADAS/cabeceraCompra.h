#ifndef CABECERACOMPRA_H_INCLUDED
#define CABECERACOMPRA_H_INCLUDED

void CabeceraCompra::cargarDatos(char *_usuario){
    Validador validar;
    char nombreProveedor[20];
    cout << "NUMERO DE FACTURA " << cuentaRegistros(rutaCabeceraCompra,tamanioCabeceraCompra)+1<<endl;
    NrodeFactura=cuentaRegistros(rutaCabeceraCompra,tamanioCabeceraCompra)+1;
    cout << "TIPO DE FACTURA: ";
    cin.getline(tipo,10);
    convierteAMiniscula(tipo);
    strcpy(usuario,_usuario);

    while(strcmp(tipo,"remito")&&(strcmp(tipo,"a"))){
        cout << "TIPO INVALIDO. SOLO SE ACEPTA 'A' o 'REMITO'"<<endl;
        cout << "TIPO DE FACTURA: ";
        cin.getline(tipo,10);
        convierteAMiniscula(tipo);
    }
    cout << "CODIGO DE PROVEEDOR: ";
    cin >> codigoProveedor;
    while(validar.existenciaProveedor(codigoProveedor)<0){
        cout << "EL CODIGO DE PROVEEDOR INGRESADO NO EXISTE."<<endl;
        cout << "CODIGO DE PROVEEDOR: ";
        cin >> codigoProveedor;
    }
    cout << "NOMBRE DE PROVEEDOR:"<<strcpy(nombreProveedor,buscarProveedor(codigoProveedor))<<endl;
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
