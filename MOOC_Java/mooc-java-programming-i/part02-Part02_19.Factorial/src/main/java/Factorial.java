
import java.util.Scanner;

public class Factorial {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num1;

        System.out.println("Give a number:");
        num1 = Integer.valueOf(scanner.nextLine());

        for(int i = num1 - 1; i > 0; i--){
            num1 *= i;
        }

        System.out.println("Factorial: " + num1);
    }
}
