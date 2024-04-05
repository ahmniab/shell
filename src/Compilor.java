
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public abstract class Compilor {
    public static void handle_command(String cmd)
    {
        invoke_command(cmd);
    }
    private static void invoke_command(String bash){
        ProcessBuilder processBuilder = new ProcessBuilder();
        // Windows
        processBuilder.command("cmd.exe", "/c", bash);

        try {

            Process process = processBuilder.start();

            BufferedReader reader =
                    new BufferedReader(new InputStreamReader(process.getInputStream()));

            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            int exitCode = process.waitFor();
            System.out.println("\nExited with error code : " + exitCode);

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }

    }
}
