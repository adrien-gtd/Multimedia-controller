package view;
import javax.swing.*;

import model.Client;
import view.components.BarMenu;
import view.components.GroupPanel;
import view.components.HomePanel;
import view.components.MultimediaPanel;
import view.components.ToolBar;

import java.awt.*;

public class MainFrame extends JFrame {
    private HomePanel homePanel;
    private MultimediaPanel multimediaPanel;
    private GroupPanel groupPanel;
    private CardLayout cardLayout;
    private JPanel cards;

    public MainFrame(Client client) {
        super("Main Frame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setJMenuBar(new BarMenu());

        // Create card layout
        cardLayout = new CardLayout();
        cards = new JPanel(cardLayout);

        // Create the panels
        homePanel =  new HomePanel(client, this);
        cards.add(homePanel, "Home");

        multimediaPanel = new MultimediaPanel(client, this);
        cards.add(multimediaPanel, "Multimedia");

        this.groupPanel = new GroupPanel(client, this);
        cards.add(groupPanel, "Group");


        // Add the toolbar
        ToolBar toolBar = new ToolBar(this);
        add(toolBar, BorderLayout.NORTH);
        
        // Add the cards to the panel
        add(cards, BorderLayout.CENTER);

        // Show the frame
        cardLayout.show(cards, "Home");
        setSize(400, 400);
        setVisible(true);
    }

    public void selectMultimedia(String multimedia) {
        multimediaPanel.updateMultimedia(multimedia);
        cardLayout.show(cards, "Multimedia");
    }

    public void selectGroup(String group) {
        groupPanel.updateGroup(group);
        cardLayout.show(cards, "Group");
    }

    public void selectHome() {
        cardLayout.show(cards, "Home");
    }
}