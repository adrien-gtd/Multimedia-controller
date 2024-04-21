package view.pages.createMultimedia;

import javax.swing.*;

import model.Client;
import view.MainFrame;

import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class CreateMultimediaModal extends JDialog {
    private JPanel cards;

    public CreateMultimediaModal(Client client, MainFrame mainFrame) {
        super();
        setTitle("Create Multimedia");
        setSize(600, 600);
        setMinimumSize(new Dimension(600, 600));
        setLocationRelativeTo(null);
        setModal(true);

        // Create a dropdown menu
        String[] multimediaTypes = {"Image", "Video", "Film", "Select a type..."};
        JComboBox<String> multimediaTypeDropdown = new JComboBox<>(multimediaTypes);
        multimediaTypeDropdown.setSelectedIndex(3);
        multimediaTypeDropdown.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent evt) {
                CardLayout cl = (CardLayout)(cards.getLayout());
                cl.show(cards, (String)evt.getItem());
            }
        });

        // Create the "cards"
        cards = new JPanel(new CardLayout());
        cards.add(new JPanel(),  "Select a type...");
        cards.add(new CreateVideoPanel(client, this, mainFrame), "Video");
        cards.add(new CreateImagePanel(client, this, mainFrame), "Image");
        cards.add(new CreateFilmPanel(client, this, mainFrame), "Film");

        // Add the label, dropdown menu, and cards to the JDialog
        add(cards, BorderLayout.CENTER);
        add(multimediaTypeDropdown, BorderLayout.NORTH);

        setVisible(true);
    }
}