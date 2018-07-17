#ifndef CABECERADOCUMENTO_H_INCLUDED
#define CABECERADOCUMENTO_H_INCLUDED

void CabeceraDocumento::mostrarArchivo(){

    recuadro(1, 1,100, 25, cBLANCO, cAZUL);
    recuadro(1, 1,100, 3, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(2,2);cout << "FECHA DE EMISION: "<<FechaDeEmision.getDia()<<"/"<<FechaDeEmision.getMes()<<"/"<<FechaDeEmision.getAnio();
    gotoxy(50,2);cout << "USUARIO: "<<usuario;
    gotoxy(2,3);cout<<"NUMERO DE FACTURA: "<<NrodeFactura<<endl;
    textcolor(cBLANCO, cAZUL);

}
#endif // CABECERADOCUMENTO_H_INCLUDED
