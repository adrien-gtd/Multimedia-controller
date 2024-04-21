package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JDialog;

import view.pages.groups.GroupPanel;

public class AddValidateAction extends AbstractAction {
    private GroupPanel groupPanel;
    private JDialog dialog;

    public AddValidateAction(GroupPanel groupPanel, JDialog dialog){
        super("Validate");
        this.groupPanel = groupPanel;
        this.dialog = dialog;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        groupPanel.updateMultimediaList();
        dialog.setVisible(false);
    }
}
