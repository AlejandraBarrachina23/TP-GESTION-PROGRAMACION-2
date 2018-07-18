#ifndef DETALLECOMPRA_H_INCLUDED
#define DETALLECOMPRA_H_INCLUDED

bool DetalleCompra::grabarArchivo(){

    FILE *p;
    p=fopen("archivos/detalleCompra.dat","ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(DetalleCompra),1,p);
    fclose(p);
    return true;
}
void DetalleCompra::mostrarArchivo(){
    Producto unProducto;
    Validador validar;
    int pos;
    pos=validar.existenciaCodigo(codigoProducto);
    unProducto.leerArchivo(pos);
    cout <<"NRO\tDETALLE\t\tCANTIDAD\t\tPN\t\tPB\t\tPV"<<endl;
    cout <<nroLinea<<"\t\t"<<unProducto.getDescripcion()<<"\t\t"<<cantidad<<"\t\t\t"<<precioNeto<<"\t\t"<<precioBruto<<"\t\t"<<precioVenta<<endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
}
bool DetalleCompra::leerArchivo(int cod){

    bool leyo;
    FILE *p;
    p=fopen("archivos/detalleCompra.dat","rb");
    if(p==NULL)return false;
    fseek(p,cod*sizeof(DetalleCompra),0);
    leyo=fread(this,sizeof(DetalleCompra),1,p);
    fclose(p);
    return leyo;
}
void DetalleCompra::cargarDatos(int codFactura,int lineas, int codProveedor){

    Validador validar;
    Producto unProducto;
    char detalle [30];
    int pertenencia;

    gotoxy(35,8);cout << "CODIGO DE PRODUCTO: ";
    cin >> codigoProducto;

    pertenencia=validar.perteneceAproveedor(codigoProducto,codProveedor);
    while(pertenencia!=1){
        if(pertenencia==0){
            textcolor(cROJO_CLARO,cAZUL);
            cout << "EL PRODUCTO INGRESADO NO PERTENECE A ESE PROVEEDOR."<<endl;
            getch();
            textcolor(cBLANCO,cAZUL);
            cout << "CODIGO DE PRODUCTO: ";
            cin >> codigoProducto;
        }
        else if(pertenencia==-1){
            textcolor(cROJO_CLARO,cAZUL);
            cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
            getch();
            textcolor(cBLANCO,cAZUL);
            cout << "CODIGO DE PRODUCTO: ";
            cin >> codigoProducto;
        }
        pertenencia=validar.perteneceAproveedor(codigoProducto,codProveedor);
    }

    cout << strcpy(detalle,buscardescripcion(codigoProducto))<<endl;
    cout << "CANTIDAD:";
    cin >> cantidad;
    while(!validar.intervaloDeNumeros(cantidad,1,999)){
        textcolor(cROJO_CLARO,cAZUL);
        cout << "NUMERO INVALIDO. INGRESE UN VALOR DEL 1 AL 999."<<endl;
        getch();
        textcolor(cBLANCO,cAZUL);
        cout << "CANTIDAD:";
        cin >> cantidad;
    }
    cout << "PRECIO NETO: ";
    cin >> precioNeto;
    while(!validar.intervaloDeNumeros(precioNeto,1,9999)){
        textcolor(cROJO_CLARO,cAZUL);
        cout << "NUMERO INVALIDO. INGRESE UN VALOR DEL 1 AL 9999."<<endl;
        getch();
        textcolor(cBLANCO,cAZUL);
        cout << "PRECIO NETO: ";
        cin >> precioNeto;
    }
    nroFactura=codFactura;
    nroLinea=lineas;
}
void DetalleCompra::calculoPrecioBruto(Producto &unProducto){

    Validador validar;
    RetencionesImpositivas ri;
    float descuento;
    cout << "DESCUENTO: ";
    cin >> descuento;
    while(!validar.intervaloDeNumeros(descuento,0,100)){
        cout << "NUMERO INVALIDO. INGRESE UN VALOR DE 0 AL 100."<<endl;
        cout << "DESCUENTO: ";
        cin >> descuento;
        }
    precioNeto=precioNeto*((100-descuento)/100);
    cout << "PRECIO NETO-DESCUENTO: "<<precioNeto<<endl;
    ri.setIVA(unProducto.getPorcentuales().getIVA()/100*precioNeto);
    cout << "PRECIO CON IVA: "<< ri.getIVA()<<endl;
    ri.setPercepcion(ri.getIVA()*unProducto.getPorcentuales().getPercepcion()/100);
    cout << "PRECIO PERCEPCION SOBRE IVA: "<<ri.getPercepcion()<<endl;
    ri.setIB(precioNeto*unProducto.getPorcentuales().getIB()/100);
    cout << "PRECIO CON IB:" <<ri.getIB()<<endl;
    setPrecioBruto(ri.getIVA()+ri.getPercepcion()+ri.getIB()+precioNeto);
    cout << "PRECIO BRUTO:" << getPrecioBruto() <<endl;
}
#endif // DETALLECOMPRA_H_INCLUDED
