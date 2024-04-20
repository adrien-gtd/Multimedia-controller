package view.components;

import java.awt.BorderLayout;

import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import model.Client;
import view.MainFrame;

public class MultimediaListPanel extends JPanel {
    Client client;
    JList<String> jList = new JList<>();

    public MultimediaListPanel(Client client, MainFrame mainFrame) {
        super();
        this.client = client;
        setLayout(new BorderLayout());
        updateMultimediaList();
        jList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    String selectedValue = jList.getSelectedValue();
                    if(selectedValue != null)
                        mainFrame.selectMultimedia(selectedValue);
                }
            }
        });

        JScrollPane scrollPane = new JScrollPane(jList);
        add(scrollPane, BorderLayout.CENTER);
    }

    public void updateMultimediaList() {
        DefaultListModel<String> listModel = new DefaultListModel<>();
        for (String item : client.fetchMultimediaList()) {
            listModel.addElement(item);
        }
        jList.setModel(listModel);
    }
}