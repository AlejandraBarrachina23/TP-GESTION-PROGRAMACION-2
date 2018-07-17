#ifndef CABECERADOCUMENTO_H_INCLUDED
#define CABECERADOCUMENTO_H_INCLUDED

void CabeceraDocumento::mostrarArchivo(){

    cout << "====================================================================================================="<<endl;
    cout << "\tFECHA: "<<FechaDeEmision.getDia()<<"/"<<FechaDeEmision.getMes()<<"/"<<FechaDeEmision.getAnio()<<"\t\tUSUARIO:"<< usuario<<"\t\t\tNUMERO DE FACTURA:"<<NrodeFactura<<endl;

}
#endif // CABECERADOCUMENTO_H_INCLUDED
