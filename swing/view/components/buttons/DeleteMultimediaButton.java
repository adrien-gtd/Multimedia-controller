package view.components.buttons;

import javax.swing.JButton;

import model.Client;
import view.MainFrame;
import view.components.actions.DeleteMultimediaAction;

public class DeleteMultimediaButton extends JButton {
    private Client client;
    private MainFrame mainFrame;
    private DeleteMultimediaAction deleteMultimediaAction;

    public DeleteMultimediaButton(Client client, MainFrame mainFrame){
        super("Delete");
        this.client = client;
        this.mainFrame = mainFrame;
        deleteMultimediaAction = new DeleteMultimediaAction(client, mainFrame, null);
    }
    
    public void setMultimedia(String multimediaName){
        removeActionListener(deleteMultimediaAction);
        deleteMultimediaAction = new DeleteMultimediaAction(client, mainFrame, multimediaName);
        addActionListener(deleteMultimediaAction);
    }
}
