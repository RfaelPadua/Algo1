
import java.util.Scanner;

public class SumOfASequenceTheSequel {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, i, sum;

        System.out.println("First number?");
        i = Integer.valueOf(scanner.nextLine());

        System.out.println("Last number?");
        n = Integer.valueOf(scanner.nextLine());

        sum = 0;

        for(; i <= n; i++){
            sum += i;
        }

        System.out.println("The sum is " + sum);
    }
        

}
