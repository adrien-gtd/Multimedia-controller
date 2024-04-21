package view.pages.multimedias;

import java.awt.BorderLayout;
import java.util.List;

import javax.swing.DefaultListModel;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import model.Client;
import view.MainFrame;
import view.pages.groups.GroupPanel;

public class MultimediaListPanel extends JPanel {
    Client client;
    JList<String> jList = new JList<>();
    GroupPanel group;

    public MultimediaListPanel(Client client, MainFrame mainFrame) {
        super();
        this.client = client;
        group = null;
        setLayout(new BorderLayout());
        updateMultimediaList(null);
        jList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    String selectedValue = jList.getSelectedValue();
                    if(selectedValue != null) {
                        if (group == null) {
                            mainFrame.selectMultimedia(selectedValue);
                        }
                        else {
                            group.selectedMultimedia(selectedValue);
                        }
                    }   
                }
            }
        });

        JScrollPane scrollPane = new JScrollPane(jList);
        add(scrollPane, BorderLayout.CENTER);

        add(new JLabel("Multimedia list:"), BorderLayout.NORTH);
    }

    public void updateMultimediaList(List<String> multimediaList) {
        DefaultListModel<String> listModel = new DefaultListModel<>();
        if (multimediaList == null) {
            for (String item : client.fetchMultimediaList()) {
                listModel.addElement(item);
            }
        }
        else {
            for (String item : multimediaList) {
                listModel.addElement(item);
            }
        }
        jList.setModel(listModel);
    }

    public void setGroup(GroupPanel group) {
        this.group = group;
    }

    public JList<String> getJList() {
        return jList;
    }
}
