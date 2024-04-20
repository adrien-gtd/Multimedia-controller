package view.components;

import javax.swing.JToolBar;
import view.components.buttons.ExitButton;

import view.MainFrame;

public class ToolBar extends JToolBar {

    public ToolBar(MainFrame mainFrame){
        super();
        add(new ExitButton());
    }
}
