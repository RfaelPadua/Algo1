
import java.util.Scanner;

public class GradesAndPoints {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Give poits [0-100]:");
        int pontos = Integer.valueOf(scan.nextLine());
        
        if(pontos > 100){
            System.out.println("incredible!");
        }else if (pontos >= 90){
            System.out.println("5");
        }else if(pontos >= 80){
            System.out.println("4");
        }else if(pontos >= 70){
            System.out.println("3");
        }else if (pontos >= 60){
            System.out.println("2");
        }else if(pontos >= 50){
            System.out.println("1");
        }else if(pontos >= 0){
            System.out.println("failed");
        }else{
            System.out.println("impossible!");
        }

    }
}
