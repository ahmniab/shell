import java.util.Scanner;


public class Main {
    public static void main(String[] args) {


        System.out.println("shell");

        while (true) {
            System.out.print("Enter a command> ");
            String comnd = get_f_arg();
            Compilor.handle_command(comnd);

        }




    }
    public static String get_f_arg(){
        Scanner inp = new Scanner(System.in);
        String inp_line = inp.nextLine();
        return inp_line.split(" \n")[0];
    }
}