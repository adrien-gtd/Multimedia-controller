package view.pages.groups;

import java.awt.BorderLayout;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import model.Client;


public class AddMultimediaPanel extends JPanel {
    private GroupPanel groupPanel;
    private JList<String> jList = new JList<>();
    private Client client;

    public AddMultimediaPanel(GroupPanel groupPanel, Client client) {
        super();
        this.groupPanel = groupPanel;
        this.client = client;
        this.setLayout(new BorderLayout());
        jList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    String selectedValue = jList.getSelectedValue();
                    if(selectedValue != null) {
                        ((DefaultListModel<String>) jList.getModel()).removeElement(selectedValue);
                        client.addMultimediaToGroup(selectedValue, groupPanel.getGroup());
                    }
                }
            }
        });
        JScrollPane scrollPane = new JScrollPane(jList);
        add(scrollPane, BorderLayout.CENTER);
    }

    public void updateList () {
        DefaultListModel<String> listModel = new DefaultListModel<>();
        List<String> allMultimedias = client.fetchMultimediaList();
        JList<String> groupMultimedias = groupPanel.getJList();

        // Convert the elements in groupMultimedias to a set for faster lookup
        Set<String> groupMultimediasSet = new HashSet<>();
        for (int i = 0; i < groupMultimedias.getModel().getSize(); i++) {
            groupMultimediasSet.add(groupMultimedias.getModel().getElementAt(i));
        }

        // Add elements from allMultimedias to listModel if they are not in groupMultimedias
        for (String multimedia : allMultimedias) {
            if (!groupMultimediasSet.contains(multimedia)) {
                listModel.addElement(multimedia);
            }
        }
        jList.setModel(listModel);
    }
}
