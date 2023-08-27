import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.TimerTask;
import java.util.Timer;

public class FileChatApp extends JFrame {
    private JTextArea chatArea;
    private JTextField messageField;
    private JButton sendButton;

    private File senderFile;
    private File receiverFile;

    public FileChatApp(String senderName, String receiverName) {
        setTitle("File Chat - " + senderName);
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        chatArea = new JTextArea();
        chatArea.setEditable(false);

        messageField = new JTextField();
        sendButton = new JButton("Send");

        senderFile = new File(senderName + ".txt");
        receiverFile = new File(receiverName + ".txt");

        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                sendMessage();
            }
        });

        JScrollPane scrollPane = new JScrollPane(chatArea);

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new BorderLayout());
        inputPanel.add(messageField, BorderLayout.CENTER);
        inputPanel.add(sendButton, BorderLayout.EAST);

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(scrollPane, BorderLayout.CENTER);
        getContentPane().add(inputPanel, BorderLayout.SOUTH);

        // Ensure that both sender and receiver files exist
        createIfNotExists(senderFile);
        createIfNotExists(receiverFile);

        refreshChat();
        startAutoRefresh(); // Call the auto-refresh method
    }

    private void sendMessage() {
        String message = messageField.getText();
        if (!message.isEmpty()) {
            try (PrintWriter writer = new PrintWriter(new FileWriter(senderFile, true))) {
                writer.println(message);
                writer.flush();
                messageField.setText("");
                refreshChat();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    private void refreshChat() {
        chatArea.setText("");
        try (BufferedReader reader = new BufferedReader(new FileReader(receiverFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                chatArea.append(line + "\n");
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    private void startAutoRefresh() {
        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                refreshChat();
            }
        }, 0, 1000); // Refresh every 1 second (adjust as needed)
    }

    private void createIfNotExists(File file) {
        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        String senderName = "User1";
        String receiverName = "User2";

        SwingUtilities.invokeLater(() -> {
            FileChatApp senderApp = new FileChatApp(senderName, receiverName);
            senderApp.setVisible(true);
        });

        SwingUtilities.invokeLater(() -> {
            FileChatApp receiverApp = new FileChatApp(receiverName, senderName);
            receiverApp.setVisible(true);
        });
    }
}
