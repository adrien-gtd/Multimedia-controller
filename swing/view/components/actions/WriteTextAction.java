package view.components.actions;

import java.awt.event.ActionEvent;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.JTextArea;

import model.Client;

public class WriteTextAction extends AbstractAction {
    private JTextArea textArea;
    private String name;
    private Client client;

    public WriteTextAction(JTextArea textArea, String name, Client client) {
        super("Write Text");
        this.client = client;
        this.textArea = textArea;
        this.name = name;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println(name + " clicked!");
        List<String> multimediaList = client.fetchMultimediaList();
        for (String answer : multimediaList)
            textArea.append(answer + "\n");
    }
    
}
