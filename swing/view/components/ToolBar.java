package view.components;

import javax.swing.JToolBar;

import model.Client;
import view.MainFrame;
import view.components.buttons.CreateGroupButton;
import view.components.buttons.CreateMultimediaButton;
import view.components.buttons.ExitButton;
import view.components.buttons.HomeButton;

public class ToolBar extends JToolBar {

    public ToolBar(MainFrame mainFrame, Client client){
        super();
        add(new ExitButton());
        add(new HomeButton(mainFrame));
        add(new CreateGroupButton(client, mainFrame));
        add(new CreateMultimediaButton(client, mainFrame));
    }
}
