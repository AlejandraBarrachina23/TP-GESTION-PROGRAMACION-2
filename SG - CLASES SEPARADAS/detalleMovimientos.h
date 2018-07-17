#ifndef DETALLEMOVIMIENTOS_H_INCLUDED
#define DETALLEMOVIMIENTOS_H_INCLUDED

bool DetalleMovimientos::leerArchivo(int pos){
    bool leyo;
    FILE *p;
    p=fopen("archivos/detalleMovimiento.dat","rb");
    if(p==NULL)return false;
    fseek(p,sizeof(DetalleMovimientos)*pos,0);
    leyo=fread(p,sizeof(DetalleMovimientos),1,p);
    fclose(p);
    return leyo;
}
void DetalleMovimientos::mostrarArchivo(){

char descripcion[30];
strcpy(descripcion,buscardescripcion(codigoProducto));
cout <<"NRO\tCODIGO\tDETALLE\t\tCANTIDAD"<<endl;
cout <<nroLinea<<"\t"<<codigoProducto<<"\t"<<descripcion<<"\t"<<cantidad<<"\t\t"<<endl;
cout << "-----------------------------------------------------------------------------------------------------"<<endl;
}
bool DetalleMovimientos::grabarArchivo(){

    bool grabo;
    FILE *p;
    p=fopen("archivos/detalleMovimento.dat","ab");
    if(p==NULL)return false;
    grabo=fwrite(this,sizeof(DetalleMovimientos),1,p);
    fclose(p);
    return grabo;
}
void DetalleMovimientos::cargarDatos(int _nroFactura, int _nroLinea, int _codigoProducto, int cantidadTransferida){

    nroFactura=_nroFactura;
    nroLinea=_nroLinea;
    codigoProducto=_codigoProducto;
    cantidad=cantidadTransferida;
}

void DetalleMovimientos::mostrarEncabezadoFaltantes(){
cout <<"---------------------------------------------------------------------------"<<endl;
cout << "                      CODIGO  DESCRIPCION         SC    SS    SD    MOV"<<endl;
cout <<"---------------------------------------------------------------------------"<<endl;

}
void DetalleMovimientos::mostrarFaltantes(int pos){

    Producto unProducto;
    unProducto.leerArchivo(pos);
    std::cout << setiosflags(ios::left)<<"                      "<<setw(8)<<unProducto.getCodigoProducto()<<setw(20)<<unProducto.getDescripcion()<<setw(6)<<unProducto.getStockCritico()<<setw(6)<<unProducto.getStockSucursal()<<setw(6)<<unProducto.getStockDeposito()<<setw(6)<<endl;

}

void DetalleMovimientos::cargarDatosDevoluciones(int _nroFactura, int _nroLinea){

    Validador validar;
    char descripcion[20];
    bool codigoAceptado=false;

    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
    cin >> codigoProducto;

    while(codigoAceptado==false){

        if(validar.existenciaCodigo(codigoProducto)<0){
        cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
        cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
        cin >> codigoProducto;
        }
        else if(buscarStockSucursal(codigoProducto)==0){
        cout << "EL PRODUCTO INGRESADO TIENE STOCK CERO."<<endl;
        cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
        cin >> codigoProducto;
        }
        else codigoAceptado=true;

    }
    cout << "DESCRIPCION:" <<strcpy(descripcion,buscardescripcion(codigoProducto))<<endl;
    cout << "STOCK: "<< buscarStockSucursal(codigoProducto)<<endl;

    cout << "INGRESE CANTIDAD A DESCONTAR: ";
    cin >> cantidad;
    while(validar.validarStockSucursal(codigoProducto,cantidad)==false){
        cout << "LA CANTIDAD INGRESADA ES MAYOR AL STOCK QUE SE TIENE."<<endl;
        cout<<"INGRESE CANTIDAD: ";
        cin>>cantidad;
    }

    nroFactura=_nroFactura;
    nroLinea=_nroLinea;

}
#endif // DETALLEMOVIMIENTOS_H_INCLUDED
