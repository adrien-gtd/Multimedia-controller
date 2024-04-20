import model.Client;
import view.MainFrame;

public class Main {
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;

    private static Client client;
    public static void main(String[] args) {
      String host = DEFAULT_HOST;
      int port = DEFAULT_PORT;

      System.setProperty("sun.awt.exception.handler", AwtExceptionHandler.class.getName());
      
      try {
          client = new Client(host, port);
          System.out.println("Client connected to "+host+":"+port);
        }
        catch (Exception e) {
          System.err.println("Client: Couldn't connect to "+host+":"+port);
          System.exit(1);
        }
        new MainFrame(client);
    }

    public static class AwtExceptionHandler {
      public void handle(Throwable t) {
          t.printStackTrace();
      }
    }
}
