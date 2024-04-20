package model;
//
// Client Java pour communiquer avec le Serveur C++ 
// eric lecolinet - telecom paristech - 2015
//

import java.util.List;
import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Client
{
  private Socket sock;
  private BufferedReader input;
  private BufferedWriter output;


  public static void  printFormated (String str) {
    System.out.println(str.replaceAll(";", "\n"));
  }

  ///
  /// Initialise la connexion.
  /// Renvoie une exception en cas d'erreur.
  ///
  public Client(String host, int port) throws UnknownHostException, IOException {
    try {
      sock = new java.net.Socket(host, port);
    }
    catch (java.net.UnknownHostException e) {
      System.err.println("Client: Couldn't find host "+host+":"+port);
      throw e;
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't reach host "+host+":"+port);
      throw e;
    }
    
    try {
      input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't open input or output streams");
      throw e;
    }
  }
  
  
  ///
  /// Envoie une requete au server et retourne sa reponse.
  /// Noter que la methode bloque si le serveur ne repond pas.
  ///
  public String send(String request) {
    // Envoyer la requete au serveur
    try {
      request += "\n";  // ajouter le separateur de lignes
      output.write(request, 0, request.length());
      output.flush();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't send message: " + e);
      return null;
    }
    
    // Recuperer le resultat envoye par le serveur
    try {
      return input.readLine().replaceAll(";", "\n");
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't receive message: " + e);
      return null;
    }
  }

  ///
  /// Implementation des requetes du client
  ///

  public List<String> fetchMultimediaList() {
    String answer = send("FetchMultimediaList");
    List<String> list = new ArrayList<>(Arrays.asList(answer.replaceAll("\t", "").split("\n")));
    list.remove(0);
    return list;
  }

  public List<String> fetchGroupList() {
    String answer = send("FetchGroupList");
    List<String> list = new ArrayList<>(Arrays.asList(answer.replaceAll("\t", "").split("\n")));
    list.remove(0);
    return list;
  }


}


