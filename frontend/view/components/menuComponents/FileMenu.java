package view.components.menuComponents;

import javax.swing.JMenu;
import javax.swing.JMenuItem;

import view.components.actions.ExitAction;

public class FileMenu extends JMenu{
    private JMenuItem exit;

    public FileMenu(){
        super("File");
        this.exit = new JMenuItem("Exit");
        exit.addActionListener(new ExitAction());
        add(exit);
    }
}
