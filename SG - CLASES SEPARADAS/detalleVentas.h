#ifndef DETALLEVENTAS_H_INCLUDED
#define DETALLEVENTAS_H_INCLUDED

void DetalleVentas::cargarArchivo(int _codigoFactura,int _codigoLinea){

    char descripcion[30];
    bool codigoAceptado=false;
    Validador validar;
    nroFactura=_codigoFactura;
    nroLinea=_codigoLinea;

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
    strcpy(descripcion,buscardescripcion(codigoProducto));
    cout<<"PRODUCTO: "<<descripcion<<endl;
    cout <<"STOCK: "<<buscarStockSucursal(codigoProducto)<<endl;
    cout<<"INGRESE CANTIDAD: ";
    cin>>cantidad;

    while(validar.validarStockSucursal(codigoProducto,cantidad)==false){
        cout << "LA CANTIDAD INGRESADA ES MAYOR AL STOCK QUE SE TIENE."<<endl;
        cout<<"INGRESE CANTIDAD: ";
        cin>>cantidad;
    }
    precioVenta=buscarPV(codigoProducto);
    cout<<"PRECIO UNITARIO: "<<precioVenta<<endl;
    cout<<"IMPORTE"<<cantidad*precioVenta<<endl;
    subtotal+=(cantidad*precioVenta);
    cout<<"TOTAL: "<<subtotal<<endl;
    precioCosto=buscarPC(codigoProducto);
}
void DetalleVentas::mostrarArchivo(){
float pv=buscarPV(codigoProducto);
char descripcion[30];
strcpy(descripcion,buscardescripcion(codigoProducto));
cout <<"NRO\tCODIGO\tDETALLE\t\tCANTIDAD\tPU\tSUBTOTAL\tTOTAL"<<endl;
cout <<nroLinea<<"\t"<<codigoProducto<<"\t"<<descripcion<<"\t"<<cantidad<<"\t\t"<<buscarPV(codigoProducto)<<"\t"<<pv*cantidad<<"\t"<<subtotal<<endl;
cout << "-----------------------------------------------------------------------------------------------------"<<endl;

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
    cout<<"METODO DE PAGO: "<<endl;
    cin>>metodoDePago;

    if(metodoDePago==3){
    cout << "INGRESE CUOTAS: ";
    cin >> cuotas;
    if(cuotas==2) subtotal=subtotal*1.06;
    if(cuotas==3) subtotal=subtotal*1.08;
    }
    cout << "EL TOTAL AL PAGAR ES: "<<subtotal;

    return metodoDePago;
}

#endif // DETALLEVENTAS_H_INCLUDED
