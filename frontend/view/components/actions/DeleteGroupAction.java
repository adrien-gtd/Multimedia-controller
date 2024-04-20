package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

import model.Client;
import view.components.GroupListPanel;

public class DeleteGroupAction extends AbstractAction{
    private Client client;
    private GroupListPanel groupList;
    private String group;


    public DeleteGroupAction(Client client, GroupListPanel groupList){
        super("Delete Group");
        this.client = client;
        this.groupList = groupList;
    }

    public void setGroup(String group){
        this.group = group;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        client.deleteGroup(group);
        groupList.updateGroupList();
    }
}
