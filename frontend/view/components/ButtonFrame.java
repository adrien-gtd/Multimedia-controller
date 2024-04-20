package view.components;
import javax.swing.JPanel;

import model.Client;

import java.awt.FlowLayout;

import view.MainFrame;
import view.components.buttons.ExitButton;
import view.components.buttons.MyButton;

public class ButtonFrame extends JPanel{

    public ButtonFrame(MainFrame mainFrame, Client client){
        setLayout(new FlowLayout());

        add(new MyButton("Button 1", mainFrame, client));
        add(new MyButton("Button 2", mainFrame, client));
        add(new ExitButton());

        setVisible(true);
    }
    
}
