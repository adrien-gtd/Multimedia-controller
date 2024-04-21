package view.components;
import javax.swing.JButton;
import javax.swing.JPanel;


import java.awt.FlowLayout;
import java.util.List;


public class ButtonFrame extends JPanel{

    public ButtonFrame(List<JButton> buttons){
        setLayout(new FlowLayout());
        for(JButton button : buttons){
            add(button);
        }
        setVisible(true);
    }
    
}
