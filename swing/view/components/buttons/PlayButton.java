package view.components.buttons;

import javax.swing.JButton;

import model.Client;
import view.components.actions.PlayAction;

public class PlayButton extends JButton{
    private Client client;
    private PlayAction playAction;

    public PlayButton(Client client){
        super("Play");
        this.client = client;
        playAction = new PlayAction(client, null);
        addActionListener(playAction);
    }

    public void setMultimedia(String multimediaName){
        removeActionListener(playAction);
        playAction = new PlayAction(client, multimediaName);
        addActionListener(playAction);
    }
}
