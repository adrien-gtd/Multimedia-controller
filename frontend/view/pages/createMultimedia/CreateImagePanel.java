package view.pages.createMultimedia;

import java.awt.BorderLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import model.Client;
import view.MainFrame;

public class CreateImagePanel extends JPanel {
    private JTextField pathField;
    private JTextField nameField;
    private JTextField widthField;
    private JTextField heightField;
    private CreateMultimediaModal dialog;
    
    public CreateImagePanel(Client client, CreateMultimediaModal dialog, MainFrame mainFrame){
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
        panel.add(new JLabel("Width:"), gbc);
    
        widthField = new JTextField(10);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        panel.add(widthField, gbc);

        gbc.anchor = GridBagConstraints.EAST;
        gbc.gridx = 0;
        gbc.gridy = 3;
        panel.add(new JLabel("Height:"), gbc);
    
        heightField = new JTextField(10);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.gridx = 1;
        panel.add(heightField, gbc);

        add(panel, BorderLayout.CENTER);

        JButton button = new JButton("Done");
        button.addActionListener(e -> {
            String name = nameField.getText();
            String path = pathField.getText();
            String width = widthField.getText();
            String height = heightField.getText();
            try {
                System.out.println(Float.parseFloat(width));
                System.out.println(Float.parseFloat(height));
           
                if (name != null && !name.isEmpty() && path != null && !path.isEmpty() && width != null && !width.isEmpty() && height != null && !height.isEmpty() && Float.parseFloat(height) > 0 && Float.parseFloat(width) > 0 && name.matches("^[a-zA-Z0-9 ]*$") && path.matches("^[a-zA-Z0-9_/\\\\.]*$")) {
                    client.createImage(name, path, width, height);
                    mainFrame.selectMultimedia(name);
                    dialog.dispose();
                } else {
                    resetFields();
                }
            } catch (NumberFormatException ex) {
                resetFields();
            }
        });
        add(button, BorderLayout.SOUTH);
    }

    private void resetFields() {
        JOptionPane.showMessageDialog(dialog, "Please fill correctly all the fields", "Error", JOptionPane.ERROR_MESSAGE);
        nameField.setText("");
        pathField.setText("");
        widthField.setText("");
        heightField.setText("");
    }
}
