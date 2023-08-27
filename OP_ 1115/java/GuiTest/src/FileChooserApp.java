import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class FileChooserApp extends JFrame {
    private JButton chooseButton;
    private JLabel pathLabel;

    public FileChooserApp() {
        // Set up the JFrame
        setTitle("File Chooser App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 150);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        // Create components
        chooseButton = new JButton("Choose File");
        pathLabel = new JLabel("Selected File: ");

        // Add components to the frame
        add(chooseButton, BorderLayout.NORTH);
        add(pathLabel, BorderLayout.CENTER);

        // Add action listener to the button
        chooseButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showFileChooser();
            }
        });
    }

    private void showFileChooser() {
        JFileChooser fileChooser = new JFileChooser();

        int result = fileChooser.showOpenDialog(this);

        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            pathLabel.setText("Selected File: " + selectedFile.getAbsolutePath());
        } else {
            pathLabel.setText("Selected File: No file selected");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new FileChooserApp().setVisible(true);
            }
        });
    }
}
