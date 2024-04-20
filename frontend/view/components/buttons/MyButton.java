package view.components.buttons;

import javax.swing.JButton;
import javax.swing.JTextArea;

import model.Client;
import view.MainFrame;
import view.components.actions.WriteTextAction;

public class MyButton extends JButton {
    private JTextArea textArea;


    public MyButton(String name, MainFrame mainFrame, Client client) {
        super(name);
        this.textArea = mainFrame.getTextArea();
        addActionListener(new WriteTextAction(textArea, name, client));
    }
}
