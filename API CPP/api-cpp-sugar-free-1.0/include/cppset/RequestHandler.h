/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef I_REQUEST_HANDLER_H
#define I_REQUEST_HANDLER_H

#include <iostream>
#include <memory>
#include <cppset/ComponentFactory.h>
#include <cppset/IService.h>
#include <cppset/IniReader.h>
#include <vendors/nlohmann/json.hpp>

// https://developer.mozilla.org/es/docs/Web/HTTP/Status
class RequestHandler
{
    private:
        nlohmann::json getRequestData()
        {
            //deserialize from standard input
            nlohmann::json requestData;
            
            //Intenta obtener la información y almancenarla dentro de requestData, pero en el caso de que no se pueda
            //se crea una respuesta de excepción, la cual luego se imprime en pantalla, imprimiendo también una línea que 
            //especifica que se espera una respuesta de tipo JSON y la codificación de utf-8. Luego se finaliza la funcion.
            //En caso de que se haya obtenido una respuesta, ésta será retornada por la función.
            try
            {
                std::cin >> requestData;
            }
            catch(nlohmann::json::exception& e)
            {
                nlohmann::json exception_response = {
                                {"error_status", true},
                                {"message", "415 Unsupported Media Type"},
                                {"debug_message", "json standard input fail, incorrect format"}, 
                                {"data",{ 
                                    {"message",e.what()},
                                    {"exception id", e.id}
                                }}
                            };
               std::cout << "Content-type:application/json; charset=utf-8\r\n\r\n";
               std::cout << exception_response; 
               exit (EXIT_FAILURE);     //EXIT_FAILURE corresponde a la stdlib.h, y su valor es de 1       
            }

            return requestData;
        }
        
    public:
        RequestHandler(){}
        
        virtual ~RequestHandler(){}


        //Inicializa un puntero inteligente de iniReader, para luego llamar a su método open pasándole el nombre del
        //archivo 'configuration.ini' (que contiene información de configuración), y luego se crea un string para obtener
        //de la sección "GENERAL" del iniReader, el valor de "servicesPath". Luego se crea una variable tipo JSON para almacenar
        //la respuesta que retorna el método getRequestData. A continuación, se crea un string para almacenar el valor de 'servicio'
        //dentro de la respuesta obtenida. También se crean punteros inteligentes, de ComponentFactory y de IService y luego se llama
        //al método call pasándole la respuesta obtenida previamente.
        void handle()
        {
            std::shared_ptr<IniReader> iniReader( new IniReader() );
            iniReader->open("configuration.ini");
            std::string servicesPath = iniReader->selectSection("GENERAL")->getValue("servicesPath");

            nlohmann::json requestData = this->getRequestData();
            std::string serviceName = requestData["service"];

            std::shared_ptr<ComponentFactory> cF(new ComponentFactory());
            std::shared_ptr<IService> service = cF->create<IService>(servicesPath + serviceName);
            
            service->call(requestData);
        }
};
#endif // I_REQUEST_HANDLER_H
