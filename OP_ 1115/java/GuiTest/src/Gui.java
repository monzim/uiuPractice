import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Gui extends JFrame {
    private JTextField numberField;
    private JButton multiplyButton;
    private JLabel resultLabel;

    public Gui() {
        setTitle("Java GUI");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 150);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(3, 1));

        numberField = new JTextField(10);
        multiplyButton = new JButton("Multiply");
        resultLabel = new JLabel("Result: ");

        add(numberField);
        add(multiplyButton);
        add(resultLabel);

        multiplyButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                multiply();
            }
        });
    }

    private void multiply() {
        try {
            String userInput = numberField.getText();
            double inputNumber = Double.parseDouble(userInput);

            double multiplier = 2.0;
            double result = inputNumber * multiplier;

            resultLabel.setText("Result: " + result);
        } catch (NumberFormatException ex) {
            resultLabel.setText("Result: Invalid input");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                Gui gui = new Gui();
                gui.setVisible(true);
            }
        });
    }
}
