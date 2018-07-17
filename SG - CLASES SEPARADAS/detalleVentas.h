#ifndef DETALLEVENTAS_H_INCLUDED
#define DETALLEVENTAS_H_INCLUDED

void DetalleVentas::cargarArchivo(){

    char descripcion[30];
    Validador validar;

    cout<<"INGRESE CODIGO DE PRODUCTO: ";
    cin>>codigoProducto;
    while(validar.existenciaCodigo(codigoProducto)<0){
            cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
            cout<<"INGRESE CODIGO DE PRODUCTO: ";
            cin>>codigoProducto;
    }
    strcpy(descripcion,buscardescripcion(codigoProducto));
    cout<<"PRODUCTO: "<<descripcion<<endl;
    cout<<"INGRESE CANTIDAD: ";
    cin>>cantidad;

    while(validar.validarStockSucursal(codigoProducto,cantidad)==false){
        cout << "LA CANTIDAD INGRESADA ES MAYOR AL STOCK QUE SE TIENE."<<endl;
        cout<<"INGRESE CANTIDAD: ";
        cin>>cantidad;
    }
    precioVenta=buscarPV(codigoProducto);
    cout<<"PRECIO UNITARIO: "<<precioVenta<<endl;
    cout<<"IMPORTE: "<<cantidad*precioVenta<<endl;
    precioCosto=buscarPC(codigoProducto);

}
void DetalleVentas::mostrarArchivo(){
float pv=buscarPV(codigoProducto);
char descripcion[30];
strcpy(descripcion,buscardescripcion(codigoProducto));
cout <<"NRO\tCODIGO\tDETALLE\t\tCANTIDAD\tPU\tTOTAL"<<endl;
cout <<nroLinea<<"\t"<<codigoProducto<<"\t"<<descripcion<<"\t"<<cantidad<<"\t\t"<<buscarPV(codigoProducto)<<"\t"<<pv*cantidad<<endl;
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


#endif // DETALLEVENTAS_H_INCLUDED
