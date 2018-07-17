#ifndef DETALLEVENTAS_H_INCLUDED
#define DETALLEVENTAS_H_INCLUDED

void DetalleVentas::cargarArchivo(int _codigoFactura,int _codigoLinea){

    char descripcion[30];
    bool codigoAceptado=false;
    Validador validar;
    nroFactura=_codigoFactura;
    nroLinea=_codigoLinea;

    gotoxy(30,5);cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
    gotoxy(62,5);cin >> codigoProducto;

    while(codigoAceptado==false){

        if(validar.existenciaCodigo(codigoProducto)<0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(34,6);cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
        getch();
        gotoxy(34,6);cout << "                              "<<endl;
        gotoxy(62,5);cout << "             ";
        textcolor(cBLANCO,cAZUL);
        gotoxy(30,5);cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
        gotoxy(62,5);cin >> codigoProducto;
        }
        else if(buscarStockSucursal(codigoProducto)==0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(29,6);cout << "EL PRODUCTO INGRESADO TIENE STOCK CERO."<<endl;
        getch();
        gotoxy(29,6);cout << "                                       "<<endl;
        gotoxy(62,5);cout << "             ";
        textcolor(cBLANCO,cAZUL);
        gotoxy(30,5);cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
        gotoxy(62,5);cin >> codigoProducto;
        }
        else codigoAceptado=true;

    }
    textcolor(cGRIS_CLARO,cAZUL);
    strcpy(descripcion,buscardescripcion(codigoProducto));
    gotoxy(30,6);cout<<"PRODUCTO: "<<descripcion<<endl;
    gotoxy(30,7);cout <<"STOCK: "<<buscarStockSucursal(codigoProducto)<<endl;
    textcolor(cBLANCO,cAZUL);
    gotoxy(30,8);cout<<"INGRESE CANTIDAD: ";
    gotoxy(48,8);cin>>cantidad;

    while(validar.validarStockSucursal(codigoProducto,cantidad)==false){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(22,9);cout << "LA CANTIDAD INGRESADA ES MAYOR AL STOCK QUE SE TIENE."<<endl;
        getch();
        gotoxy(22,9);cout << "                                                     "<<endl;
        gotoxy(48,8);cout << "      "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(30,8);cout<<"INGRESE CANTIDAD: ";
        gotoxy(48,8);cin>>cantidad;
    }
    textcolor(cGRIS_CLARO,cAZUL);
    precioVenta=buscarPV(codigoProducto);
    gotoxy(30,9);cout<<"PRECIO UNITARIO: $"<<precioVenta<<endl;
    gotoxy(30,10);cout<<"IMPORTE: $"<<cantidad*precioVenta<<endl;
    subtotal+=(cantidad*precioVenta);
    gotoxy(30,11);cout<<"TOTAL: $"<<subtotal<<endl;
    precioCosto=buscarPC(codigoProducto);
}
void DetalleVentas::mostrarEncabezado(){

cout<<"    NRO  CODIGO    DETALLE             CANT      PU        SUBT      TOTAL"<<endl;
cout<<"  ==================================================================================================="<<endl;

}
void DetalleVentas::mostrarArchivo(){
float pv=buscarPV(codigoProducto);
char descripcion[30];
strcpy(descripcion,buscardescripcion(codigoProducto));
std::cout << setiosflags(ios::left)<<"     "<<setw(4)<<nroLinea<<setw(10)<<codigoProducto<<setw(20)<<descripcion<<setw(10)<<cantidad;
std::cout << setiosflags(ios::left)<<setw(10)<<buscarPV(codigoProducto)<<setw(10)<<pv*cantidad<<setw(10)<<subtotal<<endl;

}
bool DetalleVentas::grabarenDisco(){
bool escribio;
FILE*p;
p=fopen("archivos/detalleVentas.dat","ab");
if(p==NULL)return false;
escribio=fwrite(this,sizeof(DetalleVentas),1,p);
fclose(p);
return escribio;
}
bool DetalleVentas::leerenDisco(int pos){
bool leyo;
FILE*p;
p=fopen("archivos/detalleVentas.dat", "rb");
if(p==NULL)return false;
fseek(p,pos*sizeof(DetalleVentas),0);
leyo=fread(this,sizeof(DetalleVentas),1,p);
fclose(p);
return leyo;
}
int DetalleVentas::calculoConFormaDePago(){

    int cuotas,metodoDePago;
    cout<<"METODO DE PAGO: ";
    cin>>metodoDePago;

    if(metodoDePago==3){
    cout << "INGRESE CUOTAS: ";
    cin >> cuotas;
    if(cuotas==2) subtotal=subtotal*1.06;
    if(cuotas==3) subtotal=subtotal*1.08;
    }
    cout << "EL TOTAL AL PAGAR ES: "<<subtotal<<endl;

    return metodoDePago;
}
void DetalleVentas::calculoDeVuelto(){
    float importe;
    cout << "INGRESE EL DINERO RECIBIDO: ";
    cin >>importe;
    cout << "VUELTO:"<<importe-subtotal<<endl;

}
#endif // DETALLEVENTAS_H_INCLUDED
