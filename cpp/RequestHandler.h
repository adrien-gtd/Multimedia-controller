#ifndef request_handler_
#define request_handler_

#include <string>
#include "controller/Controller.h"

/**
 * @brief RequestHandler class, utility class to handle the request and return the response after processing the request see the communication_protocol_template for more details
 * 
 */
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

    /**
     * @brief Handle the request and return the response after processing the request see the communication_protocol_template for more details
     * 
     * @param header  header of the request
     * @param body  body of the request
     * @param my_controller  controller object
     * @return std::string 
     */
    std::string static handleRequest(std::string header, std::string body, Controller& my_controller);
};

#endif