package view.components.buttons;

import javax.swing.JButton;

import model.Client;
import view.MainFrame;
import view.pages.createMultimedia.CreateMultimediaModal;

public class CreateMultimediaButton extends JButton {

    public CreateMultimediaButton(Client client, MainFrame mainFrame) {
        super("Create Multimedia");
        addActionListener(actionListener -> new CreateMultimediaModal(client, mainFrame));
    }
}
