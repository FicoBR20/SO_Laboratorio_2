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
#include <cstring>
#include <sstream>
using namespace std;

/**
 * Se define la estructura de los registros
 */
struct ram_register{
    int a_secuence=0;//posicion de memoria, puntero de la app.
    string b_tipo;// puede ser SET, LDR, SUB, ADD, SHW, END.
    int c_p_memory;// posicion de memoria del registro
    string d_get_value;// valor a transar, casting a entero segun se necesite.
};


/**
 * vector contenedor de los registros a procesar.
 * usado en la funcion -> conf_registros
 */
vector<ram_register>tarea_actual;

/**
 * string que presenta el paso paso de las entidades que intervienen 
 * en el ciclo basico de instrucciones.
 */
string cpu[14] = {"Unidad de Control ","[  ]",//unidad de control
                " PC ","[  ]", //PC
                " Acumulador ","[  ]",//acum
                " ICR ","[  ]", //icr
                " ALU ","[  ]",//alu
                " MAR ","[  ]",//mar
                " MDR ","[  ]\n"};//mdr

/**
 * funcion que entrega un string con los 4 atributos
 * de un registro de entrada para procesar.
 */
string info_registros_iniciales(ram_register reg_nvo){

    string salida = to_string(reg_nvo.a_secuence) + " " + reg_nvo.b_tipo + " " + to_string(reg_nvo.c_p_memory) + " " + reg_nvo.d_get_value + " \n";
    
    return salida; 
}

/**
 * funcion que entrega un string de un arreglo
 * de string[].
 */
string step_cpu(string basico[]){

    string info_paso="";

    stringstream ssf;
    for (int i = 0; i < basico->size(); i++)
    {
        ssf<<basico[i]<<" \n";
    }
    
    return info_paso=ssf.str(); 
}



/**
 * funcion que escribe cada iteraccion del ciclo basico
 * de instruccion en un archivo de texto.
 */
void writer_data (string iteracion){
    ofstream info_compiler("data_regiter.txt");
    info_compiler<<iteracion<<" \n";
    info_compiler.close();
}
/**
 * funcion que mostrara en consola la huella
 * del ciclo basico de instruccion.
 */
void reader_data_show (){
    string renglon="";//out aux
    ifstream read_info("copiecita.txt");//object
    while (getline(read_info, renglon))
    {
        cout<<renglon;
    }
    read_info.close(); 

}

/**
 * funcion para configurar los registros
 */
ram_register conf_registros (int sec, string ty, int pmem, string value){
   
    ram_register my_register;
    my_register.a_secuence=sec;
    my_register.b_tipo=ty;
    my_register.c_p_memory=pmem;
    my_register.d_get_value=value;

    return my_register;


}

/**
 * funcion que realiza la secuencia de instrucciones para ejecutar
 * un load.
 */

string load_execute (int secuence, string my_cpu[], ram_register my_reg){

    string aux=" ";

    if (my_reg.b_tipo=="load")
    {
        my_cpu[2]=my_reg.c_p_memory;
        my_cpu[10]=my_reg.c_p_memory;
        my_cpu[12]=my_reg.b_tipo , " " , to_string(my_reg.c_p_memory);
        my_cpu[6]=my_reg.b_tipo , " " , to_string(my_reg.c_p_memory);

        my_cpu[2]+=1;
        my_cpu[0]=my_reg.b_tipo , " " , to_string(my_reg.c_p_memory);
        my_cpu[10]=my_reg.c_p_memory;


    }

    return aux;


}






/**
 * funcion que simula el ENGINE que maneja los procesos
 * durante el cilo basico de instrucciones
 */
void engine(vector<ram_register>my_reg){

    int paso=0;//consecutivo paso a paso de cada accion ejecutada.
    int *secuencia=&paso;

    stringstream sst;

    int hd_memory[1000];//memoria
    memset(hd_memory, 0, sizeof(hd_memory));//clean array to ceros

    int pc_cont=1;//representa el contador de programas

    int my_acumulador = 0; // representa el acumulador

    int my_alu = 0; // representa el alu

    string aux="";//auxiliar para casting

    int tmp_v=0;//auxiliar para casting




    for (int i = 0; i < my_reg.size(); i++) //iniciacion del proceso
    {
        
        if (my_reg.at(i).b_tipo=="SET")//cargamos valores en memoria
        {
            
            aux = my_reg.at(i).d_get_value;
        
            tmp_v = stoi(aux);//casting for valor

            hd_memory[my_reg.at(i).c_p_memory]= tmp_v;


        }
        else{

            cpu[3]="00"+to_string(pc_cont);//inicializa PC

            cout<<"paso # "<<paso+1<<" "<<step_cpu(cpu)<<endl;

            /**
             * 
            stringstream ss1;
            for( string x : cpu){
                ss1<<x;
                }
            cout<<ss1.str()<<endl;
             */







            
            if (my_reg.at(i).b_tipo=="LDR")//("LDR", 110, "NULL")
            {
        /*mar*/ cpu[10]="00"+to_string(pc_cont);
        /*mdr*/ cpu[12]=my_reg.at(i).b_tipo + " " + to_string(my_reg.at(i).c_p_memory);
        /*icr*/ cpu[6]=my_reg.at(i).b_tipo + " " + to_string(my_reg.at(i).c_p_memory);
               
            


                cpu[3]="00"+to_string(pc_cont+1);//inicializa PC
        /*uc*/  cpu[0]=my_reg.at(i).b_tipo + " " + to_string(my_reg.at(i).c_p_memory);



        /*mar*/ cpu[10]="00"+to_string(my_reg.at(i).c_p_memory);
        /*mdr*/ cpu[12]=my_reg.at(i).d_get_value;
        /*acum*/cpu[4]=my_reg.at(i).d_get_value;

    


        


        /*mar*/ cpu[5]="00"+to_string(pc_cont);//no se le aumenta nada, ya fue aumentada en 1.

                tmp_v = my_reg.at(i).c_p_memory;

                my_acumulador = my_acumulador + hd_memory[tmp_v];

            }
            else if (my_reg.at(i).b_tipo=="ADD")//"ADD", 105, "NULL"
            {
                tmp_v = my_reg.at(i).c_p_memory;
                            
                my_acumulador = my_acumulador + hd_memory[tmp_v];
                my_alu = my_acumulador;

                pc_cont++;
            }
            else if (my_reg.at(i).b_tipo=="SUB")//"SUB", 110, "NULL"
            {
                tmp_v = my_reg.at(i).c_p_memory;
                            
                my_acumulador = my_acumulador - hd_memory[tmp_v];
                my_alu = my_alu - hd_memory[tmp_v];

                pc_cont++;
                
            }
            else if (my_reg.at(i).b_tipo=="STR")//"STR", 106, "NULL"
            {
                hd_memory[my_reg.at(i).c_p_memory]=my_acumulador;

                pc_cont++;
                
            }
            else if (my_reg.at(i).b_tipo=="SHW")//"SHW", 106, "NULL"
            {
               // cout<<"El valor a mostrar es "<<hd_memory[my_reg.at(i).c_p_memory]<<endl;

                pc_cont++;

            }
            else if (my_reg.at(i).b_tipo=="END")
            {
                cout<<"El valor de alu es: "<<my_alu<<endl;
            }
            else{

                cout<<"hay dificultades...debenos revisar\n";
            
            }
            
            
            
            

        }
        
        


        
    }//cierre for

 


}


int main()
{
    vector<ram_register>mistareas;//arreglo con el CONJUNTO de registros para procesar en CPU

    int muestra;//probador temporal

    //conjunto de registros a configurar
    ram_register set1, set2, set3, ldr1, add1, sub1, str1, shw1,end1;



    //configuracion de los registros.
    set1 = conf_registros(105, "SET", 106, "0");//primera posicion de memoria con info.
    set2 = conf_registros(106, "SET", 105, "20");
    set3 = conf_registros(107, "SET", 110, "40");
    ldr1 = conf_registros(108, "LDR", 110, "NULL");
    add1 = conf_registros(109, "ADD", 105, "NULL");
    sub1 = conf_registros(110, "SUB", 110, "NULL");
    str1 = conf_registros(111, "STR", 106, "NULL");
    shw1 = conf_registros(112, "SHW", 106, "NULL");
    end1 = conf_registros(113, "END", 999, "NULL");// el final se evalua con "END"

    /**
     * llenado del arreglo contenedor de los registros a procesar
     */
    mistareas.push_back(set1);
    mistareas.push_back(set2);
    mistareas.push_back(set3);
    mistareas.push_back(ldr1);
    mistareas.push_back(add1);
    mistareas.push_back(sub1);
    mistareas.push_back(str1);
    mistareas.push_back(shw1);
    mistareas.push_back(end1);

    /**
     * generamos un archivo de texto con el estado inicial de la memoria
     */
    stringstream ls;
    ls<<"\nRegistros iniciales memoria para procesar\n";
    for (ram_register my_reg : mistareas)
    {
        string receptor = info_registros_iniciales(my_reg);//strig de cada registro
        ls<<receptor;

    }
    cout<<ls.str()<<endl;//muestra en consola info inicial.
    writer_data(ls.str());//genera "data_registes.txt"
    


    
  

    engine(mistareas);
    
    cout<<" Gracias a Dios, estamos en camino\n";
    return 0;
}
