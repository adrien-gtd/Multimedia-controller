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
      System.out.println("\n--- Sending Request ---");
      System.out.println(request);
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
      String answer = input.readLine().replaceAll(";", "\n");
      System.out.println("\n--- Received Response ---");
      System.out.println(answer);
      return answer;
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


  public String fetchMultimedia(String multimedia) {
    return removeFirstWord(send("FetchMultimedia " + multimedia));
  }

  public List<String> fetchGroup(String multimedia) {
    String answer = send("FetchGroup " + multimedia);
    List<String> list = new ArrayList<>(Arrays.asList(answer.split("\n")));
    list.remove(0);
    return list;
  }

  public void playMultimedia(String multimedia) {
    send("PlayMultimedia " + multimedia);
  }

  public void deleteMultimedia(String multimedia) {
    send("RemoveMultimedia " + multimedia);
  }

  public void deleteGroup(String group) {
    send("RemoveGroup " + group);
  }

  private String removeFirstWord(String str) {
    if (str == null || str.isEmpty()) {
        return "";
    }

    int index = str.indexOf(" ");
    if (index == -1) { // Single word
        return "";
    }

    return str.substring(index + 1);
}

}


