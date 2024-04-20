package view;
import javax.swing.*;

import model.Client;

import view.components.ButtonFrame;
import view.components.HomePanel;
import view.components.TextAreaCustom;
import view.components.ToolBar;
import view.components.BarMenu;

import java.awt.*;

public class MainFrame extends JFrame {
    private TextAreaCustom textArea;

    public MainFrame(Client client) {
        super("Main Frame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        setJMenuBar(new BarMenu());

        TextAreaCustom textArea = new TextAreaCustom();
        this.textArea = textArea;

        HomePanel homePanel = new HomePanel(client);
        add(homePanel, BorderLayout.CENTER);

        ToolBar toolBar = new ToolBar(this);
        add(toolBar, BorderLayout.NORTH);
        
        ButtonFrame buttonFrame = new ButtonFrame(this, client);
        add(buttonFrame, BorderLayout.SOUTH);
        
        pack();
        setVisible(true);
        setSize(400, 400);
    }

    public JTextArea getTextArea() {
        return textArea.getTextArea();
    }
}