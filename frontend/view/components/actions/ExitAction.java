package view.components.actions;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

public class ExitAction extends AbstractAction{

    @Override
    public void actionPerformed(ActionEvent e) {
        System.exit(0);
    }
    
}
