public class Analyzer {
    public Analyzer()
    {
        init_commands();
    }
    final String CONF = "cmd.conf";
    private Command[] commands;
    private String[] git_lines(){

        return new String[3];
    }
    private void init_commands(){
        String[] lines =  git_lines();
        commands = new Command[lines.length];
        for (int i = 0 ; i < lines.length ; i++) {
            commands[i] = new Command(lines[i]);
        }
    }
    public String dos2bash(String dos){
        return null ;
    }

}
