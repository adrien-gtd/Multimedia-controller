package view.components;
import javax.swing.JButton;
import javax.swing.JPanel;

import model.Client;

import java.awt.FlowLayout;
import java.util.List;

import view.MainFrame;

public class ButtonFrame extends JPanel{

    public ButtonFrame(MainFrame mainFrame, Client client, List<JButton> buttons){
        setLayout(new FlowLayout());
        for(JButton button : buttons){
            add(button);
        }
        setVisible(true);
    }
    
}
