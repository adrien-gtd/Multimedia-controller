#include "RequestHandler.h"
#include <iostream>
#include <sstream>
#include <fstream>

std::string RequestHandler::handleRequest(std::string header, std::string body, Controller& my_controller)
{
    try
    {
    std::cout << "Handeling request - header: " << header << "; body: " << body << std::endl ;
    if (header == "FetchMultimedia") return fetchMultimedia(body, my_controller);
    if (header == "FetchGroup") return fetchGroup(body, my_controller);
    if (header == "PlayMultimedia") return playMultimedia(body, my_controller);
    if (header == "FetchMultimediaList") return fetchMultimediaList(my_controller);
    if (header == "FetchGroupList") return fetchGroupList(my_controller);
    if (header == "RemoveMultimedia") return removeMultimedia(body, my_controller);
    if (header == "RemoveGroup") return removeGroup(body, my_controller);
    if (header == "AddGroup") return addGroup(body, my_controller);
    if (header == "AddMultimediaToGroup") return addMultimediaToGroup(body, my_controller);
    if (header == "RemoveMultimediaFromGroup") return removeMultimediaFromGroup(body, my_controller);
    if (header == "SaveControllerState") return saveControllerState(body, my_controller);
    if (header == "LoadControllerState") return loadControllerState(body, my_controller);
    if (header == "AddVideo") return addVideo(body, my_controller);
    if (header == "AddImage") return addImage(body, my_controller);
    if (header == "AddFilm") return addFilm(body, my_controller);

    return "WrongRequest";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return "Error";
    }
}

std::pair<std::string, std::string> getMultimediaAndGroupName(const std::string& body)
{
    std::istringstream iss(body);
    std::string multimediaName, groupName;
    std::getline(iss, multimediaName, ']');
    std::getline(iss, groupName, ']');
    multimediaName = multimediaName.substr(1);
    groupName = groupName.substr(2);

    // Check if the strings are empty
    if (multimediaName.empty() || groupName.empty()) {
        return std::pair<std::string, std::string>();
    }
    
    return std::make_pair(multimediaName, groupName);
}

std::string RequestHandler::fetchMultimedia(std::string body, Controller& my_controller) 
{
    std::ostringstream oss;
    my_controller.printMultimedia(body,oss, ';');
    std::string response_body = oss.str();
    if (response_body == "MultimediaNotFound") {
      return "MultimediaNotFound";
    }
    return "MultimediaInfo " + response_body;
}

std::string RequestHandler::fetchGroup(std::string body, Controller& my_controller) 
{
    std::ostringstream oss;
    my_controller.printGroup(body,oss, ';');
    std::string response_body = oss.str();
    if (response_body == "GroupNotFound") {
      return "GroupNotFound";
    }
    return "GroupInfo " + response_body;
}

std::string RequestHandler::playMultimedia(std::string body, Controller& my_controller)
{
    int status = my_controller.playMultimedia(body);
    if (status == 0) return "PlayMultimediaSuccess";
    else return "MultimediaNotFound";
}

std::string RequestHandler::fetchMultimediaList(Controller& my_controller)
{
    std::ostringstream oss;
    my_controller.printAllMultimedia(oss, ';');
    return "MultimediaList " + oss.str();
}

std::string RequestHandler::fetchGroupList(Controller& my_controller)
{
    std::ostringstream oss;
    my_controller.printAllGroup(oss, ';');
    return "GroupList " + oss.str();
}

std::string RequestHandler::removeMultimedia(std::string body, Controller& my_controller)
{
    int status = my_controller.deleteMultimedia(body);
    if (status == 0) return "RemoveMultimediaSuccess";
    else return "MultimediaNotFound";
}

std::string RequestHandler::removeGroup(std::string body, Controller& my_controller)
{
    int status = my_controller.deleteGroup(body);
    if (status == 0) return "RemoveGroupSuccess";
    else return "GroupNotFound";
}

std::string RequestHandler::addGroup(std::string body, Controller& my_controller)
{
    if (body == "") return "WrongFormat";
    auto group = my_controller.createGroup(body);
    return "AddGroupSuccess";
}

std::string RequestHandler::addMultimediaToGroup(std::string body, Controller& my_controller)
{
    auto multimediaAndGroupName = getMultimediaAndGroupName(body);
    if (multimediaAndGroupName.first.empty() || multimediaAndGroupName.second.empty())  return "WrongFormat";
    int status = my_controller.addMultimediaToGroup(multimediaAndGroupName.second, multimediaAndGroupName.first);
    if (status == 0) return "AddMultimediaToGroupSuccess";
    if (status == 1) return "GroupNotFound";
    if (status == 2) return "MultimediaNotFound";
    if (status == 3) return "MultimediaAlreadyInGroup";
    return "UnexpectedError";
}

std::string RequestHandler::removeMultimediaFromGroup(std::string body, Controller& my_controller)
{
    auto multimediaAndGroupName = getMultimediaAndGroupName(body);
    if (multimediaAndGroupName.first.empty() || multimediaAndGroupName.second.empty())  return "WrongFormat";
    int status = my_controller.removeMultimediaFromGroup(multimediaAndGroupName.second, multimediaAndGroupName.first);
    if (status == 0) return "RemoveMultimediaFromGroupSuccess";
    if (status == 1) return "GroupNotFound";
    if (status == 2) return "MultimediaNotFound";
    if (status == 3) return "MultimediaNotInGroup";
    return "UnexpectedError";
}

std::string RequestHandler::saveControllerState(std::string body, Controller& my_controller)
{   
    try 
    {
    std::ofstream ofs(body);
    if (!ofs.is_open()) return "CouldNotOpenFile";
    my_controller.serialize(ofs);
    return "SaveControllerStateSuccess";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return "ErrorWhileSaving";
    }
}

std::string RequestHandler::loadControllerState(std::string body, Controller& my_controller)
{
    try 
    {
    std::ifstream ifs(body);
    if (!ifs.is_open()) return "FileNotFound";
    my_controller.deserialize(ifs);
    return "LoadControllerStateSuccess";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return "ErrorWhileLoading";
    }
}

std::string RequestHandler::addVideo(std::string body, Controller& my_controller)
{
    std::istringstream iss(body);
    std::string name, path, duration_str;
    std::getline(iss, name, ']');
    name = name.substr(1);
    if (name.empty() || !(iss >> path >> duration_str)) return "WrongFormat";
    try {
        int duration = std::stoi(duration_str);
        my_controller.createVideo(duration, name, path);
        return "AddVideoSuccess";
    } catch (const std::invalid_argument& e) {
        return "InvalidDuration";
    } catch (const std::out_of_range& e) {
        return "DurationOutOfRange";
    }
}

std::string RequestHandler::addImage(std::string body, Controller& my_controller)
{
    std::istringstream iss(body);
    std::string name, path, height, width;
    std::getline(iss, name, ']');
    name = name.substr(1);
    if (name.empty() || !(iss >> path >> width >> height)) return "WrongFormat";
    try {
        my_controller.createImage(std::stof(width), std::stof(height), name, path);
        return "AddImageSuccess";
    } catch (const std::invalid_argument& e) {
        return "InvalidDimensions";
    } catch (const std::out_of_range& e) {
        return "DimensionsOutOfRange";
    }
}

std::string RequestHandler::addFilm(std::string body, Controller& my_controller)
{
    std::istringstream iss(body);
    std::string name, path, duration_str, nb_chapters_str;
    std::getline(iss, name, ']');
    name = name.substr(1);
    if (name.empty() || !(iss >> path >> duration_str >> nb_chapters_str)) return "WrongFormat";
    try {
        int duration = std::stoi(duration_str);
        int nb_chapters = std::stoi(nb_chapters_str);
        if (nb_chapters <= 0) return "InvalidNbChapters";
        int* chapters = new int[nb_chapters];
        for (int i = 0; i < nb_chapters; i++) {
            if (!(iss >> chapters[i])) return "WrongFormat";
        }
        my_controller.createFilm(duration, name, path, chapters, nb_chapters);
        return "AddFilmSuccess";
    } catch (const std::invalid_argument& e) {
        return "InvalidDuration";
    } catch (const std::out_of_range& e) {
        return "DurationOutOfRange";
    }
}