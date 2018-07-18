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
void DetalleCompra::mostrarEncabezado(){

    cout<<" "<<(char)186<<"NRO     DETALLE             CANT     PN        PB        PV  "<<endl;
    cout<<" "<<(char)186<<"==================================================================================================="<<endl;

}
void DetalleCompra::mostrarArchivo(){
    char descripcion[20];
    strcpy(descripcion,buscardescripcion(codigoProducto));

    std::cout << setiosflags(ios::left)<<" "<<(char)186<<setw(8)<<codigoProducto<<setw(20)<<descripcion<<setw(8)<<cantidad<<fixed<<setprecision(2)<<setw(10)<<precioNeto<<setw(10)<<precioBruto<<setw(10)<<precioVenta<<endl;
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
            gotoxy(25,9);cout << "EL PRODUCTO INGRESADO NO PERTENECE A ESE PROVEEDOR."<<endl;
            getch();
            gotoxy(25,9);cout << "                                                   "<<endl;
            gotoxy(55,8);cout << "           "<<endl;
            textcolor(cBLANCO,cAZUL);
            gotoxy(35,8);cout << "CODIGO DE PRODUCTO: ";
            gotoxy(55,8);cin >> codigoProducto;
        }
        else if(pertenencia==-1){
            textcolor(cROJO_CLARO,cAZUL);
            gotoxy(34,9);cout << "EL CODIGO INGRESADO NO EXISTE."<<endl;
            getch();
            gotoxy(34,9);cout << "                              "<<endl;
            gotoxy(55,8);cout << "           "<<endl;
            textcolor(cBLANCO,cAZUL);
            gotoxy(35,8);cout << "CODIGO DE PRODUCTO: ";
            gotoxy(55,8);cin >> codigoProducto;
        }
        pertenencia=validar.perteneceAproveedor(codigoProducto,codProveedor);
    }

    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(35,9);cout << "DETALLE: "<<strcpy(detalle,buscardescripcion(codigoProducto))<<endl;
    textcolor(cBLANCO,cAZUL);
    gotoxy(35,10);cout << "CANTIDAD: ";
    cin >> cantidad;
    while(!validar.intervaloDeNumeros(cantidad,1,999)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(28,11);cout << "NUMERO INVALIDO. INGRESE UN VALOR DEL 1 AL 999."<<endl;
        getch();
        gotoxy(28,11);cout << "                                               "<<endl;
        gotoxy(45,10);cout << "             "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,10);cout << "CANTIDAD:";
        gotoxy(45,10);cin >> cantidad;
    }
    gotoxy(35,11);cout << "PRECIO NETO: ";
    cin >> precioNeto;
    while(!validar.intervaloDeNumeros(precioNeto,1,9999)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(25,12);cout << "NUMERO INVALIDO. INGRESE UN VALOR DEL 1 AL 9999."<<endl;
        getch();
        gotoxy(25,12);cout << "                                                "<<endl;
        gotoxy(48,11);cout << "         "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,11);cout << "PRECIO NETO: ";
        gotoxy(48,11);cin >> precioNeto;
    }
    nroFactura=codFactura;
    nroLinea=lineas;
}
void DetalleCompra::calculoPrecioBruto(Producto &unProducto){

    Validador validar;
    RetencionesImpositivas ri;
    float descuento;
    gotoxy(35,12);cout << "DESCUENTO: ";
    cin >> descuento;
    while(!validar.intervaloDeNumeros(descuento,0,100)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(15,13);cout << "NUMERO INVALIDO. INGRESE UN VALOR DE 0 AL 100."<<endl;
        getch();
        gotoxy(20,13);cout<< "                                               "<<endl;
        gotoxy(46,12);cout<< "         "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,12);cout << "DESCUENTO: ";
        gotoxy(46,12);cin >> descuento;
        }
    precioNeto=precioNeto*((100-descuento)/100);
    //cout << "PRECIO NETO-DESCUENTO: "<<precioNeto<<endl;
    ri.setIVA(unProducto.getPorcentuales().getIVA()/100*precioNeto);
    //cout << "PRECIO CON IVA: "<< ri.getIVA()<<endl;
    ri.setPercepcion(ri.getIVA()*unProducto.getPorcentuales().getPercepcion()/100);
    //cout << "PRECIO PERCEPCION SOBRE IVA: "<<ri.getPercepcion()<<endl;
    ri.setIB(precioNeto*unProducto.getPorcentuales().getIB()/100);
    //cout << "PRECIO CON IB:" <<ri.getIB()<<endl;
    setPrecioBruto(ri.getIVA()+ri.getPercepcion()+ri.getIB()+precioNeto);
    //cout << "PRECIO BRUTO:" << getPrecioBruto() <<endl;
}
#endif // DETALLECOMPRA_H_INCLUDED
