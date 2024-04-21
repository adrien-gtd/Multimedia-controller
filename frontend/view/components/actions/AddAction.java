package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JDialog;

import view.pages.groups.AddMultimediaPanel;

public class AddAction extends AbstractAction{
    private JDialog dialog;
    private AddMultimediaPanel panel;

    public AddAction(JDialog dialog, AddMultimediaPanel panel){
        super("Add");
        this.dialog = dialog;
        this.panel = panel;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        panel.updateList();
        dialog.setVisible(true);
    }
}
