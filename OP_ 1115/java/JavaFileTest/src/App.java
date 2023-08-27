import java.io.*;

public class App {
    public static void main(String[] args) throws Exception {
        FileInputStream in = null;
        FileOutputStream out = null;
        BufferedReader br = null;

        try {
            in = new FileInputStream("input.txt");
            out = new FileOutputStream("output.txt");

            br = new BufferedReader(new FileReader("input.txt"));

            String line;

            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            // int c;
            // while ((c = in.read()) != -1) {
            // System.out.println(c);
            // out.write(c);
            // }
        } finally {
            if (br != null) {
                br.close();
            }
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
        }

    }
}
