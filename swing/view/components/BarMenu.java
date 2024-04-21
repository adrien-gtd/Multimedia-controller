package view.components;

import view.components.menuComponents.FileMenu;

import javax.swing.JMenuBar;

import model.Client;

public class BarMenu extends JMenuBar {
    public BarMenu(Client client){
        super();
        add(new FileMenu(client));
    }
}
