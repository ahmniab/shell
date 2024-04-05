import static java.nio.file.Files.lines;


public class InitCommand {

    private void init_commands() {

        String[] lines =  git_lines();
        for (String line : lines) {
            String[] parts = line.split(" ");
            if (parts.length >= 2) {
                commands.add(new Command(parts[0], parts[1]));
            }
        }
    }
}



