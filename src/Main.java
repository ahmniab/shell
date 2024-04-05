import java.io.IOException;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {


        System.out.println("shell");

        while (true) {
            System.out.print(dir() + "> ");
            String comnd = get_f_arg();
            Compilor.handle_command(comnd);

        }




    }
    public static String get_f_arg(){
        Scanner inp = new Scanner(System.in);
        String inp_line = inp.nextLine();
        return inp_line.split(" \n")[0];
    }
    public static String dir (){
        try {
         return new java.io.File(".").getCanonicalPath();
        }catch (IOException ex){
            return "ERROR";
        }
    }
}