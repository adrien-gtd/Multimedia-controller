package view.components;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import model.Client;
import view.MainFrame;

public class CreateGroupModal extends JDialog {
    private JTextField groupNameField;
    
    public CreateGroupModal(Client client, MainFrame mainFrame) {
        super();
        setTitle("Create Group");
        setSize(300, 200);
        setLocationRelativeTo(null);
        setModal(true);
        setResizable(false);

        // Create a panel with a GridLayout
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        // Create a label and add it to the panel
        JLabel label = new JLabel("Create a new group");
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.CENTER;
        panel.add(label, gbc);

        // Create an input field and add it to the panel
        JLabel nameLabel = new JLabel("Group name:");
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.EAST;
        panel.add(nameLabel, gbc);

        groupNameField = new JTextField(10);
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.anchor = GridBagConstraints.WEST;
        panel.add(groupNameField, gbc);

        JButton button = new JButton("Done");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String group = groupNameField.getText();
                if (group != null && !group.isEmpty() && group.matches("^[a-zA-Z0-9_ ]+$")) {
                    client.createGroup(group);
                    mainFrame.selectGroup(group);
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(CreateGroupModal.this, "Please fill correctly the field", "Error", JOptionPane.ERROR_MESSAGE);
                    groupNameField.setText("");
                    groupNameField.requestFocus();
                }
            }
        });
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.CENTER;
        panel.add(button, gbc);

        // Add the panel to the JDialog
        add(panel);
        
        setVisible(true);
    }
}
