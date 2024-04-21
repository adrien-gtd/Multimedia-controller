#ifndef request_handler_
#define request_handler_

#include <string>
#include "controller/Controller.h"

class RequestHandler {
private:
    std::string static fetchMultimedia(std::string body, Controller& my_controller);
    std::string static fetchGroup(std::string body, Controller& my_controller);
    std::string static playMultimedia(std::string body, Controller& my_controller);
    std::string static fetchMultimediaList(Controller& my_controller);
    std::string static fetchGroupList(Controller& my_controller);
    std::string static removeMultimedia(std::string body, Controller& my_controller);
    std::string static removeGroup(std::string body, Controller& my_controller);
    std::string static addGroup(std::string body, Controller& my_controller);
    std::string static addMultimediaToGroup(std::string body, Controller& my_controller);
    std::string static removeMultimediaFromGroup(std::string body, Controller& my_controller);
    std::string static saveControllerState(std::string body, Controller& my_controller);
    std::string static loadControllerState(std::string body, Controller& my_controller);
    std::string static addVideo(std::string body, Controller& my_controller);
    std::string static addImage(std::string body, Controller& my_controller);
    std::string static addFilm(std::string body, Controller& my_controller);
public:
    std::string static handleRequest(std::string header, std::string body, Controller& my_controller);
};

#endif