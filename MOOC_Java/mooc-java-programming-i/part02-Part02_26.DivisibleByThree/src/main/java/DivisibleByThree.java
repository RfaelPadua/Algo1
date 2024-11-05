
import java.util.Scanner;

public class DivisibleByThree {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        divisibleByThreeInRange(3, 6);

    }

    public static void divisibleByThreeInRange(int comeco, int fim){
        while(comeco <= fim){
            if(comeco % 3 == 0){
                System.out.println(comeco);
            }
            comeco++;
        }
    }

}
