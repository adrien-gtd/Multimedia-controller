package view.components;

import javax.swing.JScrollPane;
import javax.swing.JTextArea;


public class TextAreaCustom extends JScrollPane {

    private JTextArea textArea;

    public TextAreaCustom() {
        super();
        textArea = new JTextArea();
        textArea.setEditable(false);
        setViewportView(textArea);
    }

    public JTextArea getTextArea() {
        return textArea;
    }
}
