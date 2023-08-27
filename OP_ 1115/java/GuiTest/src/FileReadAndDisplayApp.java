import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileReadAndDisplayApp extends JFrame {
    private JButton readFileButton;
    private JTextArea contentTextArea;

    public FileReadAndDisplayApp() {
        // Set up the JFrame
        setTitle("File Read and Display App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        // Create components
        readFileButton = new JButton("Read File");
        contentTextArea = new JTextArea();

        // Add components to the frame
        add(readFileButton, BorderLayout.NORTH);
        add(new JScrollPane(contentTextArea), BorderLayout.CENTER);

        // Add action listener to the button
        readFileButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                readAndDisplayFileContent();
            }
        });
    }

    private void readAndDisplayFileContent() {
        JFileChooser fileChooser = new JFileChooser();

        int result = fileChooser.showOpenDialog(this);

        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();

            try {
                BufferedReader reader = new BufferedReader(new FileReader(selectedFile));
                StringBuilder content = new StringBuilder();
                String line;

                while ((line = reader.readLine()) != null) {
                    content.append(line).append("\n");
                }

                reader.close();
                contentTextArea.setText(content.toString());
            } catch (IOException ex) {
                contentTextArea.setText("Error reading the file.");
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new FileReadAndDisplayApp().setVisible(true);
            }
        });
    }
}
