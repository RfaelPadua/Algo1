
import java.util.ArrayList;
import java.util.Scanner;

public class IndexOfSmallest {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // implement here a program that reads user input
        // until the user enters 9999
        
        // after that, the program prints the smallest number
        // and its index -- the smallest number
        // might appear multiple times
        ArrayList<Integer> numeros = new ArrayList<>();

        while(true){
            int num = Integer.valueOf(scanner.nextLine());
            if(num == 9999){
                break;
            }

            numeros.add(num);
        }
        int menorNumero = numeros.get(0);
        for(int i = 1; i < numeros.size(); i++){
            if(numeros.get(i) < menorNumero){
                menorNumero = numeros.get(i);
            }
        }

        System.out.println("Smallest number: " + menorNumero);

        for(int i = 0; i < numeros.size();i++){
            if(numeros.get(i) == menorNumero){
                System.out.println("Found at index: " + i);
            }
        }



        
    }
}
