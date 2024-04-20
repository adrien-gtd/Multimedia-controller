package view.components;


import java.awt.GridLayout;

import javax.swing.JPanel;

import model.Client;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class HomePanel extends JPanel {
    MultimediaPanel multimediaPanel;
    GroupPanel groupPanel;


    public HomePanel(Client client) {
        super();
        setLayout(new GridLayout(1, 2));

        this.multimediaPanel = new MultimediaPanel(client);
        add(multimediaPanel);

        this.groupPanel = new GroupPanel(client);
        add(groupPanel);

        addComponentListener(new ComponentAdapter() {
            public void componentShown(ComponentEvent e) {
                groupPanel.updateGroupList();
                multimediaPanel.updateMultimediaList();
            }
        });
    }
}
