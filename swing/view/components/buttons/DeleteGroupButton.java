package view.components.buttons;

import javax.swing.JButton;

import view.MainFrame;
import view.components.actions.DeleteGroupAction;
import model.Client;

public class DeleteGroupButton extends JButton {
    private DeleteGroupAction deleteGroupAction;

    public DeleteGroupButton(Client client, MainFrame mainFrame) {
        super("Delete Group");
        this.deleteGroupAction = new DeleteGroupAction(client, mainFrame);
        addActionListener(deleteGroupAction);
    }

    public void setGroup(String group) {
        deleteGroupAction.setGroup(group);
    }
}
