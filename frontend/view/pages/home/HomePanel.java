package view.pages.home;


import java.awt.GridLayout;

import javax.swing.JPanel;

import model.Client;
import view.MainFrame;
import view.pages.groups.GroupListPanel;
import view.pages.multimedias.MultimediaListPanel;

import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class HomePanel extends JPanel {
    MultimediaListPanel multimediaPanel;
    GroupListPanel groupPanel;


    public HomePanel(Client client, MainFrame mainFrame) {
        super();
        setLayout(new GridLayout(1, 2));

        this.multimediaPanel = new MultimediaListPanel(client, mainFrame);
        add(multimediaPanel);

        this.groupPanel = new GroupListPanel(client, mainFrame, multimediaPanel);
        add(groupPanel);

        addComponentListener(new ComponentAdapter() {
            public void componentShown(ComponentEvent e) {
                groupPanel.updateGroupList();
                multimediaPanel.updateMultimediaList(null);
            }
        });
    }
}
