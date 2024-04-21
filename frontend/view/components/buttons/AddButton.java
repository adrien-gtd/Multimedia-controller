package view.components.buttons;

import javax.swing.JButton;
import javax.swing.JDialog;

import view.components.actions.AddAction;
import view.pages.groups.AddMultimediaPanel;

public class AddButton extends JButton{
    public AddButton(JDialog dialog, AddMultimediaPanel panel){
        super("Add");
        addActionListener(new AddAction(dialog, panel));
    }
}
