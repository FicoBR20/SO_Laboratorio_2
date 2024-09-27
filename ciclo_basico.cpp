/*
Archivo: ciclo_basico.cpp
Autor: federico.barbeetti@correounivalle.edu.co>
Fecha creación: 2024-09-26
Fecha última modificación: 2024-09-27 
Licencia: GNU-GPL
*/


#include <iostream>
#include <vector>
#include <fstream> //files c-r-w
using namespace std;

/**
 * variable que regisrara paso a paso la
 * huella del ciclo basico de instruccion.
 */
//ofstream info_compiler("data_register.txt");
/**
 * variable que mostrara en consola la huella
 * del ciclo basico de instruccion.
 */
//ifstream read_info("data_register.txt");
/**
 * funcion que escribe cada iteraccion del ciclo basico
 * de instruccion en un archivo de texto.
 */
void huellera (string iteracion){
    ofstream info_compiler("data_regiter.txt");
    int indice=1;//numerador lineas
    info_compiler<<to_string(indice)<<" "<<iteracion<<" \n";
    info_compiler.close();
    indice++;
}

void shower (){
    string renglon="";//out aux
    ifstream read_info("data_register.txt");
    while (getline(read_info, renglon))
    {
        cout<<renglon;
    }
    read_info.close();
    

}




/**
 * Se define la estructura de los registros
 */
struct set_registros{
    string id_registro;//consecutivo del registro.
    string tipo;// puede ser SET, LDR, SUB, ADD, SHW, END.
    string p_memory;// posicion de memoria del registro
    string get_value;// valor a transar
};

/**
 * vector contenedor de los registros a procesar.
 */
vector<set_registros>tarea_actual;

/**
 * representa las entidades que intervienen en el ciclo basico de instrucciones.
 */
vector<string>ent_procesadoras = {"Unidad_de_control", "Acumulador", "ALU", "PC", "ICR", "MDR"};



/**
 * funcion para configurar los registros
 * e incluirlos en un arreglo
 */
void conf_registros (set_registros my_register,string ids, string ty, string pmem, string value){
   

    my_register.id_registro=ids;
    my_register.tipo=ty;
    my_register.p_memory=pmem;
    my_register.get_value=value;

    tarea_actual.push_back(my_register);




}
/**
 * funcion que representa la configuracion de los procesos
 * durante el cilo basico de instrucciones
 */
int engine(vector<set_registros>tareas){

    int salida_final=99999;//valor por defecto

    /**
     * Pendiente configuracion del flujo con funciones
     * invocadas
     */
    

    return salida_final;//valor defaul es 99999
    


}

void fn_inicio(set_registros reg){

    tarea_actual[0].id_registro;
}


int main()
{
    vector<set_registros>mistareas;//instancia en main.

    int muestra;//probador temporal

    //lista de registros
    set_registros set1, set2, ldr1, add1, sub1, str1, shw1;

    //configuracion de los registros.
    conf_registros(set1, "77", "SET", "105", "20");
    conf_registros(set2, "78", "SET", "110", "40");
    conf_registros(ldr1, "79", "LDR", "110", "NULL");
    conf_registros(add1, "80", "ADD", "105", "NULL");
    conf_registros(sub1, "81", "SUB", "110", "NULL");
    conf_registros(str1, "82", "STR", "105", "NULL");
    conf_registros(shw1, "83", "SHW", "110", "NULL");

    mistareas=tarea_actual;

    //comprobacion
    for (set_registros reg : mistareas)
    {
        cout<<reg.tipo<<reg.id_registro<<endl;
    }
    
    //comprobacion
    muestra=engine(mistareas);


    
    
    
    cout<<" estamos en camino\n";
    return 0;
}
