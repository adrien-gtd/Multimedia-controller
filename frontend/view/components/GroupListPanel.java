package view.components;

import java.awt.BorderLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.List;

import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import model.Client;
import view.MainFrame;
import view.components.buttons.DeleteGroupButton;

public class GroupListPanel extends JPanel {
    Client client;
    JList<String> jList = new JList<>();

    public GroupListPanel(Client client, MainFrame mainFrame, MultimediaListPanel multimediaListPanel) {
        super();
        this.client = client;
        setLayout(new BorderLayout());
        updateGroupList();
        DeleteGroupButton deleteGroupButton = new DeleteGroupButton(client, this);
        add(deleteGroupButton, BorderLayout.SOUTH);
        deleteGroupButton.setVisible(false);
        jList.addMouseListener(new MouseAdapter() {
            private String lastSelectedValue = null;
            List<String> groupMembers;
            @Override
            public void mouseClicked(MouseEvent e) {
                String selectedValue = jList.getSelectedValue();
                if (selectedValue != null && selectedValue.equals(lastSelectedValue)) {
                    lastSelectedValue = null;
                    deleteGroupButton.setVisible(false);
                    jList.clearSelection();
                    multimediaListPanel.updateMultimediaList(null);
                    
                } else {
                    lastSelectedValue = selectedValue;
                    deleteGroupButton.setVisible(true);
                    groupMembers = client.fetchGroup(selectedValue);
                    multimediaListPanel.updateMultimediaList(groupMembers);
                    deleteGroupButton.setGroup(selectedValue);
                }


            }
        });

        JScrollPane scrollPane = new JScrollPane(jList);
        add(scrollPane, BorderLayout.CENTER);
    }

    public void updateGroupList() {
        DefaultListModel<String> listModel = new DefaultListModel<>();
        for (String item : client.fetchGroupList()) {
            listModel.addElement(item);
        }
        jList.setModel(listModel);
    }


}
