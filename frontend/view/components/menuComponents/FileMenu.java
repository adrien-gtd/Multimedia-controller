package view.components.menuComponents;

import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

import model.Client;
import view.components.actions.ExitAction;

public class FileMenu extends JMenu{

    public FileMenu(Client client){
        super("File");
        JMenuItem exit = new JMenuItem("Exit");
        exit.addActionListener(new ExitAction());
        add(exit);

        JMenuItem laod = new JMenuItem("Load");
        laod.addActionListener(e -> {
            String path = JOptionPane.showInputDialog("Enter a path to load the controller state from:");
            if (path.matches("^[a-zA-Z0-9_/\\\\.]*$") && path != null && !path.isEmpty()) {
                String answer = client.loadState(path);
                if (answer != "SaveControllerStateSuccess")
                    JOptionPane.showMessageDialog(null, answer, "Error", JOptionPane.ERROR_MESSAGE);
            }
            else
                JOptionPane.showMessageDialog(null, "Incorrect path", "Error", JOptionPane.ERROR_MESSAGE);
        });
        add(laod);

        JMenuItem save = new JMenuItem("Save");
        save.addActionListener(e -> {
            String path = JOptionPane.showInputDialog("Enter a path to save the controller state:");
            if (path.matches("^[a-zA-Z0-9_/\\\\.]*$") && path != null && !path.isEmpty()) {
                String answer = client.saveState(path);
                if (answer != "SaveControllerStateSuccess")
                    JOptionPane.showMessageDialog(null, answer, "Error", JOptionPane.ERROR_MESSAGE);
            }
            else
                JOptionPane.showMessageDialog(null, "Incorrect path", "Error", JOptionPane.ERROR_MESSAGE);
        });
        add(save);

    }
}
