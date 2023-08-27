
import javax.swing.*;
import java.awt.*;

public class SimpleGui {

    public static void main(String[] args) {
        // Create the main JFrame
        JFrame frame = new JFrame("Simple GUI Snippet");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new BorderLayout());

        // Create components
        JLabel label = new JLabel("Enter your name:");
        JTextField textField = new JTextField();
        JButton button = new JButton("Submit");

        // Add components to the frame
        frame.add(label, BorderLayout.NORTH);
        frame.add(textField, BorderLayout.CENTER);
        frame.add(button, BorderLayout.SOUTH);

        // Add an action listener to the button
        button.addActionListener(e -> {
            String input = textField.getText();
            JOptionPane.showMessageDialog(frame, "Hello, " + input + "!");
        });

        // Set the frame to be visible
        frame.setVisible(true);
    }
}
