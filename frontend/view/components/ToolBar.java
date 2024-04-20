package view.components;

import javax.swing.JToolBar;

import view.MainFrame;
import view.components.buttons.ExitButton;

public class ToolBar extends JToolBar {

    public ToolBar(MainFrame mainFrame){
        super();
        add(new ExitButton());
    }
}
