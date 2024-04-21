package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

import model.Client;
import view.MainFrame;

public class DeleteGroupAction extends AbstractAction{
    private Client client;
    private String group;
    private MainFrame mainFrame;


    public DeleteGroupAction(Client client, MainFrame mainFrame){
        super("Delete Group");
        this.client = client;
        this.mainFrame = mainFrame;
    }

    public void setGroup(String group){
        this.group = group;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        client.deleteGroup(group);
        mainFrame.selectHome();
    }
}
