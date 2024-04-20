package view.components;

import java.awt.BorderLayout;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JPanel;

import model.Client;
import view.MainFrame;
import view.components.buttons.DeleteMultimediaButton;
import view.components.buttons.PlayButton;

public class MultimediaPanel extends JPanel{
    private Client client;
    private TextAreaCustom textArea;
    private PlayButton playButton;
    private DeleteMultimediaButton deleteButton;

    public MultimediaPanel(Client client, MainFrame mainFrame){
        super();
        setLayout(new BorderLayout());
        this.client = client;
        TextAreaCustom textArea = new TextAreaCustom();
        this.textArea = textArea;
        add(textArea, BorderLayout.CENTER);


        List<JButton> buttons = new ArrayList<>();
        playButton = new PlayButton(client);
        deleteButton = new DeleteMultimediaButton(client, mainFrame);

        buttons.add(playButton);
        buttons.add(deleteButton);

        ButtonFrame buttonFrame = new ButtonFrame(mainFrame, client, buttons);
        add(buttonFrame, BorderLayout.SOUTH);
    }

    public void updateMultimedia(String multimedia){
        deleteButton.setMultimedia(multimedia);
        playButton.setMultimedia(multimedia);
        String info = client.fetchMultimedia(multimedia);
        textArea.getTextArea().setText(info);
        playButton.setMultimedia(multimedia);
    }
}
