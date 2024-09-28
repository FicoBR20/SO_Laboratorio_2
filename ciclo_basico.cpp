/*
Archivo: ciclo_basico.cpp
Autor: federico.barbeetti@correounivalle.edu.co>
Fecha creación: 2024-09-26
Fecha última modificación: 2024-09-27 
Licencia: GNU-GPL
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream> //files c-r-w
using namespace std;

/**
 * Se define la estructura de los registros
 */
struct setup_registro{
    string b_tipo;// puede ser SET, LDR, SUB, ADD, SHW, END.
    string c_p_memory;// posicion de memoria del registro
    string d_get_value;// valor a transar, puede ser NULL
};


/**
 * vector contenedor de los registros a procesar.
 */
vector<setup_registro>tarea_actual;

/**
 * representa las entidades que intervienen en el ciclo basico de instrucciones.
 */
string cpu[7] = {"Unidad_de_control []",
                "PC []", 
                "Acumulador []", 
                "ICR []", 
                "ALU []",
                "MAR []", 
                "MDR []"};

/**
 * funcion que entrega un string formateado especialmente
 * a fin de presentar la secuencia de las modificaciones
 * sucesivas en el ciclo basico de instrucciones.
 */
string info_secuencia(string info_cpu[7]){

    string salida = "\nUnidad_de_control [ " + info_cpu[0] + " ]" + "\t\t" + "PC [ " + info_cpu[1] + " ]" + "\nAcumulador [ " + info_cpu[2] + " ]" + "\t\t\t" + "ICR [ " + info_cpu[3] + " ]\n" + "ALU [ " + info_cpu[4] + " ]" + "\t\t\t\t" + "MAR [ " + info_cpu[5] +
    "\t\n\t\t\t\t\t" +"MDR [ " + info_cpu[6] + " ]\n";


    return salida;

}



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
/**
 * funcion que mostrara en consola la huella
 * del ciclo basico de instruccion.
 */
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
 * funcion para configurar los registros
 * e incluirlos en un arreglo
 */
void conf_registros (setup_registro my_register,string ty, string pmem, string value){
   

    my_register.b_tipo=ty;
    my_register.c_p_memory=pmem;
    my_register.d_get_value=value;

    tarea_actual.push_back(my_register);

}
/**
 * funcion que simula el ENGINE que maneja los procesos
 * durante el cilo basico de instrucciones
 */
int engine(vector<setup_registro>tareas){

    int salida_final=99999;//valor por defecto

    /**
     * Pendiente configuracion del flujo con funciones
     * invocadas
     */
    

    return salida_final;//valor defaul es 99999
    


}
/**
 * funcion que inicializa el contador de procesos
 * con el registro recibido
 */
void init_PC(vector<setup_registro>my_reg){



    string aux="";
    

    int tmp;


    for (int i = 0; i < my_reg.size(); i++)
    {


        if (my_reg.at(i).b_tipo != "SET")//inicializa pc
        {
            cpu[1]=my_reg.at(i).c_p_memory;



            cout<<"vamos fico "<<endl;
        
        }
        
    }



}


int main()
{
    vector<setup_registro>mistareas;//instancia en main.

    int muestra;//probador temporal

    //lista de registros
    setup_registro set1, set2, set3, ldr1, add1, sub1, str1, shw1,end1;

    //configuracion de los registros.
    conf_registros(set1, "SET", "106", "0");
    conf_registros(set2, "SET", "105", "20");
    conf_registros(set3, "SET", "110", "40");
    conf_registros(ldr1, "LDR", "110", "NULL");
    conf_registros(add1, "ADD", "105", "NULL");
    conf_registros(sub1, "SUB", "110", "NULL");
    conf_registros(str1, "STR", "106", "NULL");
    conf_registros(shw1, "SHW", "106", "NULL");
    conf_registros(end1, "END", "NULL", "NULL");

    mistareas=tarea_actual;//asignacion entre vectores.

    //comprobacion
    for (setup_registro reg : mistareas)
    {
        cout<<reg.b_tipo<<reg.d_get_value<<endl;
    }
    
    //comprobacion
    muestra=engine(mistareas);

    init_PC(mistareas);
    
    cout<<" estamos en camino\n";
    return 0;
}
