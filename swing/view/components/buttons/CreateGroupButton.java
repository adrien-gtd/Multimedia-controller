package view.components.buttons;

import javax.swing.JButton;

import model.Client;
import view.MainFrame;
import view.components.CreateGroupModal;

public class CreateGroupButton extends JButton {
    public CreateGroupButton(Client client, MainFrame mainFrame) {
        super("Create Group");
        addActionListener(actionListener -> new CreateGroupModal(client, mainFrame));
    }
}
