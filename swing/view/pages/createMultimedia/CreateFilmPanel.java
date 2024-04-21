package view.pages.createMultimedia;

import java.awt.BorderLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;

import model.Client;
import view.MainFrame;

public class CreateFilmPanel extends JPanel {
    private JTextField filmDurationField;
    private JTextField filmChapterNumberField;
    private JTextField pathField;
    private JTextField nameField;
    private DefaultListModel<String> chapterDurationsModel;
    private CreateMultimediaModal dialog;
    

    public CreateFilmPanel(Client client, CreateMultimediaModal dialog, MainFrame mainFrame) {
        this.dialog = dialog;
        setLayout(new BorderLayout());
        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(0, 0, 0, 10);
        gbc.anchor = GridBagConstraints.EAST;
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(new JLabel("Name:"), gbc);
    
        nameField  = new JTextField(10);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        panel.add(nameField, gbc);

        gbc.anchor = GridBagConstraints.EAST;
        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(new JLabel("Path:"), gbc);
    
        pathField = new JTextField(10);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        panel.add(pathField, gbc);
        
        gbc.anchor = GridBagConstraints.EAST;
        gbc.gridx = 0;
        gbc.gridy = 2;
        panel.add(new JLabel("Duration:"), gbc);
    
        filmDurationField = new JTextField(10);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        panel.add(filmDurationField, gbc);
        
        gbc.anchor = GridBagConstraints.EAST;
        gbc.gridx = 0;
        gbc.gridy = 3;
        panel.add(new JLabel("Number of Chapters:"), gbc);
    
        filmChapterNumberField = new JTextField(10);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        panel.add(filmChapterNumberField, gbc);
        
        gbc.anchor = GridBagConstraints.EAST;
        gbc.gridx = 0;
        gbc.gridy = 4;
        panel.add(new JLabel("Chapter Durations:"), gbc);
    
        chapterDurationsModel = new DefaultListModel<>();
        JList<String> chapterDurationsList = new JList<>(chapterDurationsModel);
        gbc.gridx = 1;
        panel.add(new JScrollPane(chapterDurationsList), gbc);
    
        JButton addChapterButton = new JButton("Add Chapter");
        addChapterButton.addActionListener(e -> {
            String duration = JOptionPane.showInputDialog("Enter chapter duration:");
            if (duration != null) {
                chapterDurationsModel.addElement(duration);
            }
        });

        JButton resetChapterButton = new JButton("Reset Chapters");
        resetChapterButton.addActionListener(e -> {
            chapterDurationsModel.clear();
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(addChapterButton);
        buttonPanel.add(resetChapterButton);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        gbc.gridy = 5;
        panel.add(buttonPanel, gbc);

        add(panel, BorderLayout.CENTER);

        JButton button = new JButton("Done");
        button.addActionListener(e -> {
            String name = nameField.getText();
            String path = pathField.getText();
            String duration = filmDurationField.getText();
            String chapterNumber = filmChapterNumberField.getText();
            String[] chapterDurations = new String[chapterDurationsModel.size()];
            for (int i = 0; i < chapterDurationsModel.size(); i++) {
                chapterDurations[i] = chapterDurationsModel.get(i);
            }
            try {
                Integer.parseInt(duration);
                Integer.parseInt(chapterNumber);
                for (String chapterDuration : chapterDurations) {
                    Integer.parseInt(chapterDuration);
                }

                // Check if the fields are not empty and if the name and path are valid
                if (name != null && 
                            !name.isEmpty() && 
                            path != null && 
                            !path.isEmpty() && 
                            duration != null && 
                            !duration.isEmpty() && 
                            chapterNumber != null && 
                            !chapterNumber.isEmpty() && 
                            chapterDurations.length > 0 &&
                            chapterDurations.length == Integer.parseInt(chapterNumber) &&
                            Integer.parseInt(duration) > 0 &&
                            name.matches("^[a-zA-Z0-9 ]*$") && 
                            path.matches("^[a-zA-Z0-9_/\\\\.]*$")) {
                    client.createFilm(name, path, duration, chapterNumber, chapterDurations);
                    mainFrame.selectMultimedia(name);
                    dialog.dispose();
                } else {
                    resetFields();
                }
            } catch (Exception ex) {
                System.out.println(ex);
                resetFields();
            }
        });
        add(button, BorderLayout.SOUTH);
    }

    private void resetFields() {
        JOptionPane.showMessageDialog(dialog, "Please fill correctly all the fields", "Error", JOptionPane.ERROR_MESSAGE);
        nameField.setText("");
        pathField.setText("");
        filmDurationField.setText("");
        filmChapterNumberField.setText("");
        chapterDurationsModel.clear();
    }
}
