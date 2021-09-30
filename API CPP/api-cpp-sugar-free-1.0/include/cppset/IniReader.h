/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef INIREADER_H
#define INIREADER_H

#include <string>
#include <fstream>
#include <sstream>

class IniReader
{
    public:
        IniReader();
        virtual ~IniReader();
        bool open( std::string fileName);
        IniReader* selectSection( std::string section );
        std::string getValue( std::string key );
        void close();


    private:
        std::ifstream _fileInput;
        std::string  _dataSection ;
        std::string _BufferData ;

        void ReadFile();
};

IniReader::IniReader()
{
    //ctor
}


//Abre el archivo cuyo nombre se recibe por parámetro, y retorna un booleando dependiendo de si se abrió correctamente o no.
bool IniReader::open( std::string fileName )
{
   _fileInput.open(fileName.c_str());
    return  !_fileInput ? false : true;
}


//Se leen los datos del archivo abierto, y se crea una variable _buffer. Luego se crea una variable para almacenar la posición
//inicial del buffer, buscando en el atributo _BufferData el valor del parámetro section que es recibido. Se almacena en la variable
//como un valor unsigned, por lo que se comprueba si el valor es -1. De ser así se regresa el objeto en sí. Caso contrario, a la
//variable _buffer se le asigna un substring del atributo _BufferData, en base a la posición inicial del buffer (cuya variable se
//creó con anterioridad). Luego se crean tres variables más, la primera para la posición inicial dentro de _buffer; la segunda para
//la posición al final de la misma variable; y la tercera es para obtener el tamaño del string, que se obtiene restando la posición
//final del _buffer, con la inicial del mismo. A continuación, al atributo _dataSection se le asigna el valor equivalente al substring
//de _buffer entre la posición inicial, y el tamaño del string. Para finalizar se retorna el objeto.
IniReader* IniReader::selectSection( std::string section )
{

    ReadFile();
    std::string _buffer;
    size_t posInitialBuffer = _BufferData.find("["+section+"]");

    if (_BufferData.find("["+section+"]") == (std::string::npos))
    {
        return this;
    }
    else
    {
        _buffer = _BufferData.substr(posInitialBuffer);
        size_t posInitial = _buffer.find("["+section+"]");
        size_t posEnd = _buffer.find_first_of("[",posInitial+1);

        size_t sizeOfString = posEnd-posInitial;
        _dataSection = _buffer.substr(posInitial,sizeOfString );

        return this;
    }
}

//Recine una key, la cual se utiliza para buscar el elemento en tal índice en el atributo _dataSection.
//Si _dataSection no está vacío o si pos es diferente a -1 (es el valor dado a std::string::npos), se retorna un string vacío.
//Caso contrario, se asigna a una nueva variable el primer valor que sea equivalente a '={la posición recibida}' más 2.
//A continuación, se asigna a otra variable el valor recibido al buscar el primer elemento de _dataSection, que coincida con
//" {el valor de la variable anterior}".
//Luego, se crea una variable string para almacenar una parte del _dataSection, partiendo desde la posición creada en la primer variable
//hasta la posición de la segunda variable creada. Ese string es retornado en la función.
std::string IniReader::getValue(std::string key)
{
    unsigned int pos ;
    pos  = _dataSection.find(key);

    if ((pos==std::string::npos) || (_dataSection == ""))
    {
        return "";
    }
    else
    {
        int posValue = (_dataSection.find_first_of("=",pos) + 2);
        int posEndValue = _dataSection.find_first_of(" ",posValue);
        size_t sizeOfString = posEndValue-posValue;

        std::string value = _dataSection.substr(posValue,sizeOfString);

        return value ;
    }
}


//Cierra el archivo
void IniReader::close()
{
    _fileInput.close();
}


//Mientras no sea el final del archivo, se crea una variable _buffer para leer la línea del archivo y luego 
//convertirla en string y añadirla al atributo _BufferData, separado previamente por un espacio.
void IniReader::ReadFile()
{
    while( !_fileInput.eof())
    {
        std::string _buffer;

       _fileInput >> _buffer;
       _BufferData += " " + std::string(_buffer);
    }
}

IniReader::~IniReader()
{
    //dtor
}

#endif // INIREADER_H
