import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;

public class FileEditorHelper {

    private JFrame frame;
    private JTextArea textArea;
    private JButton openButton, saveButton, exitButton;
    private File currentFile;

    public FileEditorHelper() {
        frame = new JFrame("Text Editor");
        frame.setLayout(new BorderLayout());

        textArea = new JTextArea();
        textArea.setEditable(false);
        frame.add(textArea, BorderLayout.CENTER);

        openButton = new JButton("Open");
        openButton.addActionListener(new OpenButtonListener());
        frame.add(openButton, BorderLayout.WEST);

        saveButton = new JButton("Save");
        saveButton.addActionListener(new SaveButtonListener());
        frame.add(saveButton, BorderLayout.EAST);

        exitButton = new JButton("Exit");
        exitButton.addActionListener(new ExitButtonListener());
        frame.add(exitButton, BorderLayout.SOUTH);

        frame.setSize(500, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    private class OpenButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JFileChooser fileChooser = new JFileChooser();
            int returnValue = fileChooser.showOpenDialog(frame);

            if (returnValue == JFileChooser.APPROVE_OPTION) {
                currentFile = fileChooser.getSelectedFile();
                // String text = readFile(currentFile);
                // textArea.setText(text);
            }
        }
    }

    private class SaveButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if (currentFile == null) {
                JFileChooser fileChooser = new JFileChooser();
                int returnValue = fileChooser.showSaveDialog(frame);

                if (returnValue == JFileChooser.APPROVE_OPTION) {
                    currentFile = fileChooser.getSelectedFile();
                    // saveFile(currentFile, textArea.getText());
                }
            } else {
                // saveFile(currentFile, textArea.getText());
            }
        }
    }

    private class ExitButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    private String readFile(File file) throws IOException {
        String text = "";
        BufferedReader reader = new BufferedReader(new FileReader(file));

        String line;
        while ((line = reader.readLine()) != null) {
            text += line + "\n";
        }

        reader.close();
        return text;
    }

    private void saveFile(File file, String text) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(file));
        writer.write(text);
        writer.close();
    }

    public static void main(String[] args) {
        new FileEditorHelper();
    }
}
