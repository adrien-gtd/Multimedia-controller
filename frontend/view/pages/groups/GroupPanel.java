package view.pages.groups;

import java.awt.BorderLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JList;
import javax.swing.JPanel;

import model.Client;
import view.MainFrame;
import view.components.ButtonFrame;
import view.components.buttons.AddButton;
import view.components.buttons.AddValidateButton;
import view.components.buttons.DeleteGroupButton;
import view.components.buttons.ToggleDeleteMultimediaButton;
import view.pages.multimedias.MultimediaListPanel;

public class GroupPanel extends JPanel {
    private Client client;
    private MultimediaListPanel multimediaListPanel;
    private DeleteGroupButton deleteGroupButton;
    private ActionsTypes currentAction;
    private String group;
    private MainFrame mainFrame;
    private ToggleDeleteMultimediaButton toggleDeleteMultimediaButton;


    public GroupPanel(Client client, MainFrame mainFrame) {
        super();
        setLayout(new BorderLayout());
        this.client = client;
        this.mainFrame = mainFrame;
        this.multimediaListPanel = new MultimediaListPanel(client, mainFrame);

        // Create a new JDialog and the components for adding multimedia
        JDialog dialog = new JDialog();
        dialog.setLayout(new BorderLayout());
        AddMultimediaPanel addPanel = new AddMultimediaPanel(this, client);
        dialog.setModal(true);
        dialog.addWindowListener(new DialogWindowAdapter(dialog));
        dialog.add(addPanel, BorderLayout.CENTER);
        dialog.add(new AddValidateButton(this, dialog), BorderLayout.SOUTH);
        dialog.setSize(300, 200);

        // Create the list of multimedia
        multimediaListPanel.setGroup(this);
        add(multimediaListPanel, BorderLayout.CENTER);

        // Creates buttons and add them to the JPanel
        List<JButton> buttons = new ArrayList<>();

        this.deleteGroupButton = new DeleteGroupButton(client, mainFrame);
        this.toggleDeleteMultimediaButton = new ToggleDeleteMultimediaButton(this);
        
        buttons.add(new AddButton(dialog, addPanel));
        buttons.add(deleteGroupButton);
        buttons.add(toggleDeleteMultimediaButton);
        add(new ButtonFrame(buttons), BorderLayout.SOUTH);
    }
    
    public void updateGroup(String group) {
        this.group = group;
        deleteGroupButton.setGroup(group);
        updateMultimediaList();
    }

    public void updateMultimediaList() {
        List<String> multimedias = client.fetchGroup(group);
        multimediaListPanel.updateMultimediaList(multimedias);
    }

    public void selectedMultimedia(String multimedia) {
        currentAction = toggleDeleteMultimediaButton.getCurrentAction();
        if (currentAction == ActionsTypes.REMOVE_MULTIMEDIA) {
            deleteMultimediaFromGroup(multimedia);
        }
        else if (currentAction == ActionsTypes.SHOW_MULTIMEDIA) {
            mainFrame.selectMultimedia(multimedia);
        }
    }

    public void deleteMultimediaFromGroup(String multimedia) {
        client.deleteMultimediaFromGroup(multimedia, group);
        updateMultimediaList();
    }

    public String getGroup() {
        return group;
    }

    public enum ActionsTypes {
        SHOW_MULTIMEDIA,
        REMOVE_MULTIMEDIA
    }

    public JList<String> getJList() {
        return multimediaListPanel.getJList();
    }

    private class DialogWindowAdapter extends WindowAdapter {
        private JDialog dialog;
    
        public DialogWindowAdapter(JDialog dialog) {
            this.dialog = dialog;
        }
    
        @Override
        public void windowClosing(WindowEvent e) {
            updateMultimediaList();
            dialog.setVisible(false);
        }
    }
}
