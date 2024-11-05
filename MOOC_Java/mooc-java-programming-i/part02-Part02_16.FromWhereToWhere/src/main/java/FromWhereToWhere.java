
import java.util.Scanner;

public class FromWhereToWhere {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Write your program here
        int to, from;

        System.out.println("Where to?");
        to = Integer.valueOf(scanner.nextLine());

        System.out.println("Where from?");
        from = Integer.valueOf(scanner.nextLine());

        for(int i = from; i <= to; i++){
            System.out.println(i);
        }

        
    }
}
