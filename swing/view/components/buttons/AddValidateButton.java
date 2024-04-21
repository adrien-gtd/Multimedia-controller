package view.components.buttons;

import javax.swing.JButton;
import javax.swing.JDialog;

import view.components.actions.AddValidateAction;
import view.pages.groups.GroupPanel;

public class AddValidateButton extends JButton{

    public AddValidateButton(GroupPanel groupPanel, JDialog dialog){
        super("Validate");
        addActionListener(new AddValidateAction(groupPanel, dialog));
    }


}
