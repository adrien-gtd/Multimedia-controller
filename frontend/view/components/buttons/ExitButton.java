package view.components.buttons;

import javax.swing.JButton;

import view.components.actions.ExitAction;

public class ExitButton extends JButton {

    public ExitButton() {
        super("Exit");
        addActionListener(new ExitAction());
    }
}
