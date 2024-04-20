package view.components;

import java.awt.BorderLayout;

import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import model.Client;

public class GroupPanel extends JPanel {
    Client client;
    JList<String> jList = new JList<>();

    public GroupPanel(Client client) {
        super();
        this.client = client;
        setLayout(new BorderLayout());
        updateGroupList();
        jList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    String selectedValue = jList.getSelectedValue();
                    System.out.println(selectedValue);
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
