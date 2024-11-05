
import java.util.Scanner;

public class AverageOfPositiveNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n;
        double sum;
        n = 0;
        sum = 0;

        while(true){
            System.out.println("Give a number:");
            int num = Integer.valueOf(scanner.nextLine());

            if(num == 0){
                break;
            }else if(num > 0){
                n = n + 1;
                sum = sum + num;
            }
            
        }
        if(n == 0){
            System.out.println("Cannot calculate the average");
        }else{
            System.out.println(sum / n);
        }
        

    }
}
