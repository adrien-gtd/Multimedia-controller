//
// main.cpp
// Created on 21/10/2018
//
#define version_2

#include "Controller.h"
#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include <fstream> 

const int PORT = 3331;

std::string handleRequest(std::string header, std::string body, Controller my_controller);

int main(int argc, const char *argv[])
{

#ifdef version_1
  // Multimedia **mutlimedia_array = new Multimedia *[10];
  // int count = 0;
  // mutlimedia_array[count++] = new Video(30, "asset/video1.mp4", "Ma video 1");
  // mutlimedia_array[count++] = new Image(14, 10, "asset/image1.jpeg", "Mon image 1");
  // mutlimedia_array[count++] = new Video(25, "asset/video2.mp4", "Ma video 2");
  // mutlimedia_array[count++] = new Image(14, 10, "asset/image2.jpeg", "Mon image 2");
  // mutlimedia_array[count++] = new Video(52, "asset/video3.mp4", "Ma video 3");
  // mutlimedia_array[count++] = new Image(14, 10, "asset/image3.jpeg", "Mon image 3");
  // Image * i = new Image(14, 10, "asset/image3.jpeg", "Mon image 3");
  // i->print(std::cout);

  // for (unsigned int index = 0; index < count; index++) {
  //     mutlimedia_array[index]->print(std::cout);
  // }

  // int * myChapters = new int[5]{6, 3, 5, 7, 3};
  // Film* myFilm = new Film(25, "asset/video2.mp4", "Ma video 2", myChapters,5);
  // myFilm->print(std::cout);

  // myChapters[2] = 10;
  // myFilm->print(std::cout);

  // myFilm->setChapters(myChapters, 5);
  // myChapters[2] = 15;
  // myFilm->print(std::cout);

#endif

#ifdef version_2
  Controller *my_controller = new Controller();

  auto group1 = my_controller->createGroup("Ma liste");
  group1->push_front(my_controller->createImage(14, 10, "Mon image 1", "asset/image1.jpeg"));
  group1->push_front(my_controller->createImage(14, 10, "Mon image 2", "asset/image2.jpeg"));
  group1->push_front(my_controller->createVideo(25, "Ma video 2", "asset/video2.mp4"));
  group1->push_front(my_controller->createImage(14, 10, "Mon image 3", "asset/image3.jpeg"));
  group1->push_front(my_controller->createVideo(52, "Ma video 3", "asset/video3.mp4"));
  group1->push_front(my_controller->createFilm(25, "Mon Film 1", "asset/video2.mp4", new int[5]{6, 3, 5, 7, 3}, 5));

  my_controller->printGroup("Ma liste", std::cout);
  my_controller->printAllGroup(std::cout);
  my_controller->printAllMultimedia(std::cout);

  std::ofstream file("example.txt");
  my_controller->serialize(file);
  file.close();

  std::cout << "\n***** Objects serialized *****\n" << std::endl;

  std::ifstream file1("example.txt");
  Controller* my_controller2 = new Controller();


  my_controller2->deserialize(file1);

  my_controller->printGroup("Ma liste", std::cout);
  my_controller->printAllGroup(std::cout);
  my_controller->printAllMultimedia(std::cout);
  // std::cout << "\nREMOVING ****** \n"
  //           << std::endl;

  // group1->pop_front();
  // group1->pop_front();
  // group1->pop_front();
  // group1->pop_front();

  // std::cout << "\nPrinting the content ****** \n"
  //           << std::endl;
  // my_controller->printGroup("Ma liste", std::cout);
  // my_controller->printAllGroup(std::cout);
  // my_controller->printAllMultimedia(std::cout);

  #endif

  #ifdef version_3

  // cree le TCPServer
  auto *server =
      new TCPServer([&](std::string const &request, std::string &response)
                    {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // processing the request
    std::istringstream iss(request);

    // extract the header
    std::string header;
    std::getline(iss, header, ' ');

    // get the body of the request
    std::ostringstream oss;
    oss << iss.rdbuf();
    std::string body = oss.str();

    // handle the request in another function, see #handleRequest
    response = handleRequest(header, body, *my_controller);

    // return false would close the connecytion with the client
    return true; });

  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0)
  {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

#endif
  return 0;
}

std::string handleRequest(std::string header, std::string body, Controller my_controller)
{ 
  std::cout << "Handeling request - header: " << header << "; body: " << body << std::endl ;
  if (header == "FetchMultimedia")
  {
    std::ostringstream oss;
    my_controller.printMultimedia(body,oss, ';');
    std::string response_body = oss.str();
    if (response_body == "MultimediaNotFound") {
      return "MultimediaNotFound";
    }
    return "MultimediaInfo" + response_body;
  }
  if (header == "FetchGroup")
  {
    std::ostringstream oss;
    my_controller.printGroup(body,oss, ';');
    std::string response_body = oss.str();
    if (response_body == "GroupNotFound") {
      return "GroupNotFound";
    }
    return "GroupInfo" + response_body;
  }
  if (header == "PlayMultimedia")
  {
    int status = my_controller.playMultimedia(body);
    if (status == 0) return "PlayMultimediaSuccess";
    else return "MultimediaNotFound";
  }
  return "WrongRequest";
}
