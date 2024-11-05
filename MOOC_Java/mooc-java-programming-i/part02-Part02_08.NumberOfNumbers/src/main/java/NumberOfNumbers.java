
import java.util.Scanner;

public class NumberOfNumbers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numerosDeNumeros = 0;

        while(true){
            System.out.println("Give a number:");
            
            int num = Integer.valueOf(scanner.nextLine());
            if(num == 0){
                break;
            }

            numerosDeNumeros = numerosDeNumeros + 1;
        }

        System.out.println("Number of numbers: " + numerosDeNumeros);
        


    }
}
