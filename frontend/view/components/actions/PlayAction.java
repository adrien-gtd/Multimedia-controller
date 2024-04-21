package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

import model.Client;

public class PlayAction extends AbstractAction {
    private Client client;
    private String multimediaName;

    public PlayAction(Client client, String multimediaName){
        super("Play");
        this.client = client;
        this.multimediaName = multimediaName;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        client.playMultimedia(multimediaName);
    }
}
