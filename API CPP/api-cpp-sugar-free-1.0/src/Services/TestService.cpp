/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <memory>
#include <cppset/IService.h>
#include <cppset/ResponseHandler.h>

class TestService : public IService
{
    private:
        nlohmann::json data;
        std::shared_ptr<ResponseHandler> responseHandler;

        //SERVICES ACTIONS:
        //Cada acción retorna un JSON, conteniendo información relacionada a la acción seleccionada.
        void create()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Create OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Create Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

        void read()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Read OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Read Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

        void update()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Update OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Update Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

        void del()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Delete OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Delete Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

    public:
        TestService()
        {
            this->responseHandler = std::make_shared<ResponseHandler>();
        }

        //Mediante el método call, se recibe un json como parámetro, el cual se almacena en el atributo data,
        //y luego en una nueva variable se almacena la propiedad action de data, para ser comparada con diversas
        //acciones que podrían realizarse y, si es en algún caso correcto, ejecutar el método correspondiente.
        void call(nlohmann::json data)
        {
            this->data = data;
            std::string action = this->data["action"];
            if(action == "create") this->create();
            if(action == "read") this->read();
            if(action == "update") this->update();
            if(action == "del") this->del();
        }
};

extern "C" std::shared_ptr<IService> create(std::string);

std::shared_ptr<IService> create(std::string typeinfo)
{
    return ( typeid(IService).name() == typeinfo )? std::make_shared<TestService>() : nullptr;
}
