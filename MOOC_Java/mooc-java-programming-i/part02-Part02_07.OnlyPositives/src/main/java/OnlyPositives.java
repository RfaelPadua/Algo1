
import java.util.Scanner;

public class OnlyPositives {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        
        while(true){
            int num;
            System.out.println("Give a number:");
            num = Integer.valueOf(scanner.nextLine());

            if(num < 0){
                System.out.println("Unsuitable number");
                continue;
            }else if(num == 0){
                break;
            }

            System.out.println(num * num);
            
        }
        
    }
}
