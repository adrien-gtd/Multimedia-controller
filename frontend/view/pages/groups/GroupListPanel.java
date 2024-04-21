package view.pages.groups;

import java.awt.BorderLayout;


import javax.swing.DefaultListModel;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import model.Client;
import view.MainFrame;
import view.pages.multimedias.MultimediaListPanel;

public class GroupListPanel extends JPanel {
    Client client;
    JList<String> jList = new JList<>();

    public GroupListPanel(Client client, MainFrame mainFrame, MultimediaListPanel multimediaListPanel) {
        super();
        this.client = client;
        setLayout(new BorderLayout());
        updateGroupList();
        jList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    String selectedValue = jList.getSelectedValue();
                    if(selectedValue != null)
                        mainFrame.selectGroup(selectedValue);
                }
            }
        });

        JScrollPane scrollPane = new JScrollPane(jList);
        add(scrollPane, BorderLayout.CENTER);
        add(new JLabel("Group list:"), BorderLayout.NORTH);
    }

    public void updateGroupList() {
        DefaultListModel<String> listModel = new DefaultListModel<>();
        for (String item : client.fetchGroupList()) {
            listModel.addElement(item);
        }
        jList.setModel(listModel);
    }


}
