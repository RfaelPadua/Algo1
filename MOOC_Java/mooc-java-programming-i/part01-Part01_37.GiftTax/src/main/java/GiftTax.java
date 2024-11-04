
import java.util.Scanner;

public class GiftTax {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Value of the gift?");

        double custo = Double.valueOf(scan.nextLine());

        if(custo < 5000){
            System.out.println("No tax!");
        }else if(custo <= 25000){
            System.out.println("Tax: " + (100+(custo - 5000)*0.08));
        }else if(custo <= 55000){
            System.out.println("Tax: " + (1700+(custo - 25000)*0.10));
        }else if(custo <= 200000){
            System.out.println("Tax: " + (4700+(custo - 55000)*0.12));
        }else if(custo <= 1000000){
            System.out.println("Tax: " + (22100+(custo - 200000)*0.15));
        }else{
            System.out.println("Tax: " + (142100+(custo - 1000000)*0.17));
        }

    }
}
