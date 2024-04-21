package view.components.buttons;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Dimension;

import javax.swing.JButton;

import view.pages.groups.GroupPanel;
import view.pages.groups.GroupPanel.ActionsTypes;

public class ToggleDeleteMultimediaButton extends JButton{
    private ActionsTypes currentAction = ActionsTypes.SHOW_MULTIMEDIA;

    public ToggleDeleteMultimediaButton(GroupPanel groupPanel){
        super("Show Multimedia");
        setPreferredSize(new Dimension(150, 30));
        addActionListener(new ActionListener () {
            @Override
            public void actionPerformed(ActionEvent e){
                toggleDeleteMultimedia();
            }
        });
    }

    public void toggleDeleteMultimedia() {
        if (currentAction == ActionsTypes.REMOVE_MULTIMEDIA) {
            currentAction = ActionsTypes.SHOW_MULTIMEDIA;
            setText("Show Multimedia");
        }
        else {
            currentAction = ActionsTypes.REMOVE_MULTIMEDIA;
            setText("Remove Multimedia");
        }
    }

    public ActionsTypes getCurrentAction() {
        return currentAction;
    }
}
