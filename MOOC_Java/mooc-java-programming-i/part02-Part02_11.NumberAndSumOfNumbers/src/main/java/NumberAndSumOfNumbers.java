
import java.util.Scanner;

public class NumberAndSumOfNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, sum;
        n = 0;
        sum = 0;

        while(true){
            System.out.println("Give a number:");
            int num = Integer.valueOf(scanner.nextLine());

            if(num == 0){
                break;
            }
            
            n = n + 1;
            sum = sum + num;
        }

        System.out.println("Number of numbers: " + n);
        System.out.println("Sum of the numbers: " + sum);

    }
}
