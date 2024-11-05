
import java.util.Scanner;

public class SumOfASequence {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, sum;

        System.out.println("Last number?");
        n = Integer.valueOf(scanner.nextLine());

        sum = 0;

        for(int i = 1; i <= n; i++){
            sum += i;
        }

        System.out.println("The sum is " + sum);
    }
}
