#ifndef DETALLEMOVIMIENTOS_H_INCLUDED
#define DETALLEMOVIMIENTOS_H_INCLUDED

bool DetalleMovimientos::leerArchivo(int pos){
    bool leyo;
    FILE *p;
    p=fopen("archivos/detalleMovimento.dat","rb");
    if(p==NULL)return false;
    fseek(p,sizeof(DetalleMovimientos)*pos,0);
    leyo=fread(this,sizeof(DetalleMovimientos),1,p);
    fclose(p);
    return leyo;
}
void DetalleMovimientos::mostrarArchivo(){

char descripcion[30];
strcpy(descripcion,buscardescripcion(codigoProducto));
recuadro(1, 4,100, 2, cBLANCO, cAZUL);
textcolor(cBLANCO,cAZUL);
gotoxy(4,5);std::cout << setiosflags(ios::left)<<"         "<<setw(8)<<"NRO"<<setw(12)<<"CODIGO"<<setw(20)<<"DETALLE"<<setw(8)<<"CANTIDAD"<<endl;
cout<<endl;
std::cout<<setiosflags(ios::left)<<"              "<<setw(8)<<nroLinea<<setw(12)<<codigoProducto<<setw(20)<<descripcion<<setw(8)<<cantidad<<endl;

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

recuadro(1, 3,100, 2, cBLANCO, cAZUL);
textcolor(cBLANCO,cAZUL);
gotoxy(4,4);std::cout << setiosflags(ios::left)<<"                  "<<setw(8)<< "CODIGO"<<setw(20)<<"DESCRIPCION"<<setw(6)<<"SC"<<setw(6)<<"SS"<<setw(6)<<"SD"<<setw(8)<<endl;
cout<<endl;
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

    gotoxy(30,5);cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
    cin >> codigoProducto;

    while(codigoAceptado==false){

        if(validar.existenciaCodigo(codigoProducto)<0){
        textcolor(cROJO_CLARO,cAZUL);gotoxy(32,6);cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
        getch();
        gotoxy(29,6);cout << "                                    "<<endl;gotoxy(62,5);cout << "                "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(30,5);cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
        gotoxy(62,5);cin >> codigoProducto;
        }
        else if(buscarStockSucursal(codigoProducto)==0){
        textcolor(cROJO_CLARO,cAZUL);gotoxy(29,6);cout << "EL PRODUCTO INGRESADO TIENE STOCK CERO."<<endl;
        getch();
        gotoxy(29,6);cout << "                                                "<<endl;
        gotoxy(62,5);cout << "                "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(30,5);cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
        gotoxy(62,5);cin >> codigoProducto;
        }
        else codigoAceptado=true;
    }
    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(30,6);cout << "DESCRIPCION:" <<strcpy(descripcion,buscardescripcion(codigoProducto))<<endl;
    gotoxy(30,7);cout << "STOCK: "<< buscarStockSucursal(codigoProducto)<<endl;
    textcolor(cBLANCO,cAZUL);
    gotoxy(30,8);cout << "INGRESE CANTIDAD A DESCONTAR: ";
    cin >> cantidad;
    while(validar.validarStockSucursal(codigoProducto,cantidad)==false){

        textcolor(cROJO_CLARO,cAZUL);gotoxy(25,9);cout << "LA CANTIDAD INGRESADA ES MAYOR AL STOCK QUE SE TIENE."<<endl;
        getch();
        gotoxy(25,9);cout << "                                                      "<<endl;
        gotoxy(48,8);cout << "                 "<<endl;
        gotoxy(30,8);cout<<"INGRESE CANTIDAD: ";
        gotoxy(48,8);cin>>cantidad;
    }

    nroFactura=_nroFactura;
    nroLinea=_nroLinea;

}
#endif // DETALLEMOVIMIENTOS_H_INCLUDED
