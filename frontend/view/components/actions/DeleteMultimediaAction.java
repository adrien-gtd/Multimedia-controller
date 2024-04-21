package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

import model.Client;
import view.MainFrame;

public class DeleteMultimediaAction extends AbstractAction {
    private Client client;
    private MainFrame mainFrame;
    private String multimediaName;

    public DeleteMultimediaAction(Client client, MainFrame mainFrame, String multimediaName){
        super("Delete");
        this.client = client;
        this.mainFrame = mainFrame;
        this.multimediaName = multimediaName;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        client.deleteMultimedia(multimediaName);
        mainFrame.selectHome();
    }
}
