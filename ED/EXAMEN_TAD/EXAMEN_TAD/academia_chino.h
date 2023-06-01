
// RUBEN GOMEZ BLANCO DG16 

// COMENTARIO SOBRE LA SOLUCIÓN
// NO OLVIDES PONER EL COSTE JUSTIFICADO DE CADA OPERACIÓN JUNTO A ELLA

#ifndef ACADEMIACHINO
#define ACADEMIACHINO

#include <iostream>     
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
using namespace std;

using DNI = string;
using curso = int;

class academia_chino {
    unordered_map<DNI, pair<curso, list<DNI>::iterator>> alumnos; //Para cada alumno, el curso en el que esta(0 si esta graduado) y donde esta en la lista correspondiente
    vector<list<DNI>> por_curso;//para cada curso, una lista de alumnos en ese curso ordenados por orden inverso de llegada, el primero sera el ultimo que llega
    set<DNI>graduados_conj; //guardo este set ordenado de los graduados por dni para que en la funcion graduados se de orden g con g el numero de graduados

    /*Eligo esta estructura ya que para la funcion graduados te pide los alumnos ordenados alfabeticamente, por eso escojo el set ordenado, 
    ademas necesito tener una lista de alumnos para cada curso y lo consigo con ese vector. Escogo una lista dentro de cada posicion del vector y no por ejemplo
    una cola, ya que necesito extraer o borrar elementos que puedan estar a mitad de la lista cuando hago promocionar, por ello guardo el iterador en la informacion
    de cada alumno.
    Como hay operaciones que buscan por dni y necesitas accceder al curso o a su  posicion en la lista de su grupo para borrarlo de esa, he decididio 
    que mi estructura de alumnos sea un diccionario desordenado,no necesita orden, con claves alumnos y valores un par el curso y un iterador a la lista de alumnos
    que tiene cada curso para poder hacer erase de ese elemento apuntado por el iterador.
    Ademas defino la operacion privada insertar_por_grupo al que le pasa un dni y un curso y te lo inserta al principio de la lista de ese curso, devolviendo el iterador
    que apunta a ese alumno. Esto nos sera muy util en las funciones nuevo y promocionar*/

    list<DNI>::iterator insertar_por_grupo(DNI c, curso p) { //O(1) al acceder a la posicion de un vector y hacer insert en un dicc no ordenado
        auto& lista = por_curso[p];
        return lista.insert(lista.begin(), c); //devuelve el iterador que habra que insertar en el diccionario
    }
public:
    academia_chino():por_curso(7){}// De la posicion 1 a la ultima, la 6, guardo las listas de alumnos por curso en su curso corresponiente, la posicion 0 no la uso

    void nuevo_estudiante(DNI dni,curso grupo) { //O(1) al solicitar datos de un dicc no ordenado, y el metodo insert de un diccionario es constante al ser no ordenado
        if (alumnos.count(dni) > 0) {
            throw domain_error("Estudiante existente");
        }
        if (grupo < 1 || grupo>6) {
            throw domain_error("Grupo incorrecto");
        }
        alumnos.insert({ dni,{grupo,insertar_por_grupo(dni,grupo)} });
    }
    void promocionar(DNI dni) {     //O(log n) con n numero de elementos en el set al trabajar con set ordenado, el insert de un set ordenado tiene orden log(n), las demas tienen coste constante al ser operaciones en dicc no ordenado
        auto alumno = alumnos.find(dni);
        if (alumno == alumnos.end()) {
            throw domain_error("Estudiante no existente");
        }
        else if (alumno->second.first == 0) {
            throw domain_error("Estudiante ya graduado");
        }
        auto& info_alumno = alumno->second;
        if (info_alumno.first == 6) {
            graduados_conj.insert(dni);//La que hace que el coste en el caso peor sea log(n)
            por_curso[info_alumno.first].erase(info_alumno.second);
            info_alumno.first = 0; //pongo a los alumnos graduados en el curso 0, y no los borro de la academia
            info_alumno.second = por_curso[0].end();  
        }
        else {
            por_curso[info_alumno.first].erase(info_alumno.second);
            info_alumno.first++;
            info_alumno.second = insertar_por_grupo(dni, info_alumno.first);
        }
    }

    int grupo_estudiante(DNI dni){ //O(1) ya que accedo a los datos de un dicc no ordenado
        auto alumno = alumnos.find(dni);
        if (alumno == alumnos.end()) {
            throw domain_error("Estudiante no existente");
        }
        else if (alumno->second.first ==0) {
            throw domain_error("Estudiante ya graduado");
        }
       
        return alumno->second.first;
    }

    list<DNI> graduados(){ //O(g) con g el numero de estudiantes graduados
        list<DNI> res;
        for (auto graduado : graduados_conj) {
            res.push_back(graduado);
        }
        return res;
    }

    DNI novato(curso grupo){ //O(1) ya que accedo a una posicion de un vector en coste constante y luego hago .front() de una lista, coste constante
        if (grupo < 1 || grupo>6) {
            throw domain_error("Grupo incorrecto");
        }
        if (por_curso.at(grupo).empty()) {
            throw domain_error("Grupo vacio");
        }
        return por_curso.at(grupo).front();
    }

};

#endif
