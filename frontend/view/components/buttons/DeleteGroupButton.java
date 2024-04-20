package view.components.buttons;

import javax.swing.JButton;

import view.components.GroupListPanel;
import view.components.actions.DeleteGroupAction;
import model.Client;

public class DeleteGroupButton extends JButton {
    private DeleteGroupAction deleteGroupAction;

    public DeleteGroupButton(Client client, GroupListPanel groupListPanel) {
        super("Delete Group");
        this.deleteGroupAction = new DeleteGroupAction(client, groupListPanel);
        addActionListener(deleteGroupAction);
    }

    public void setGroup(String group) {
        deleteGroupAction.setGroup(group);
    }


}
