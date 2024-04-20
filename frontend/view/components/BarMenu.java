package view.components;

import view.components.menuComponents.FileMenu;

import javax.swing.JMenuBar;

public class BarMenu extends JMenuBar {
    public BarMenu(){
        super();
        add(new FileMenu());
    }
}
