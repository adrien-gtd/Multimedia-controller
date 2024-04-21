package view.components.buttons;

import javax.swing.JButton;

import view.MainFrame;

public class HomeButton extends JButton {
    public HomeButton(MainFrame mainFrame) {
        super("Home");
        addActionListener(actionListener -> mainFrame.selectHome());
    }
}
